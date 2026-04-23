#include<iostream>
using namespace std;

class complex_numbers{

private:
int a,b,z1,z2;
int i = -1;

public:

    void setNumber(int index1, int index2){

        a = index1;
        b = index2;
        z1 = a + b * i;
        z2 = a - b * i;

    };

    void show(){

        cout<< "Формула: z = a + b * i " <<"\nКомплексне число дорівнює: " << z1 << "\n" << "a - " << a << "; b - " << b << "; i - " << i;
        cout<< "\n\nФормула: z = a - b * i " <<"\nКомплексне число дорівнює: " << z2 << "\n" << "a - " << a << "; b - " << b << "; i - " << i;

    };




};




int main(){
    complex_numbers cn;
    string n,m;
    int index1, index2;

    cout << "Ведіть значення: \n";
    while(true){
        cout << "a: ";
        cin >> n;
        
        try{

            index1 = stoi(n);

        }catch(...){

            cout << "Число має бути цілим!";

        }

        

        cout << "b: ";
        cin >> m;
        
        try{

            index2 = stoi(m);

        }catch(...){

            cout << "Число має бути цілим!";

        }   

        cn.setNumber(index1,index2);



        break;

    }

    cn.show();

return 0;
}