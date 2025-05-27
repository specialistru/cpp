#include <iostream>
#include <algorithm>

int* create_array(size_t size) {
    return (size == 0) ? nullptr : new int[size]();
}

int* resize_array(int* array, size_t old_size, size_t new_size) {
    if (new_size == 0) {
        delete[] array;
        return nullptr;
    }

    int* new_array = new int[new_size]();
    
    if (array != nullptr) {
        std::copy_n(array, std::min(old_size, new_size), new_array);
        delete[] array;  // Освобождаем старую память
    }

    return new_array;
}

void delete_array(int* array) {
    delete[] array;
}

void print_array(const int* array, size_t size) {
    if (array == nullptr) {
        std::cout << "nullptr";
        return;
    }

    std::cout << "[";
    for (size_t i = 0; i < size; ++i) {
        std::cout << array[i];
        if (i < size - 1) std::cout << ", ";
    }
    std::cout << "]";
}

int main() {
    system("chcp 1251 > nul");
    std::cout << "Лабораторная работа по курсу программирования на C++. Задача 1.3.\n\n";

    try {
        // 1. Создание и инициализация массива
        size_t size = 5;
        int* my_array = create_array(size);
        
        std::cout << "1. Создан массив [" << size << "]: ";
        for (size_t i = 0; i < size; ++i) {
            my_array[i] = static_cast<int>(i + 1) * 10;  // [10, 20, 30, 40, 50]
        }
        print_array(my_array, size);
        std::cout << "\n";

        // 2. Увеличение массива
        size_t new_size = 8;
        my_array = resize_array(my_array, size, new_size);
        
        std::cout << "2. Увеличен до [" << new_size << "]: ";
        print_array(my_array, new_size);
        std::cout << "\n";

        // 3. Уменьшение массива
        size_t smaller_size = 3;
        my_array = resize_array(my_array, new_size, smaller_size);
        
        std::cout << "3. Уменьшен до [" << smaller_size << "]: ";
        print_array(my_array, smaller_size);
        std::cout << "\n";

        // 4. Удаление массива
        delete_array(my_array);
        std::cout << "4. Массив удален\n";

        // 5. Попытка создания массива нулевого размера
        std::cout << "5. Создание [0]: ";
        int* empty_array = create_array(0);
        std::cout << (empty_array == nullptr ? "Успех: nullptr" : "Ошибка") << "\n";
        delete_array(empty_array);

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
