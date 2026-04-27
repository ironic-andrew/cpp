#include <iostream>
using namespace std;


class A {

    public:

    string A = "A";

};

class B: virtual public A {

    public:

    string B = "B";

};

class C: virtual public A {

    public:

    string C = "C";

};

class F: virtual public A, public C {

    public:

    string F = "F";

};

class M: virtual public B {

    public:

    string M = "M";

};

class G: virtual public B {

    public:

    string G = "G";

};

class S: public G, public M, public F {

    public:
    string S = "S";

    void show() {

        cout << A << " - " << "\n";

        cout << A << " - " << B << "\n";
        cout << A << " - " << C << "\n";
        cout << A << " - " << F << "\n";

        cout << A << " - " << C << " - " << F << "\n";
        cout << A << " - " << B << " - " << G << "\n";
        cout << A << " - " << B << " - " << M << "\n";

        cout << A << " - " << B << " - " << M << " - " << S << "\n";
        cout << A << " - " << B << " - " << G << " - " << S << "\n";
        cout << A << " - " << C << " - " << F << " - " << S << "\n";
        cout << A << " - " << F << " - " << S << "\n";


    }



};

int main(){

    S s;
    s.show();
    return 0;
};












