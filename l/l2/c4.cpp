#include <iostream>
#include <vector>
#include <string>

// Функція для кодування вхідного рядка
std::vector<unsigned char> encode(const std::vector<unsigned char>& input_data) {
    if (input_data.size() % 8 != 0) {
        std::cerr << "Помилка: довжина вхідної послідовності не кратна 8." << std::endl;
        return {};
    }

    std::vector<unsigned char> encoded_data;

    // Обробка блоків по 8 байтів
    for (size_t i = 0; i < input_data.size(); i += 8) {
        // Створення 8 нових закодованих байтів
        unsigned char new_bytes[8] = {0};

        // Перегрупування бітів
        for (int j = 0; j < 8; ++j) { // Ітерація по вхідних байтах (0-7)
            unsigned char current_byte = input_data[i + j];
            for (int k = 0; k < 8; ++k) { // Ітерація по бітах вхідного байта (0-7)
                // Виділення біта з поточного байта (k-й біт)
                unsigned char bit = (current_byte >> (7 - k)) & 1;

                // Вставка біта в новий байт (j-й біт в k-й байт)
                new_bytes[k] |= (bit << (7 - j));
            }
        }

        // Додавання нових байтів до результату
        for (int j = 0; j < 8; ++j) {
            encoded_data.push_back(new_bytes[j]);
        }
    }

    return encoded_data;
}

// Допоміжна функція для виводу байтів у двійковому форматі
void print_as_binary(const std::vector<unsigned char>& data) {
    for (unsigned char byte : data) {
        for (int i = 7; i >= 0; --i) {
            std::cout << ((byte >> i) & 1);
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Вхідні дані (8 байтів)
    // Наприклад: 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'
    std::vector<unsigned char> input_data = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}; 

    std::cout << "Оригінальні дані (як символи): ";
    for (char c : input_data) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    std::cout << "Оригінальні дані (в двійковому форматі):" << std::endl;
    print_as_binary(input_data);

    // Кодування даних
    std::vector<unsigned char> encoded_data = encode(input_data);

    std::cout << "\nЗакодовані дані (в двійковому форматі):" << std::endl;
    print_as_binary(encoded_data);

    return 0;
}