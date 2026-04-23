#include<iostream>
using namespace std;

class MultiSet {

private:
    unsigned* s;
    unsigned int beg, end, size;

public:
    // Вивід інформації про об'єкт
    void info(const string& title) const {
        cout << "\n[" << title << "]"
             << "\n beg = " << beg
             << " | end = " << end
             << " | size = " << size
             << "\n Перші елементи масиву: ";
        for (unsigned int i = 0; i < (size < 5 ? size : 5); ++i)
            cout << s[i] << " ";
        cout << "\n";
    }

    // Без параметрів
    MultiSet() {
        beg = 0;
        end = 100;
        size = end - beg;
        s = new unsigned[size]{0};
        info("Конструктор без параметрів");
    }

    // З параметром end
    MultiSet(unsigned int end) {
        beg = 0;

        if (end <= beg) {
            cout << "Помилка: end має бути > beg!";
            end = beg + 1;
        }

        this->end = end;
        size = end - beg;
        s = new unsigned[size]{0};
        info("Конструктор з одним параметром end");
    }

    // З параметрами beg, end
    MultiSet(unsigned int beg, unsigned int end) {
        this->beg = beg;
        this->end = end;
        size = end - beg;
        s = new unsigned[size]{0};
        info("Конструктор з двома параметрами beg, end");
    }

    // З параметрами beg, end, value
    MultiSet(unsigned int beg, unsigned int end, unsigned int value) {
        this->beg = beg;
        this->end = end;
        size = end - beg;
        s = new unsigned[size]{value};
        info("Конструктор з трьома параметрами beg, end, value");
    }

    // Конструктор копіювання
    MultiSet(const MultiSet& other) {
        beg = other.beg;
        end = other.end;
        size = other.size;

        s = new unsigned[size];
        for (unsigned int i = 0; i < size; ++i)
            s[i] = other.s[i];

        info("Конструктор копіювання");
    }

    // Оператор присвоєння
    MultiSet& operator=(const MultiSet& other) {
        if (this == &other)
            return *this;

        delete[] s;

        beg = other.beg;
        end = other.end;
        size = other.size;

        s = new unsigned[size];
        for (unsigned int i = 0; i < size; ++i)
            s[i] = other.s[i];

        info("Оператор присвоєння");
        return *this;
    }

    
    // Вивід усіх елементів і кількості повторень
    void show() const {
        cout << "\nЕлементи множини [" << beg << ", " << end << "):\n";
        for (unsigned int i = 0; i < size; ++i) {
            unsigned int element = beg + i;
            cout << "Елемент: " << element
                 << " | Кількість повторень: " << s[i] << "\n";
        }
    }
    

    
    // Додавання елемента
    void add(int number) {
        if (number < beg || number >= end) {
            cout << "\nЧисло " << number << " поза діапазоном [" << beg << ", " << end << ")\n";
            return;
        }

        unsigned int index = number - beg;
        s[index]++;
        cout << "\nДодано число " << number << "\n";
    }
    

    // Деструктор
    ~MultiSet() {
        delete[] s;
        cout << "\nДеструктор викликано для [" << beg << ", " << end << ")\n";
    }
};

int main() {
    cout << "\n--- 1. Конструктор без параметрів ---";
    MultiSet s1;

    cout << "\n--- 2. Конструктор з одним параметром end ---";
    MultiSet s2(50);

    cout << "\n--- 3. Конструктор з двома параметрами beg, end ---";
    MultiSet s3(10, 20);

    cout << "\n--- 4. Конструктор з трьома параметрами beg, end, value ---";
    MultiSet s4(5, 15, 3);

    cout << "\n--- 5. Конструктор копіювання ---";
    MultiSet s5 = s4;

    cout << "\n--- 6. Оператор присвоєння ---";
    s3 = s2;

    cout << "\n--- 7. Додавання елементів у s4 ---";
    s4.add(7);
    s4.add(10);
    s4.add(7);
    s4.show();

    cout << "\n--- Кінець програми ---\n";
    return 0;
}
