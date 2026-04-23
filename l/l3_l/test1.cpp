#include<iostream>
using namespace std;

class MultiSet{

    private:

    unsigned* s;
    unsigned int beg, end, size;

    public:
    //Без параметрів
    MultiSet(){
        beg = 0;
        end = 100;
        size = end - beg;
        s = new unsigned[size]{0};
        
    };
    //Без параметрів +---

    //З параметром end
    MultiSet(unsigned int end){
        beg = 0;

        if (end <= beg) {
            cout << "Помилка: end має бути > beg!";
            end = beg + 1;
        }

        size = end - beg;
        s = new unsigned[size]{0};

    };
    //З параметром end +---

    //З параметрами end і beg
    MultiSet(unsigned int beg, unsigned int end){
        size = end - beg;
        s = new unsigned int[size]{0};

    };
    //З параметрами end і beg +---

    //З параметрами end, beg і value
    MultiSet(unsigned int beg, unsigned int end, unsigned int value){
        size = end - beg;
        s = new unsigned int[size]{value};

    };
    //З параметрами end, beg і value +---

    //Оператор копіювання
    MultiSet(const MultiSet& other){
        beg = other.beg;
        end = other.end;
        size = other.size;

        if(other.s != nullptr){
            for (int i = 0; i < size; ++i){

                s[i] = other.s[i];

            }
        }else{

            s = nullptr;

        }

    };
    //Оператор копіювання +---

    //оператор присвоєння
    MultiSet operator =(const MultiSet& other){
        if(this == &other){

            return *this;

        }

        beg = other.beg;
        end = other.end;
        size = other.size;

        if(other.s != nullptr){
            for (int i = 0; i < size; ++i){

                s[i] = other.s[i];

            }
        }else{

            s = nullptr;

        }


    }
    //оператор присвоєння +---

    void show(unsigned int beg, unsigned int end, unsigned int value){

        cout << "\nBeg - " << beg << " end - " << end << " value - " << value << " size - " << end - beg << "\n";
        for (unsigned int i = 0; i < size; ++i) {
            unsigned int element = beg + i; 
            cout << "Елемент: " << element << " | Кількість повторень: " << s[i] << "\n";
        }

    };

    void add(int number){

    if (number < beg or number >= end) {
            cout << "\nЧисло " << number << " поза діапазоном [" << beg << ", " << end << ")\n";
            return;
        }

        unsigned int index = number - beg;
        s[index]++;
        cout << "\nЧисло " << number << "в діапазоні\n";
    };

};


int main(){
int beg = 0, end = 0, value = 0, index = 0, number = 0;
MultiSet t;
string input;

    while (true) {

        int choice;
        


        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Додати значення\n";
        cout << "2. Додати числа\n";
        cout << "3. Переглянути\n";
        cout << "4. Переглянути перемитер, площу(числове)\n";
        cout << "5. Переглянути перемитер, площу(кординатне)\n";
        cout << "6. Переглянути сторони(кординатий)'\n";
        cout << "7. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;


        switch (choice) {

            case 1:{
                index = 0;
                beg = end = value = 0;

                cout << "Введіть значення або '-' Щоб вийти: \n";

                while(true){

                    cout << "Beg: ";
                    cin >> input;

                    if(input == "-"){

                        break;

                    }

                    try{

                        beg = stoi(input);
                        if(beg <= 0){

                            cout << "\nЗначення має бути додатнім!\n";
                            continue;

                        }
                        index += index + 1;
                        break;
                    }catch(...){

                        cout << "\nЗначення має бути числовим(int)!\n";

                    }

                }

                

                while(true){

                    cout << "End: ";
                    cin >> input;

                    if(input == "-"){

                        break;

                    }

                    try{

                        end = stoi(input);
                        if(end <= 0){

                            cout << "\nЗначення має бути додатнім!\n";
                            continue;

                        }
                        index += index + 1;
                        break;
                    }catch(...){

                        cout << "\nЗначення має бути числовим(int)!\n";

                    }

                }

               

                while(true){

                    cout << "Value: ";
                    cin >> input;

                    if(input == "-"){

                        break;

                    }

                    try{

                        value = stoi(input);
                        if(value <= 0){

                            cout << "\nЗначення має бути додатнім!\n";
                            continue;

                        }
                        index += index + 1;
                        break;
                    }catch(...){

                        cout << "\nЗначення має бути числовим(int)!\n";

                    }

                }

                break;
            }


            case 2:{

                while(true){
                cout << "Напишіть число або 'back' щоб вийти: ";
                cin >> input;

                if(input == "back"){

                    break;

                }

                try{
                    number = stoi(input);
                    if(number <= 0){

                        cout << "\nЗначення має бути додатнім!\n";
                        continue;

                    }
                    break;
                    }catch(...){

                        cout << "\nЗначення має бути числовим(int)!\n";

                    }

                if(index == 3){

                    MultiSet t1(beg, end, value);
                    t.add(number);
                    
                }else if(index == 2){

                    MultiSet t2(beg, end);
                    t.add(number);

                }else if(index == 1){

                    MultiSet t3(end);
                    t.add(number);

                }else{

                    MultiSet t4{};
                    t.add(number);
                    string text = "Ви нічого не ввели!";

                }

            
                }
            break;
            }



            case 3:{

                if(index == 3){

                    MultiSet t1(beg, end, value);
                    t1.show(beg, end, value);
                    
                }else if(index == 2){

                    MultiSet t2(beg, end);
                    t2.show(beg, end, value);

                }else if(index == 1){

                    MultiSet t3(end);
                    t3.show(beg, end, value);

                }else{

                    MultiSet t4{};
                    t4.show(beg, end, value);
                    string text = "Ви нічого не ввели!";

                }

                break;

            }






        
            case 8:{

                cout << "Удачи!";
                return 0;

            }

            default:
            cout << "Введене невірне значення, спробуйте щераз";

        }

    }












}