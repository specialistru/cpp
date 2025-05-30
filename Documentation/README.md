### 🔹 1. **Инкапсуляция**

В ядре принято использовать структуры (`struct`) для представления объектов, а доступ к их внутренним данным осуществляется через строго определённые функции (API), а не напрямую.

Пример:

```c
struct net_device {
    char name[IFNAMSIZ];
    void *priv;
    ...
};
```

Функции вроде `register_netdev()` и `unregister_netdev()` используются для управления этими структурами, скрывая детали реализации.

---

### 🔹 2. **Наследование (структурное)**

Это реализуется путём **встраивания одной структуры в другую**. Это позволяет "унаследовать" поля и интерфейсы.

Пример:

```c
struct device {
    ...
};

struct pci_dev {
    struct device dev; // "наследование" от device
    ...
};
```

Таким образом, `pci_dev` можно использовать там, где ожидается `device`.

---

### 🔹 3. **Полиморфизм**

Обычно реализуется через **указатели на функции** внутри структур. Это позволяет реализовать паттерн "виртуальных методов".

Пример:

```c
struct file_operations {
    ssize_t (*read)(struct file *, char __user *, size_t, loff_t *);
    ssize_t (*write)(struct file *, const char __user *, size_t, loff_t *);
    ...
};
```

Разные драйверы могут реализовать свой набор операций, присваивая свои функции в эту структуру.

---

### 🔹 4. **Паттерн "объект" + "таблица виртуальных функций"**

Это своего рода аналог **vtable** в C++. Каждая структура, реализующая поведение, имеет набор function pointers — аналог виртуальных методов.

---

### 🔹 5. **Интерфейсы и абстракции**

Многие подсистемы ядра (например, файловые системы, драйверы устройств) реализуют **общий интерфейс**, что позволяет ядру взаимодействовать с ними абстрактно, не зная конкретной реализации.

---

### Заключение:

Хотя **C не поддерживает ООП напрямую**, ядро Linux активно использует **ООП-подходы** через:

* структуры данных;
* вложенные структуры (наследование);
* указатели на функции (полиморфизм);
* строгие интерфейсы (инкапсуляция).


В ядре Linux активно применяются различные **проектные паттерны**, заимствованные из объектно-ориентированного программирования (ООП). Несмотря на то, что ядро написано на языке C, который не поддерживает ООП напрямую, разработчики используют структурированные подходы для реализации таких принципов, как инкапсуляция, полиморфизм и композиция. Ниже представлены основные паттерны с примерами из исходного кода ядра.

---

## 🧩 Основные проектные паттерны в ядре Linux

### 1. **State Container (Контейнер состояния)**

Этот паттерн используется для обеспечения многократной инициализации драйвера, где каждый вызов `probe()` создает отдельный экземпляр структуры, содержащей состояние устройства.

**Пример:**

```c
struct foo {
    spinlock_t lock;
    struct work_struct work;
    // другие поля
};

static void foo_work(struct work_struct *work)
{
    struct foo *foo = container_of(work, struct foo, work);
    // обработка
}

static int foo_probe(struct platform_device *pdev)
{
    struct foo *foo = devm_kzalloc(&pdev->dev, sizeof(*foo), GFP_KERNEL);
    if (!foo)
        return -ENOMEM;
    spin_lock_init(&foo->lock);
    INIT_WORK(&foo->work, foo_work);
    // регистрация прерывания
}
```


В этом примере `container_of()` используется для получения указателя на структуру `foo` из указателя на `work`. ([chiark.greenend.org.uk][1])

---

### 2. **Factory Method (Фабричный метод)**

Позволяет создавать объекты без указания конкретного класса, делая код более гибким и расширяемым.

**Пример:**

```c
struct device *dev = device_create(class, parent, devt, drvdata, fmt, args);
```


Здесь `device_create()` действует как фабричный метод, создавая объект устройства с заданными параметрами. ([thelinuxcode.com][2])

---

### 3. **Strategy (Стратегия)**

Позволяет изменять поведение объекта во время выполнения, предоставляя различные алгоритмы для выполнения одной задачи.

**Пример:**

```c
struct file_operations {
    ssize_t (*read)(struct file *, char __user *, size_t, loff_t *);
    ssize_t (*write)(struct file *, const char __user *, size_t, loff_t *);
    // другие операции
};
```


Здесь различные драйверы могут реализовывать свои версии операций чтения и записи, предоставляя гибкость в поведении файловых операций.&#x20;

---

### 4. **Observer (Наблюдатель)**

Механизм подписки и уведомления, где объекты могут подписываться на события и получать уведомления о их наступлении.

**Пример:**

```c
rcu_read_lock();
synchronize_rcu();
rcu_read_unlock();
```


Использование RCU (Read-Copy-Update) позволяет эффективно управлять синхронизацией при изменении данных, уведомляя подписчиков о изменениях. ([Medium][3])

---

### 5. **Flyweight (Приспособленец)**

Используется для эффективного хранения большого количества объектов, разделяя общие данные между ними.

**Пример:**

```c
struct inode_operations {
    int (*create)(struct inode *, struct dentry *, umode_t, bool);
    // другие операции
};
```


Здесь различные файловые системы могут использовать общие операции, такие как `create`, с конкретной реализацией для каждой файловой системы.&#x20;

---

### 6. **Composite (Композит)**

Позволяет объединить объекты в древовидную структуру для представления иерархий.

**Пример:**

```c
struct super_operations {
    int (*statfs)(struct dentry *, struct kstatfs *);
    // другие операции
};
```


Здесь `super_operations` представляет собой интерфейс для операций с файловой системой, который может быть реализован для различных типов файловых систем. ([lwn.net][4])

---

### 7. **Iterator (Итератор)**

Предоставляет способ последовательного доступа к элементам коллекции без раскрытия ее внутренней структуры.

**Пример:**

```c
list_for_each_entry(entry, &list_head, list) {
    // обработка entry
}
```


Использование макроса `list_for_each_entry` позволяет перебирать элементы списка, скрывая детали реализации списка.&#x20;

---

### 8. **Singleton (Одиночка)**

Обеспечивает существование только одного экземпляра объекта и предоставляет глобальную точку доступа к нему.

**Пример:**

```c
struct kmem_cache *cache;
cache = kmem_cache_create("my_cache", size, align, flags, ctor);
```


Здесь `kmem_cache_create()` создает кэш памяти, обеспечивая централизованное управление выделением памяти.&#x20;

---

### 9. **Builder (Строитель)**

Позволяет поэтапно создавать сложные объекты, скрывая детали их создания.

**Пример:**

```c
struct proc_dir_entry *entry;
entry = proc_create("my_entry", mode, parent, &proc_fops);
```


Здесь `proc_create()` создает запись в виртуальной файловой системе `/proc`, предоставляя интерфейс для взаимодействия с процессами. ([thelinuxcode.com][2])

https://www.chiark.greenend.org.uk/doc/linux-doc/html/driver-api/driver-model/design-patterns.html?utm_source=chatgpt.com "Device Driver Design Patterns — The Linux Kernel documentation"

https://thelinuxcode.com/design-patterns-cpp/?utm_source=chatgpt.com "Demystifying Design Patterns: A Guide for Linux Developers – TheLinuxCode"

https://arunk2.medium.com/design-patterns-in-os-kernel-d3f7e2f3f3bf?utm_source=chatgpt.com "Design Patterns in OS Kernel. Most of us know about design patterns… | by Arunkumar Krishnan | Medium"

https://lwn.net/Articles/444910/?utm_source=chatgpt.com "Object-oriented design patterns in the kernel, part 1 [LWN.net]"



