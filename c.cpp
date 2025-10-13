#include <iostream>
#include <vector>
#include <limits>
using namespace std;




struct Book{

    string author;
    string title;
    string edition;
    int year;
    int pages;

};



int main(){


    while (true) {

        int choice;
        vector<Book> Library;


        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Додати\n";
        cout << "2. Магічний куб\n";
        cout << "3. Вгадай число\n";
        cout << "4. Переклад на морзянку\n";
        cout << "5. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;


        switch (choice) {
            case 1: {
                while (true) {
                    Book new_book;

                    cout << "\nВведіть дані або напишіть 'back', щоб вийти:\n";

                    // --- Автор ---
                    cout << "Автор: ";
                    cin >> new_book.author;
                    if (new_book.author == "back") break;
                    //-+

                    // --- Назва ---
                    cout << "Назва: ";
                    cin >> new_book.title;
                    if (new_book.title == "back") break;
                    //-++

                    // --- Видавництво ---
                    cout << "Видавництво: ";
                    cin >> new_book.edition;
                    if (new_book.edition == "back") break;
                    //-+++

                    // --- Рік видання ---
                    while (true) {
                        cout << "Рік видання: ";
                        string input;
                        cin >> input;

                        if (input == "back") goto end_input;

                        try {
                            new_book.year = stoi(input);
                            if (new_book.year < 0) {
                                cout << "Рік не може бути від’ємним! Спробуйте ще раз.\n";
                                continue;
                            }
                            break;
                        } catch (...) {
                            cout << "Невірний формат! Введіть число (наприклад: 2020).\n";
                        }
                    }
                    //-++++

                    // --- Кількість сторінок ---
                    while (true) {
                        cout << "Кількість сторінок: ";
                        string input;
                        cin >> input;

                        if (input == "back") goto end_input;

                        try {
                            new_book.pages = stoi(input);
                            if (new_book.pages <= 0) {
                                cout << "Кількість сторінок має бути більше нуля!\n";
                                continue;
                            }
                            break;
                        } catch (...) {
                            cout << "Невірний формат! Введіть число (наприклад: 350).\n";
                        }
                    }
                    //-+++++

                    Library.push_back(new_book);
                    cout << "\nКнигу додано до бібліотеки!\n";
                }

                end_input:
                break;
            }

                
            case 2: {
                int i = 0;
                
                cout << "\nБібліотека\n";

                for (i; i < Library.size(); ++i){

                    cout << i + 1 << ": " << "  Автор - " << Library[i].author << "  Назва - " << Library[i].title << "  Видавець" << Library[i].edition << "  Рік видання - " << Library[i].year << "  Кількість сторінок - " << Library[i].pages << ".\n";

                }


            }
            
        












            default:
            cout << "\nНевірний вибір спробуйде щераз \n";

        }
    }
}