#include <iostream>
using namespace std;

class A {

    public:

        void show(){

            cout << A << "\n";

        }

    string A = "A";
};

class B:public A {

    public:

        void show(){

            cout << A << " - " << B << "\n";

        }

    string B = "B";

};

class C:public A {

    public:

        void show(){

            cout << A << " - " << C << "\n";

        }

    string C = "C";

};

class F_A:public A {

    

    public:

        void show(){

            cout << A << " - " << F << "\n";

        }

    string F = "F";

};

class F_C:public C {

    public:

        void show(){

            cout << A << " - " << C << " - " << F << "\n";

        }

    string F = "F";    
};

class G:public B {

    public:

        void show(){

            cout << A << " - " << B << " - " << G << "\n";

        }

    string G = "G";

};

class M:public B {

    

    public:

        void show(){

            cout << A << " - " << B << " - " << M << "\n";

        }

    string M = "M";

};

class S_G:public G {

    

    public:

        void show(){

            cout << A << " - " << B << " - " << G << " - " << S << "\n";

        }

    string S = "S";

};

class S_M:public M {

    public:

        void show(){

            cout << A << " - " << B << " - " << M << " - " << S << "\n";

        }

    string S = "S";

};

class S_F_C:public F_C {

    

    public:

        void show(){

            cout << A << " - " << C << " - " << F << " - " << S << "\n";

        }

    string S = "S";

};

class S_F_A:public F_A {

    public:

        void show(){

            cout << A << " - " << F << " - " << S << "\n";

        }

    string S = "S";

};


int main(){

A a;
B b;
C c;

F_A f_a;
F_C f_c;

M m;
G g;

S_F_A s_f_a;
S_F_C s_f_c;
S_G s_g;
S_M s_m;


a.show();
b.show();
c.show();

f_a.show();
f_c.show();

m.show();
g.show();

s_f_a.show();
s_f_c.show();
s_g.show();
s_m.show();


    return 0;
}





