# Курс программирование на С++
- Тема 1: Типы данных, операции и функции в С++. Инкапсуляция.
- Тема 2: Специальные методы класса. Константные и статические члены класса.
- Тема 3: Перегрузка операций. Потоки данных в С++.
- Тема 4: Наследование и полиморфизм. Шаблоны функций и классов.
- Тема 5: Управление исключениями.

# Дополнительные материалы
- IDE Dev-C++ Files​ 5.11​ https://sourceforge.net/projects/orwelldevcpp/files/latest/download
- GCC 15.1 https://github.com/skeeto/w64devkit/releases
- Справочник по языку С++​ ​ https://en.cppreference.com/w/
- Стандарты C и стандарты C++​ https://gcc.gnu.org/projects/cxx-status.html
- GCC Releases​ https://gcc.gnu.org/releases.html
- Build status for GCC​ https://gcc.gnu.org/buildstat.html


PowerShell-скрипт, который перекодирует все .h и .cpp файлы в UTF-8

```bash

Get-ChildItem -Filter *.txt | ForEach-Object {
    $content = Get-Content $_.FullName -Encoding Default
    Set-Content $_.FullName -Value $content -Encoding UTF8
}

```
