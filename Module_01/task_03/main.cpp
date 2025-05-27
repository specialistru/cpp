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
        delete[] array;  // ����������� ������ ������
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
    std::cout << "������������ ������ �� ����� ���������������� �� C++. ������ 1.3.\n\n";

    try {
        // 1. �������� � ������������� �������
        size_t size = 5;
        int* my_array = create_array(size);
        
        std::cout << "1. ������ ������ [" << size << "]: ";
        for (size_t i = 0; i < size; ++i) {
            my_array[i] = static_cast<int>(i + 1) * 10;  // [10, 20, 30, 40, 50]
        }
        print_array(my_array, size);
        std::cout << "\n";

        // 2. ���������� �������
        size_t new_size = 8;
        my_array = resize_array(my_array, size, new_size);
        
        std::cout << "2. �������� �� [" << new_size << "]: ";
        print_array(my_array, new_size);
        std::cout << "\n";

        // 3. ���������� �������
        size_t smaller_size = 3;
        my_array = resize_array(my_array, new_size, smaller_size);
        
        std::cout << "3. �������� �� [" << smaller_size << "]: ";
        print_array(my_array, smaller_size);
        std::cout << "\n";

        // 4. �������� �������
        delete_array(my_array);
        std::cout << "4. ������ ������\n";

        // 5. ������� �������� ������� �������� �������
        std::cout << "5. �������� [0]: ";
        int* empty_array = create_array(0);
        std::cout << (empty_array == nullptr ? "�����: nullptr" : "������") << "\n";
        delete_array(empty_array);

    } catch (const std::exception& e) {
        std::cerr << "������: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
