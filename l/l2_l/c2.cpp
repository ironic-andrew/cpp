#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

// Функція для обчислення біта парності за допомогою XOR
int calculate_parity(int value, int num_bits) {
    int parity = 0;
    for (int i = 0; i < num_bits; ++i) {
        parity ^= ((value >> i) & 1);
    }
    return parity;
}

// Функція шифрування символу в 16-бітну структуру
unsigned short encrypt_char(char c, int row_num, int col_num) {
    unsigned short encrypted_value = 0;
    int ascii_code = static_cast<int>(c);

    // Розділяємо ASCII-код на старшу і молодшу частини (по 4 біти)
    int ascii_high = (ascii_code >> 4) & 0x0F;
    int ascii_low = ascii_code & 0x0F;

    // Запис номера рядка (біти 0-3)
    encrypted_value |= (row_num & 0x0F);

    // Запис старшої частини ASCII (біти 4-7)
    encrypted_value |= (ascii_high & 0x0F) << 4;

    // Обчислення та запис першого біта парності (біт 8)
    int parity1_value = (row_num & 0x0F) | ((ascii_high & 0x0F) << 4);
    int parity1_bit = calculate_parity(parity1_value, 8);
    encrypted_value |= (parity1_bit & 1) << 8;

    // Запис молодшої частини ASCII (біти 9-12)
    encrypted_value |= (ascii_low & 0x0F) << 9;

    // 5. Запис позиції символу в рядку (біти 13-14)
   
    encrypted_value |= (col_num & 0x03) << 13;

    // 6. Обчислення та запис другого біта парності (біт 15)
    int parity2_value = ((ascii_low & 0x0F)) | ((col_num & 0x03) << 4);
    int parity2_bit = calculate_parity(parity2_value, 6);
    encrypted_value |= (parity2_bit & 1) << 15;

    return encrypted_value;
}

int main() {
    const int NUM_LINES = 16;
    const int LINE_LENGTH = 16;
    const int INPUT_LENGTH = 4;

    std::vector<std::string> text_data(NUM_LINES);

    std::cout << "Введіть " << NUM_LINES << " рядків (до " << INPUT_LENGTH << " символів кожен):\n";
    for (int i = 0; i < NUM_LINES; ++i) {
        std::cout << "Рядок " << i + 1 << ": ";
        std::getline(std::cin, text_data[i]);
    }

    // Доповнюємо рядки пробілами до 16 символів
    for (size_t i = 0; i < text_data.size(); ++i) {
        if (text_data[i].length() < LINE_LENGTH) {
            text_data[i].resize(LINE_LENGTH, ' ');
        }
    }

    std::cout << "\nЗашифрований текст (у шістнадцятковому форматі):\n";
    for (int i = 0; i < NUM_LINES; ++i) {
        for (int j = 0; j < LINE_LENGTH; ++j) {
            unsigned short encrypted_char = encrypt_char(text_data[i][j], i, j);
            std::cout << std::hex << std::setw(4) << std::setfill('0') << encrypted_char << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}