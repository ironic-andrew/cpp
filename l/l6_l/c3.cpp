#include <iostream>
using namespace std;

class F{

    public:
       string f = "Файл"; 

        friend ostream& operator<<(ostream& os, const F& x){

            os << "Файл" << "\n";
            return os;
        }

        friend istream& operator>>(istream& is, F& x){

            cout << "Записати значення: ";
            is >> x.f;
            return is;
        }
};


class F_R:virtual public F{

    public:
       string f_r = "Файл для читання"; 

        friend ostream& operator<<(ostream& os, const F_R& x){

            os << x.f << " - " << "Файл для читання" << "\n";
            return os;
        }

        friend istream& operator>>(istream& is, F_R& x){

            cout << "Записати значення: ";
            is >> x.f;
            return is;
        }
};

class F_W:virtual public F{

    public:
       string f_w = "Файл для запису"; 

        friend ostream& operator<<(ostream& os, const F_W& x){

            os << x.f << " - " << "Файл для запису" << "\n";
            return os;
        }

        friend istream& operator>>(istream& is, F_W& x){

            cout << "Записати значення: ";
            is >> x.f;
            return is;
        }
};

class F_W_R:public F_R, public F_W{

    public:
       string f_w_r = "Файл для запису і читання"; 

        friend ostream& operator<<(ostream& os, const F_W_R& x){

            os << x.f << " - " << x.f_r << " - " << "Файл для запису і читання" << "\n" << x.f << " - " << x.f_w << " - " << "Файл для запису і читання" << "\n";
            return os;
        }

        friend istream& operator>>(istream& is, F_W_R& x){

            cout << "Записати значення: ";
            is >> x.f;
            return is;
        }
};


int main(){

    F f;
    F_R f_r;
    F_W f_w;
    F_W_R f_w_r;

    cout << f;
    cout << f_r;
    cout << f_w;
    cout << f_w_r;



    return 0;
}




