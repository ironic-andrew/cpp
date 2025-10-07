#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


int calculate_parity(int value, int num_bits) {
    int parity = 0;
    for (int i = 0; i < num_bits; ++i) {
        parity ^= ((value >> i) & 1);
    }
    return parity;
}

// Структура для опису бітових полів зашифрованого символу
struct EncryptedCharFields {
    unsigned int row_num    : 4; // біти 0-3
    unsigned int ascii_high : 4; // біти 4-7
    unsigned int parity1    : 1; // біт 8
    unsigned int ascii_low  : 4; // біти 9-12
    unsigned int col_num    : 2; // біти 13-14
    unsigned int parity2    : 1; // біт 15
};



union EncryptedData {
    unsigned short value;
    struct EncryptedCharFields fields;
};


unsigned short encrypt_char(char c, int row_num, int col_num) {
    EncryptedData data;

   
    data.fields.row_num = row_num;
    data.fields.ascii_high = (static_cast<int>(c) >> 4) & 0x0F;
    data.fields.ascii_low = static_cast<int>(c) & 0x0F;
    data.fields.col_num = col_num;

    int parity1_value = data.fields.row_num | (data.fields.ascii_high << 4);
    data.fields.parity1 = calculate_parity(parity1_value, 8);

   
    int parity2_value = data.fields.ascii_low | (data.fields.col_num << 4);
    data.fields.parity2 = calculate_parity(parity2_value, 6);

    return data.value;
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