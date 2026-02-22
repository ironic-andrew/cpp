#include <iostream>
#include <cmath>
using namespace std;

class A{
public:
    virtual double sum(int n) const = 0;
    virtual ~A()= default;

};


class B: public A{
private:
    double a1;
    double a_last;


    public:

    B(double first, double last)
        : a1(first), a_last(last)
    {}

    double sum(int n) const override{
        return ((a1 + a_last) * n)/2;
    }

    ~B() = default;

};

class C: public A{
private:
    double b1;
    double q;


    public:

    C(double b1, double q)
        : b1(b1), q(q)
    {}

    double sum(int n) const override{
        if (q == 1) return b1 * n;
        return (b1 * (pow(q, n) - 1))/(q - 1);
    }

    ~C() = default;

};


int main(){

    A* p = new B(1, 5);
    A* g = new C(1, 2);
    cout << p->sum(5) << "\n";
    cout << g->sum(5) << "\n";
    delete p;


}