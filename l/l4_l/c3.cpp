#include<iostream>
#include<vector>
#include <cmath>
using namespace std;


class matrixFload{
private:

int r,c;
vector<vector<double>> s;


public:
bool codeError = false;

    matrixFload(){

        r = 4;
        c = 4;
        s = vector<vector<double>>(r, vector<double>(c));
        codeError = false;

    };

    matrixFload(int r1){

        r = r1;
        c = 4;
        s = vector<vector<double>>(r, vector<double>(c));
        codeError = false;

    };

    matrixFload(int r1, int c1, int value){

        r = r1;
        c = c1;
        s = vector<vector<double>>(r, vector<double>(c, value));
        codeError = false;

    };

    matrixFload(const matrixFload& other){

        r = other.r;
        c = other.c;
        codeError = other.codeError;
        s = other.s;

    };

    ~matrixFload(){



    };

        matrixFload operator+(const matrixFload& other){

            if(r != other.r or c != other.c){

                codeError = true;
                return *this;

            }

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] = s[i][j] + other.s[i][j];

                }
            }

            return *this;

        };

        matrixFload operator+(int value){

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] = s[i][j] + value;

                }
            }

            return *this;

        };

        matrixFload operator+(float value){

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] = s[i][j] + value;

                }
            }

            return *this;

        };

        matrixFload operator-(const matrixFload& other){

            if(r != other.r or c != other.c){

                codeError = true;
                return *this;

            }

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] = s[i][j] - other.s[i][j];

                }
            }

            return *this;

        };

        matrixFload operator-(int value){

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] = s[i][j] - value;

                }
            }

            return *this;

        };

        matrixFload operator-(float value){

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] = s[i][j] - value;

                }
            }

            return *this;

        };

        matrixFload operator-(double value){

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] = s[i][j] - value;

                }
            }

            return *this;

        };

        matrixFload operator*(const matrixFload& other){

            if(r != other.r or c != other.c){

                codeError = true;
                return *this;

            }

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] = s[i][j] * other.s[i][j];

                }
            }

            return *this;

        };

        matrixFload operator*(float value){

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] = s[i][j] * value;

                }
            }

            return *this;

        };

        matrixFload operator*(double value){

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] = s[i][j] * value;

                }
            }

            return *this;

        };

        matrixFload operator/(int value){

            if(value == 0){

                codeError = true;
                return *this;

            }

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] = s[i][j] / value;

                }
            }

            return *this;

        };

        matrixFload operator/(float value){

            if(value == 0){

                codeError = true;
                return *this;

            }

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] = s[i][j] / value;

                }
            }

            return *this;

        };

        matrixFload operator/(double value){

            if(value == 0){

                codeError = true;
                return *this;

            }

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] = s[i][j] / value;

                }
            }

            return *this;

        };

        matrixFload operator%(int value){

            if(value == 0){

                codeError = true;
                return *this;

            }

            matrixFload temp = *this;

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    temp.s[i][j] = fmod(s[i][j], static_cast<double>(value));

                }
            }

            return temp;

        };

        matrixFload operator+=(const matrixFload& other){

            if(r != other.r or c != other.c){

                codeError = true;
                return *this;

            }

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] += other.s[i][j];

                }
            }

            return *this;

        };

        matrixFload operator+=(float value){

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] += value;

                }
            }

            return *this;

        };

        matrixFload operator+=(double value){

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] += value;

                }
            }

            return *this;

        };

        matrixFload operator-=(const matrixFload& other){

            if(r != other.r or c != other.c){

                codeError = true;
                return *this;

            }

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] -= other.s[i][j];

                }
            }

            return *this;

        };

        matrixFload operator-=(float value){

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] -= value;

                }
            }

            return *this;

        };

        matrixFload operator-=(double value){

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] -= value;

                }
            }

            return *this;

        };

        matrixFload operator*=(const matrixFload& other){

            if(r != other.r or c != other.c){

                codeError = true;
                return *this;

            }

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] *= other.s[i][j];

                }
            }

            return *this;

        };

        matrixFload operator*=(float value){

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] *= value;

                }
            }

            return *this;

        };

        matrixFload operator*=(double value){

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] *= value;

                }
            }

            return *this;

        };

        matrixFload operator/=(const matrixFload& other){

            if(r != other.r or c != other.c){

                codeError = true;
                return *this;

            }

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] -= other.s[i][j];

                }
            }

            return *this;

        };

        matrixFload operator/=(float value){

            if(value == 0){

                codeError = true;
                return *this;

            }

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] -= value;

                }
            }

            return *this;

        };

        matrixFload operator/=(double value){

            if(value == 0){

                codeError = true;
                return *this;

            }

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    s[i][j] -= value;

                }
            }

            return *this;

        };

        bool operator==(const matrixFload& other) const{

            return (s == other.s);

        };

        bool operator!=(const matrixFload& other) const{

            return (s != other.s);

        };

        bool operator>(const matrixFload& other){

            if(r != other.r and c != other.c){

                codeError = true;
                return false;

            }

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    if(s[i][j] <= other.s[i][j]) return false;

                }
            }
            
            return true;

        };

        bool operator>=(const matrixFload& other){

            if(r != other.r and c != other.c){

                codeError = true;
                return false;

            }

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    if(s[i][j] < other.s[i][j]) return false;

                }
            }
            
            return true;

        };

        bool operator<(const matrixFload& other){

            if(r != other.r and c != other.c){

                codeError = true;
                return false;

            }

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    if(s[i][j] >= other.s[i][j]) return false;

                }
            }
            
            return true;

        };

        bool operator<=(const matrixFload& other){

            if(r != other.r and c != other.c){

                codeError = true;
                return false;

            }

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    if(s[i][j] > other.s[i][j]) return false;

                }
            }
            
            return true;

        };

        void* operator new[](size_t size){
            cout << "Створений об'єкт, виділено " << size << " місця\n";
            void* s1 = malloc(size); 
            if (!s1) throw bad_alloc();
            return s1;

        };

        void operator delete[](void* s1) noexcept {
            cout << "[delete[]] Звільнення пам’яті\n";
            free(s1);

        };

        matrixFload operator()(int r1, int c1, double value){

            matrixFload temp;
            temp.r = r1;
            temp.c = c1;
            temp.s = vector<vector<double>>(temp.r, vector<double>(temp.c, value));
            temp.codeError = false;
            return temp;

        };

        matrixFload operator>>(int value){

            matrixFload temp;
            temp.r = r;
            temp.c = c;
            temp.s = std::vector<std::vector<double>>(r, std::vector<double>(c, 0));
            temp.codeError = codeError;

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    int s1 = s[i][j] = static_cast<int>(s[i][j]);
                    s1 >> value;
                    temp.s[i][j] = static_cast<double>(s1);

                }
            }

            return temp;

        };

        matrixFload operator<<(int value){

            matrixFload temp;
            temp.r = r;
            temp.c = c;
            temp.s = std::vector<std::vector<double>>(r, std::vector<double>(c, 0));
            temp.codeError = codeError;

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){

                    int s1 = s[i][j] = static_cast<int>(s[i][j]);
                    s1 << value;
                    temp.s[i][j] = static_cast<double>(s1);

                }
            }

            return temp;

        };


    void show(){

        int index = 1;
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){

                cout << index << ": " << s[i][j] << "\n";
                index++;
            }
        }

        cout << "codeError - " << codeError << "\n";


    };

    void showError(){

        cout << "codeError - " << codeError << "\n";

    };

};




int main(){
    matrixFload t;

    cout << "--- 1. Констуктор за замавчуванням ---\n";
    matrixFload t1{};
    t1.show();

    cout << "\n--- 2. Констуктор з параметром r ---\n";
    matrixFload t2(3);
    t2.show();

    cout << "\n--- 3. Констуктор з параметром r,c,value ---\n";
    matrixFload t3(2,2,4);
    t3.show();

    cout << "\n--- 4. Констуктор копіювання ---\n";
    cout << "Оригінал\n";
    t2.show();
    t3 = t2;
    cout << "Копія\n";
    t3.show();

    cout << "\n--- 4. Оператор додаваня двох матриць ---\n";
    cout << "Перша матриця\n";
    matrixFload t4(2,2,4);
    t4.show();

    cout << "Друга матриця\n";
    matrixFload t5(2,2,5);
    t5.show();

    cout << "Сума матриць\n";
    t1 = t5 + t4;
    t1.show();


    cout << "\n--- 5. Оператор додаваня до значення int value ---\n";
    cout << "Число " << 2 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця після додавання\n";
    t3 = t3 + (int)2;
    t3.show();

    cout << "\n--- 6. Оператор додаваня до значення float value ---\n";
    cout << "Число " << 2.5 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця після додавання\n";
    t3 = t3 + 2.5f;
    t3.show();


    cout << "\n--- 7. Оператор віднімання двох матриць ---\n";
    cout << "Перша матриця\n";
    t4.show();

    cout << "Друга матриця\n";
    t5.show();

    cout << "Різниця матриць\n";
    t1 = t5 - t4;
    t1.show();


    cout << "\n--- 8. Оператор віднімання до значення int value ---\n";
    cout << "Число " << 2 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця після віднімання\n";
    t3 = t3 - (int)2;
    t3.show();

    cout << "\n--- 9. Оператор віднімання до значення float value ---\n";
    cout << "Число " << 2.5 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця після віднімання\n";
    t3 = t3 - 2.5f;
    t3.show();

    cout << "\n--- 10. Оператор віднімання до значення double value ---\n";
    cout << "Число " << 2.5 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця після віднімання\n";
    t3 = t3 - 2.5;
    t3.show();


    cout << "\n--- 11. Оператор множення двох матриць ---\n";
    cout << "Перша матриця\n";
    t4.show();

    cout << "Друга матриця\n";
    t5.show();

    cout << "Добуток матриць\n";
    t1 = t5 * t4;
    t1.show();


    cout << "\n--- 12. Оператор множення до значення float value ---\n";
    cout << "Число " << 3.5 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця після множення\n";
    t3 = t3 * 3.5f;
    t3.show();

    cout << "\n--- 13. Оператор множення до значення double value ---\n";
    cout << "Число " << 2.5 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця після множення\n";
    t3 = t3 * 2.5;
    t3.show();


    cout << "\n--- 14. Оператор ділення на значення int value ---\n";
    cout << "Число " << 2 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця після ділення\n";
    t3 = t3 / (int)2;
    t3.show();

    cout << "\n--- 15. Оператор ділення на значення float value ---\n";
    cout << "Число " << 3.5 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця після ділення\n";
    t3 = t3 / 3.5f;
    t3.show();

    cout << "\n--- 16. Оператор ділення на значення double value ---\n";
    cout << "Число " << 2.5 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця після ділення\n";
    t3 = t3 / 2.5;
    t3.show();


    cout << "\n--- 17. Оператор ділення з остачею на значення int value ---\n";
    cout << "Число " << 2 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця після ділення\n";
    t3 = t3 / (int)2;
    t3.show();


    cout << "\n--- 18. Оператор присвоєного додавання двох матриць ---\n";
    cout << "Перша матриця\n";
    t4.show();

    cout << "Друга матриця\n";
    t5.show();

    cout << "Cума матриць\n";
    t5 += t4;
    t5.show();


    cout << "\n--- 19. Оператор присвоєного додавання до значення float value ---\n";
    cout << "Число " << 3.5 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця після присвоєного додавання\n";
    t3 += 3.5f;
    t3.show();

    cout << "\n--- 20. Оператор присвоєного додавання до значення double value ---\n";
    cout << "Число " << 2.5 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця після присвоєного додавання\n";
    t3 += 2.5;
    t3.show();


    cout << "\n--- 21. Оператор присвоєного віднімання двох матриць ---\n";
    cout << "Перша матриця\n";
    t4.show();

    cout << "Друга матриця\n";
    t5.show();

    cout << "Різниця матриць\n";
    t5 -= t4;
    t5.show();


    cout << "\n--- 22. Оператор присвоєного віднімання до значення float value ---\n";
    cout << "Число " << 3.5 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця після присвоєного віднімання\n";
    t3 -= 3.5f;
    t3.show();

    cout << "\n--- 23. Оператор присвоєного віднімання до значення double value ---\n";
    cout << "Число " << 2.5 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця після присвоєного віднімання\n";
    t3 -= 2.5;
    t3.show();


    cout << "\n--- 24. Оператор присвоєного множення двох матриць ---\n";
    cout << "Перша матриця\n";
    t4.show();

    cout << "Друга матриця\n";
    t5.show();

    cout << "Добуток матриць\n";
    t5 *= t4;
    t5.show();


    cout << "\n--- 25. Оператор присвоєного множення до значення float value ---\n";
    cout << "Число " << 3.5 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця після присвоєного множення\n";
    t3 *= 3.5f;
    t3.show();

    cout << "\n--- 26. Оператор присвоєного множення до значення double value ---\n";
    cout << "Число " << 2.5 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця після присвоєного множення\n";
    t3 *= 2.5;
    t3.show();


    cout << "\n--- 27. Оператор присвоєного ділення двох матриць ---\n";
    cout << "Перша матриця\n";
    t4.show();

    cout << "Друга матриця\n";
    t5.show();

    cout << "Частка матриць\n";
    t5 /= t4;
    t5.show();


    cout << "\n--- 28. Оператор присвоєного ділення до значення float value ---\n";
    cout << "Число " << 3.5 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця після присвоєного ділення\n";
    t3 /= 3.5f;
    t3.show();

    cout << "\n--- 29. Оператор присвоєного ділення до значення double value ---\n";
    cout << "Число " << 2.5 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця після присвоєного ділення\n";
    t3 /= 2.5;
    t3.show();


    cout << "\n--- 30. Оператор == двох матриць ---\n";
    cout << "Перша матриця\n";
    t4.show();

    cout << "Друга матриця\n";
    t5.show();

    if(t4 == t5) cout << "Матриці рівні\n";
    else cout << "Матриці нерівні\n";


    cout << "\n--- 31. Оператор != двох матриць ---\n";
    cout << "Перша матриця\n";
    t4.show();

    cout << "Друга матриця\n";
    t5.show();

    if(t4 != t5) cout << "Матриці нерівні\n";
    else cout << "Матриці рівні\n";


    cout << "\n--- 32. Оператор > двох матриць ---\n";
    cout << "Перша матриця\n";
    t4.show();

    cout << "Друга матриця\n";
    t5.show();

    if(t4 > t5) cout << "Перша матриця більша\n";
    else cout << "Друга матриця більша рівна\n";
    t.showError();


    cout << "\n--- 33. Оператор >= двох матриць ---\n";
    cout << "Перша матриця\n";
    t4.show();

    cout << "Друга матриця\n";
    t5.show();

    if(t4 >= t5) cout << "Перша матриця більша рівна\n";
    else cout << "Друга матриця більша\n";
    t.showError();


    cout << "\n--- 34. Оператор < двох матриць ---\n";
    cout << "Перша матриця\n";
    t4.show();

    cout << "Друга матриця\n";
    t5.show();

    if(t4 < t5) cout << "Перша матриця менша\n";
    else cout << "Друга матриця менша рівна\n";
    t.showError();


    cout << "\n--- 35. Оператор <= двох матриць ---\n";
    cout << "Перша матриця\n";
    t4.show();

    cout << "Друга матриця\n";
    t5.show();

    if(t4 <= t5) cout << "Перша матриця менша рівна\n";
    else cout << "Друга матриця менша\n";
    t.showError();

    cout << "\n--- 36. Оператор new[] двох матриць ---\n";
    matrixFload* s1 = new matrixFload[2];


    cout << "\n--- 37. Оператор delete[] двох матриць ---\n";
    delete [] s1;


    cout << "\n--- 38. Оператор () двох матриць ---\n";
    matrixFload t6 = matrixFload()(2, 2, 6);
    t6.show();

    cout << "\n--- 39. Оператор >> int value ---\n";
    cout << "Число " << 5 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця зсуву\n";
    t3 = t3 >> 5;
    t3.show();


    cout << "\n--- 40. Оператор << int value ---\n";
    cout << "Число " << 5 <<"\n";
    cout << "матриця\n";
    t3.show();
    cout << "Матриця зсуву\n";
    t3 = t3 << 5;
    t3.show();


    return 0;
}