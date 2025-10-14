#include "c.h"
#include "f.cpp"
#include<iostream>
#include<limits>
using namespace std;




int main(){
    Video video_main;


    while (true) {

        int choice;
        
        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Додати\n";
        cout << "2. Переглянути\n";
        cout << "3. Фільтер по режисеру\n";
        cout << "4. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;


        switch (choice) {
            //Додати
            case 1: {

                    string name_str, rezhiser_str, genre_str, year_str;
                    int index, count = 0;
                    bool marker;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                while(true){

                    cout<< "Ведіть данні: \n\n";
                    cout << "Введіть назву або 'back' щоб вийти: ";
                    
                    getline(cin, name_str);
                    if(name_str == "back" ) break;

                    cout << "Введіть режисера або 'back' щоб вийти: ";
                    getline(cin, rezhiser_str);
                    if(rezhiser_str == "back" ) break;

                    cout << "Введіть жанр або 'back' щоб вийти: ";
                    getline(cin, genre_str);
                    if(genre_str == "back" ) break;


                    while(true){

                        cout << "Введіть рік випуску або 'back' щоб вийти: ";
                        getline(cin, year_str);
                        if(year_str == "back" ) goto end;    
                        cout << "\n";



                        try{

                            index = stoi(year_str);
                            break;

                        }catch(...){

                            cout<< "Введене значення має бути цілим числом! \n\n";

                        }

                    }
                    
                    video_main.add(name_str, rezhiser_str, genre_str, index);
                    
                    
                    
                }

                end:
                break;
            }


            case 2:{

                video_main.show();
                break;

            }


            case 3:{

                video_main.filter_rezhiser();
                break;

            }


            case 4:{

                cout << "\nУдачи!";
                return 0;

            }


            default:
            cout << "\nНевірний вибір спробуйте щераз \n";

        }
    }





}


