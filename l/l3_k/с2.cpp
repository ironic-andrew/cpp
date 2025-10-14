#include <iostream>
#include <vector>
#include <algorithm> // для sort
using namespace std;

class BoolMatrix {
private:
    int n, m;
    vector<vector<bool>> data;

public:
    // 1️⃣ Конструктор за замовчуванням
    BoolMatrix() : n(0), m(0) {}

    // 2️⃣ Конструктор з параметрами
    BoolMatrix(int rows, int cols) : n(rows), m(cols) {
        data.assign(n, vector<bool>(m, false)); // ініціалізує нулями
    }

    // 3️⃣ Конструктор копіювання
    BoolMatrix(const BoolMatrix &B) {
        n = B.n;
        m = B.m;
        data = B.data;
    }

    // 🔹 Метод для заповнення вручну
    void set(int i, int j, bool value) {
        if (i >= 0 && i < n && j >= 0 && j < m)
            data[i][j] = value;
    }

    // 🔹 Вивід
    void print() const {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }

    // 4️⃣ Диз’юнкція (логічне "або")
    BoolMatrix operator|(const BoolMatrix &B) const {
        BoolMatrix result(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                result.data[i][j] = data[i][j] || B.data[i][j];
        return result;
    }

    // 5️⃣ Кон’юнкція (логічне "і")
    BoolMatrix operator&(const BoolMatrix &B) const {
        BoolMatrix result(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                result.data[i][j] = data[i][j] && B.data[i][j];
        return result;
    }

    // 6️⃣ Інверсія (логічне "не")
    BoolMatrix operator~() const {
        BoolMatrix result(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                result.data[i][j] = !data[i][j];
        return result;
    }

    // 7️⃣ Присвоєння
    BoolMatrix& operator=(const BoolMatrix &B) {
        if (this != &B) {
            n = B.n;
            m = B.m;
            data = B.data;
        }
        return *this;
    }

    // 8️⃣ Підрахунок кількості одиниць
    int countOnes() const {
        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (data[i][j]) count++;
        return count;
    }

    // 9️⃣ Лексикографічне сортування рядків
    void sortLexicographically() {
        sort(data.begin(), data.end());
    }
};

// 🔹 Функція, яка змінює матрицю за формулою A = A ∨ B
void updateMatrix(BoolMatrix &A, const BoolMatrix &B) {
    A = A | B;
}

int main() {
    // 1️⃣ Створення матриць різними конструкторами
    BoolMatrix A(3, 3);       // конструктор з параметрами
    BoolMatrix B(3, 3);
    BoolMatrix C;             // конструктор за замовчуванням

    // 2️⃣ Заповнення матриць
    A.set(0,0,1); A.set(1,1,1); A.set(2,2,1);
    B.set(0,1,1); B.set(1,2,1); B.set(2,0,1);

    cout << "Матриця A:\n"; A.print();
    cout << "Матриця B:\n"; B.print();

    // 3️⃣ Перевірка диз’юнкції (логічне “або”)
    C = A | B;
    cout << "A ∨ B (A | B):\n"; C.print();

    // 4️⃣ Перевірка кон’юнкції (логічне “і”)
    C = A & B;
    cout << "A ∧ B (A & B):\n"; C.print();

    // 5️⃣ Інверсія
    C = ~A;
    cout << "Інверсія матриці A (~A):\n"; C.print();

    // 6️⃣ Присвоєння
    C = B;
    cout << "C після присвоєння C = B:\n"; C.print();

    // 7️⃣ Підрахунок одиниць
    cout << "Кількість одиниць у матриці A: " << A.countOnes() << endl;

    // 8️⃣ Лексикографічне сортування
    cout << "\nB до сортування:\n"; B.print();
    B.sortLexicographically();
    cout << "B після лексикографічного сортування:\n"; B.print();

    // 9️⃣ Формула A = A ∨ B
    cout << "A перед A = A ∨ B:\n"; A.print();
    updateMatrix(A, B);
    cout << "A після A = A ∨ B:\n"; A.print();

    return 0;
}
