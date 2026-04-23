#include <iostream>
using namespace std;

class Animal{
    public:

    void speack(){
        
        cout << "Тварини\n";

    }

    protected:
        
        string animal = "Тварина";

};

class Crow:public Animal{
    public:
    
        void speack(){

            cout << animal << " - ворона\n";

        }

    protected:
        
        string crow = "ворона";

};

class Lizard:public Animal{
    public:
    
        void speack(){

            cout << animal << " - ящерка\n";

        }

    protected:
        
        string lizard = "ящерка";

};




class Mammal: public Animal{
    public:   
    
        void speack(){
        
            cout << animal << " - савць\n";

        }

    protected:

        string mammal = "савець";

};


class Dog: public Mammal{
    public:
        void speack(){

            cout << animal<< " - " << mammal << " - собака \n";


        }

    protected:

    string dog = "собака";

};

class Cat: public Mammal{
    public:
        void speack(){

            cout << animal<< " - " << mammal << " - кіт \n";


        }

    protected:

    string cat = "кіт";

};

class Cloven_hoofed:public Mammal {
    public:

    void speack(){

        cout << animal << " - " << mammal << " - парнокопитні \n";

    }

    protected:

        string cloven_hoofed = "парнокопитні";

};


class Goat:public Cloven_hoofed {
    public:

    void speack(){

        cout << animal << " - " << mammal<< " - " << cloven_hoofed <<" - коза \n";

    }

    protected:

        string goat = "коза";
        
};

class Cow:public Cloven_hoofed {
    public:

    void speack(){

        cout << animal << " - " << mammal<< " - " << cloven_hoofed <<" - корова \n";

    }

    protected:

        string cow = "корова";
        
}; 



class Bird: public Animal{
    public:
        void speack(){

            cout << animal << " - птах \n";


        }

    protected:

    string bird = "птах";


};

class Ostrich: public Bird{
    public:
        void speack(){

            cout << animal<< " - " << bird << " - страус \n";


        }

    protected:

    string ostrich = "страус";


};

class Stork: public Bird{
    public:
        void speack(){

            cout << animal<< " - " << bird << " - лелека \n";


        }

    protected:

    string Stork = "лелека";


};





int main(){

    Animal animal;
    Crow crow;
    Lizard lizard;
    Dog dog;
    Cat cat;
    Ostrich ostrich;
    Stork stork;
    Goat goat;
    Cow cow;



    animal.speack();
    crow.speack();
    lizard.speack();
    dog.speack();
    cat.speack();
    ostrich.speack();
    stork.speack();
    goat.speack();
    cow.speack();



return 0;
}