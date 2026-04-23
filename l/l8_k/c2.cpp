#include <iostream>
#include <vector>
using namespace std;

void math(vector<float> numbers) {
    int s = 0;
    for(int i = 0; i < numbers.size(); ++i){

        s += numbers[i] * numbers[i];

    }

    cout << "\nВідповідь: " << s << "\n";

};


int main(){
    vector<float> numbers; 
    int n;

    while(true){

        int choice;

        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Спробувати підрахувати\n";
        cout << "2. Вийти\n";
        cin >> choice;

        switch(choice){

            case 1:{
                string text;
                cout << "Введіть числа(back щоб вийти): ";

                while(true){
                    cin >> text;

                    if(text == "Back" or text == "back" or text == "B" or text == "b") break;

                    try{
                        n = stoi(text);
                        numbers.push_back(n);
                        
                    }catch(...){

                        cout << "\nВведіть число!\n";

                    }

                }

                math(numbers);
                break;

            }

            case 2:{

                cout << "\nУдачи!\n";
                break;

            }

            default:{

                cout << "\nСпробуй ще раз!\n";

            }

        }

    }












}