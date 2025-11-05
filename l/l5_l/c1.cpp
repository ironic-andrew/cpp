#include <iostream>
#include <cmath>
using namespace std;

class Figures{

public:
    void show(){

        cout << "Фігури\n";

    };
    string figures_text = "Фігури";
};


class Quadrangular:public Figures{

public:
    void show(){

        cout << figures_text <<" - чотирекутні\n";

    };
    string quadrangular_text = "чотирекутні";
};


class Quadrate:public Quadrangular{

private:

    int P, S, a;

public:
    void show(){

        cout << figures_text << " - " << quadrangular_text << " - " << "квадрат\n";

    };
    string quadrate_text = "квадрат";

    Quadrate(){



    };

    Quadrate(int a1){
        
        P = 4 * a1;
        S = a1 * a1;
        a = a1;

    };

    ~Quadrate(){

        P = 0;
        S = 0;
        a = 0;

    };

    void show_result(){

        cout << "а = " << a << "\n";
        cout << "Периметер - " << P << "\n";
        cout << "Площа - " << S << "\n";

    };

};


class Quadrangle:public Quadrangular{

private:

    int P, p, S, a, b, c, d;

public:
    void show(){

        cout << figures_text << " - " << quadrangular_text << " - " << "чотирикутники\n";

    };
    string quadrangle_text = "чотирикутники";

    Quadrangle(){



    };

    Quadrangle(int a1, int b1, int c1, int d1){
        
        p = (a1 + b1 + c1 + d1)/2; 
        P = a1 + b1 + c1 + d1;
        S = sqrt((p - a1)*(p - b1)*(p - c1)*(p - d1));
        a = a1;
        b = b1;
        c = c1;
        d = d1;

    };

    ~Quadrangle(){

        p = 0;
        P = 0;
        S = 0;
        a = 0;
        b = 0;
        c = 0;
        d = 0;

    };


    void show_result(){

        cout << "а = " << a << "\n";
        cout << "b = " << b << "\n";
        cout << "c = " << c << "\n";
        cout << "d = " << d << "\n";
        cout << "Периметер - " << P << "\n";
        cout << "Площа - " << S << "\n";

    };

};


class Rectangle:public Quadrangular{

private:

    int P, S, a, b;

public:
    void show(){

        cout << figures_text << " - " << quadrangular_text << " - " << "прямокутник\n";

    };
    string rectangle_text = "прямокутник";

    Rectangle(){



    };

    Rectangle(int a1, int b1){
         
        P = (a1 + b1)*2;
        S = a1 * b1;
        a = a1;
        b = b1;

    };

    ~Rectangle(){

        P = 0;
        S = 0;
        a = 0;
        b = 0;

    };


    void show_result(){

        cout << "а = " << a << "\n";
        cout << "b = " << b << "\n";
        cout << "Периметер - " << P << "\n";
        cout << "Площа - " << S << "\n";

    };

};



int main(){

    Figures t1;
    Quadrangular t1_1; 
    Quadrate t1_1_1;
    Quadrangle t1_1_2;
    Rectangle t1_1_3;

    t1.show();


    t1_1.show();


    t1_1_1.show();
    Quadrate q1(4);
    q1.show_result();


    t1_1_2.show();
    Quadrangle q2(3, 6, 4, 5);
    q2.show_result();

    t1_1_3.show();
    Rectangle q3(2, 4);
    q3.show_result();



    return 0;
}