#include <iostream>
using namespace std;

class B1{

protected:

string b1 = "B1";

public:

    void speak(){

        cout<< "B1\n";

    }


};

class D1:public B1{

protected:

string d1 = "B1 - D1";

public:

    void speak(){

        cout<< b1 << " - D1\n";

    }


};

class D2:private B1{

protected:

string d2 = "B1 - D2";

public:

    void speak(){

        cout<< b1 << " - D2\n";

    }


};

class B2{

protected:

string b2 = "B2";

public:

    void speak(){

        cout<< "B2\n";

    }

};


class D4:public D1, public D2, private B2{

protected:

string d4 = "D4";

public:

    void speak(){

        cout << d1 << " - D4\n";
        cout << d2 << " - D4\n";
        cout << b2 << " - D4\n";

    }

};



int main(){

    B1 b1;
    D1 d1;
    D2 d2;
    B2 b2;
    D4 d4;

    b1.speak();
    d1.speak();
    d2.speak();
    b2.speak();
    d4.speak();
    

    return 0;
}


