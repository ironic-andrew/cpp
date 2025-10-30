#include<iostream>
#include<vector>
#include <cstdlib>
#include <ctime>
using namespace std;


class matrix{

private:

    int n;
    int m;
    vector<vector<float>> s;







public:
//vector<vector<float>> s(n, vector<float>(m));

    matrix(){

        n = 2;
        m = 2;
        s = vector<vector<float>>(n, vector<float>(m, 0));

    }

    matrix(int r){

        n = r;
        m = 2;
        s = vector<vector<float>>(n, vector<float>(m, 0));

    }

    matrix(int r, int c, int value){

        n = r;
        m = c;
        int index = 0;
        s = vector<vector<float>>(n, vector<float>(m));
        for (int i = 0;i < n; ++i){
            for (int j = 0;j < m; ++j){

                if (index == 3){
                s[i][j] = value;
                
                }else{

                    s[i][j] = 0;

                }
                index++;
            
            }
        }

    }

    matrix(const matrix& other){

        n = other.n;
        m = other.m;
        s = vector<vector<float>>(n, vector<float>(m));

        for (int i = 0;i < n; ++i){
            for (int j = 0;j < m; ++j){

                s[i][j] = other.s[i][j];

            }
        }

    };

    matrix operator=(const matrix& other){

        if(this == &other){

            return *this;

        }

        n = other.n;
        m = other.m;
        s = vector<vector<float>>(n, vector<float>(m));

        for (int i = 0;i < n; ++i){
            for (int j = 0;j < m; ++j){

                s[i][j] = other.s[i][j];

            }
        }
        return *this;
    };

    matrix(const matrix& other, int r, int c, float value){

        n = other.n;
        m = other.m;
        s = vector<vector<float>>(n, vector<float>(m));

        for (int i = 0;i < n; ++i){
            for (int j = 0;j < m; ++j){

                s[i][j] = other.s[i][j];

            }
        }

        if(r >= 0 and r < n and c >= 0 and c < m){

            s[r][c] = value;

        }else{

            cout << "\nЕлемент поза масивом!\n";

        }

        

    };

    matrix(const matrix& other1, const matrix& other2){

        if(other1.n * other1.m > other2.n * other2.m){

            cout << "\nПерща матриця більша\n";

        }else if (other1.n * other1.m < other2.n * other2.m){

            cout << "\nДруга матриця більша\n";

        }else{

            cout<< "\nМатриці рівні\n";

        }


        

    };

    ~matrix(){


    }

    void show(){
        int index = 1;
        /*
        srand(time(0));

        for (int i = 0;i < n; ++i){
            for(int j = 0;j < m; ++j){

                s[i][j] = rand() % 100/ 100.0 * 100;

            }
        } 
        */

        for (int i = 0;i < n; ++i){
            for(int j = 0;j < m; ++j){

                cout << index << ": " << s[i][j] << "\n";
                index ++;
            }
        } 

    };

    
};


int main(){

    cout << "--- 1. Стандартний конструктор --- \n";
    matrix t1{};
    t1.show();

    cout << "\n--- 2. Конструктор з значенням n ---\n";
    matrix t2(4);
    t2.show();

    cout << "\n--- 3. Конструктор з значенням n,m,value --- \n";
    matrix t3(4,4,3);
    t3.show();

    cout << "\n--- 4. Конструктор копіювання --- \n";
    matrix t4(5,5,4);
    cout << "-- 1) Оригінальна матриця --\n";
    t4.show();
    t4 = t3;
    cout << "-- 2) Зкокійованна матриця --\n";
    t4.show();

    cout << "\n--- 5. Конструктор копіювання ---\n";
    matrix t5(6,6,5);
    cout << "-- 1) Оригінальна матриця --\n";
    t5.show();
    t5 = t2;
    cout << "-- 2) Присвоїна матриця --\n";
    t5.show();

    cout << "\n--- 6. Конструктор зміни значення ---\n";
    matrix t6(t3,3,2,5);
    cout << "-- 1) Оригінальна матриця --\n";
    t3.show();
    cout << "-- 2) Присвоїна матриця --\n";
    t6.show();

    cout << "\n--- 7. Конструктор порівняння ---\n";
    matrix t7(t3,t2);
    t7.show();

    return 0;
}