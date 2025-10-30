#include<iostream>
#include<cmath>
using namespace std;


class Triangle{

private:
    int a = 0, b = 0, c = 0;
    bool marker1 = true,marker2 = true;

public:

    Triangle() {
        a = b = c = 0;
    }

    Triangle(int a1, int b1, int c1){

        if (a1 + b1 > c1 and a1 + c1 > b1 and c1 + b1 > a1){

            a = a1;
            b = b1;
            c = c1;

        }else{

            cout << "\n\nТрикутник є неправильним!\n\n";
            marker1 = false;
        }

    };

    Triangle(int x1, int x2, int x3, int y1, int y2, int y3){

        a = sqrt (pow(x2 - x1,2) + pow(y2 - y1, 2));
        b = sqrt (pow(x3 - x2,2) + pow(y3 - y2, 2));
        c = sqrt (pow(x1 - x3,2) + pow(y1 - y3, 2));

        if(!(a + b > c and a + c > b and c + b > a)){

            cout << "Точки не утворюють трикутник";
            a = 0;
            b = 0;
            c = 0;
            marker2 = false;
        
        }

    };


    void P_S1(){
            
        if(marker1 != false){
            int p = 0, s = 0;

            p = (a + b + c)/2;
            s = abs(p * (p - a) * (p - b) * (p - c));


            cout << "\n\nПериметер: " << a + b + c << "\n";
            cout << "\n\nПлоща: " << s << "\n";
            }

        };

    void P_S2(){
            
        if(marker2 != false){
            int p = 0, s = 0;

            p = (a + b + c)/2;
            s = abs(p * (p - a) * (p - b) * (p - c));


            cout << "\n\nПериметер: " << a + b + c << "\n";
            cout << "\n\nПлоща: " << s << "\n";
            }

        };

    void show(int x1, int x2, int x3, int y1, int y2, int y3, int a, int b, int c, string colour_a, string colour_b, string colour_c, string colour_a1, string colour_b1, string colour_c1){

        cout << "\na = " << a << " (" << colour_a << ")"  << " b = " << b << " (" << colour_b << ")" << " c = " << c << " (" << colour_c << ")"  <<"\n";
        cout << "x1 = " << x1 << " y1 = " << y1 << " (" << colour_a1 << ")"  << " x2 = " << x2 << " y2 = " << y2 << " (" << colour_b1 << ")" << " x3 = " << x3 << " x3 = " << x3 << " (" << colour_c1 << ")" << "\n";

    };

    void result(int x1, int x2, int x3, int y1, int y2, int y3,string colour_a1, string colour_b1, string colour_c1){

        a = sqrt (pow(x2 - x1,2) + pow(y2 - y1, 2));
        b = sqrt (pow(x3 - x2,2) + pow(y3 - y2, 2));
        c = sqrt (pow(x1 - x3,2) + pow(y1 - y3, 2));

        cout << "\na - " << a << " (" << colour_a1 << ")" << " b - " << b << " (" << colour_b1 << ")" << " c - " << c << " (" << colour_c1 << ")" << "\n";

    }









};

string colors[] = {
    "red", "green", "blue", "yellow", "black", "white",
    "orange", "purple", "cyan", "magenta", "brown", "gray",
    "pink", "lime", "navy", "teal", "olive", "maroon",

    "Red", "Green", "Blue", "Yellow", "Black", "White",
    "Orange", "Purple", "Cyan", "Magenta", "Brown", "Gray",
    "Pink", "Lime", "Navy", "Teal", "Olive", "Maroon"
};

int main(){
Triangle t;
int a = 0, b = 0, c = 0;
string colour_a, colour_b, colour_c;
int x1 = 0,x2 = 0,x3 = 0, y1 = 0,y2 = 0,y3 = 0;
string colour_a1, colour_b1, colour_c1;
string input;
bool marker;
int n = sizeof(colors) / sizeof(colors[0]);

    while (true) {

        int choice;
        


        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Додати(числовий)\n";
        cout << "2. Додати(кординатний)\n";
        cout << "3. Переглянути(загальне)\n";
        cout << "4. Переглянути перемитер, площу(числове)\n";
        cout << "5. Переглянути перемитер, площу(кординатне)\n";
        cout << "6. Переглянути сторони(кординатий)'\n";
        cout << "7. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;


        switch (choice) {
            //Додати(числове)
            case 1: {

                cout << "\nВведіть значення: \n";

                //a
                while (true){
                
                    cout << "a: ";
                    cin >> input;

                    try{
                        a = stoi(input);
                        if(a <= 0){
                            cout << "\nЗначення неможе бути від'ємним\n";
                            continue;
                        }
                        break;

                    }catch(...){

                        cout << "\nВведіть int значення!\n";

                    }
                }

                while(true){
                    marker = true;
                    cout << "Введіть колір: ";
                    cin >> input;

                    for (int i = 0; i < n; ++i){

                        if(colors[i] == input){
                            
                            colour_a = input;
                            marker = false;
                            break;
                        }else{

                            cout << "Такого кольору немає!";

                        }
                    }
                    if(marker == false){
                        break;
                    }
                }
                    //a-

                    //b
                    while (true){
                
                        cout << "b: ";
                        cin >> input;

                        try{
                            b = stoi(input);
                            if(b <= 0){
                                cout << "\nЗначення неможе бути від'ємним\n";
                                continue;
                            }
                            break;

                        }catch(...){

                            cout << "\nВведіть int значення!\n";

                        }
                    }


                    while(true){
                        marker = true;
                        cout << "Введіть колір: ";
                        cin >> input;

                        for (int i = 0; i < n; ++i){

                            if(colors[i] == input){
                                colour_b = input;
                                marker = false;
                                break;
                            }else{

                            cout << "Такого кольору немає!";

                        }
                        }
                        if(marker == false){
                            break;
                        }
                    }
                    //b-

                    //c
                    while (true){
                
                        cout << "с: ";
                        cin >> input;

                        try{
                            c = stoi(input);
                            if(c <= 0){
                                cout << "\nЗначення неможе бути від'ємним\n";
                                continue;
                            }
                            break;

                        }catch(...){

                            cout << "\nВведіть int значення!\n";

                        }
                    }


                    while(true){
                        marker = true;
                        cout << "Введіть колір: ";
                        cin >> input;

                        for (int i = 0; i < n; ++i){

                            if(colors[i] == input){
                                colour_c = input;
                                marker = false;
                                break;
                            }else{

                            cout << "Такого кольору немає!";

                        }
                        }
                        if(marker == false){
                            break;
                        }
                    }

                    //c-
            
                    break;
                }
            //Додати(числове) +---

            //Додати(Кординати)
            case 2: {

                cout << "Введіть значенння:\n";

                //x1
                while (true){

                    cout << "x1: ";
                    cin >> input;

                    try{
                        x1 = stoi(input);
                        break;

                    }catch(...){

                        cout << "\nВведіть int значення!\n";

                    }

                }
                //x1-

                //y1
                while (true){

                    cout << "y1: ";
                    cin >> input;

                    try{
                        y1 = stoi(input);
                        break;

                    }catch(...){

                        cout << "\nВведіть int значення!\n";

                    }

                }

                
                while(true){
                    marker = true;
                    cout << "Введіть колір: ";
                    cin >> input;

                    for (int i = 0; i < n; ++i){

                        if(colors[i] == input){
                            
                            colour_a1 = input;
                            marker = false;
                            break;
                        }else{

                            cout << "Такого кольору немає!";

                        }
                    }
                    if(marker == false){
                        break;
                    }
                }
                //y1-

                //x2
                while (true){

                    cout << "x2: ";
                    cin >> input;

                    try{
                        x2 = stoi(input);
                        break;

                    }catch(...){

                        cout << "\nВведіть int значення!\n";

                    }

                }
                //x2-

                //y2
                while (true){

                    cout << "y2: ";
                    cin >> input;

                    try{
                        y2 = stoi(input);
                        break;

                    }catch(...){

                        cout << "\nВведіть int значення!\n";

                    }

                }

                
                while(true){
                    marker = true;
                    cout << "Введіть колір: ";
                    cin >> input;

                    for (int i = 0; i < n; ++i){

                        if(colors[i] == input){
                            
                            colour_b1 = input;
                            marker = false;
                            break;
                        }else{

                            cout << "Такого кольору немає!";

                        }
                    }
                    if(marker == false){
                        break;
                    }
                }
                //y2-

                //x3
                while (true){

                    cout << "x3: ";
                    cin >> input;

                    try{
                        x3 = stoi(input);
                        break;

                    }catch(...){

                        cout << "\nВведіть int значення!\n";

                    }

                }
                //x3-

                //y3
                while (true){

                    cout << "y3: ";
                    cin >> input;

                    try{
                        y3 = stoi(input);
                        break;

                    }catch(...){

                        cout << "\nВведіть int значення!\n";

                    }

                }

                
                while(true){
                    marker = true;
                    cout << "Введіть колір: ";
                    cin >> input;

                    for (int i = 0; i < n; ++i){

                        if(colors[i] == input){
                            
                            colour_c1 = input;
                            marker = false;
                            break;
                        }else{

                            cout << "Такого кольору немає!";

                        }
                    }
                    if(marker == false){
                        break;
                    }
                }
                //y3-

                break;
            }
            //Додати(Кординати) +---

            //Перегяд(загальний)
            case 3: {

                t.show(x1, x2, x3, y1, y2, y3, a, b, c, colour_a, colour_b, colour_c, colour_a1, colour_b1, colour_c1);
                break;

            }
            //Перегяд(загальний) +---

            //переглянути(числовий)
            case 4:{

                if(a != 0 and b != 0 and c != 0){
                    Triangle t1(a, b, c);
                    t1.P_S1();
                }else{

                    cout << "\nВи ще невели значення!\n";

                }
                break;
            }
            //переглянути(числовий) +---

            //переглянути(кординатний)
            case 5:{

                if(x1 != 0 or x2 != 0 or x3 != 0 or y1 != 0 or y2 != 0 or y3 != 0){

                    Triangle t2(x1, x2, x3, y1, y2, y3);
                    t2.P_S2();

                }else{

                cout << "\nВи ще невели значення!\n";

                }

                break;
            }
            //переглянути(кординатний) +---

            //Підрахувати сторони(кординатний)
            case 6: {

                if(x1 != 0 or x2 != 0 or x3 != 0 or y1 != 0 or y2 != 0 or y3 != 0){
                    t.result(x1,x2,x3,y1,y2,y3,colour_a1, colour_b1, colour_c1);
                }else{

                cout << "\nВи ще невели значення!\n";

                }

                break;
            }
            //Підрахувати сторони(кординатний) +---

            //Вихід
            case 8:{

            cout << "\n\nудачи";
            return 0;

            }
            //Вихід +---

            default:
            cout << "Невірний вибір, спробуйте щераз!";

        }


    }


}














