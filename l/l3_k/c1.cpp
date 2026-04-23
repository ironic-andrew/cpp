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
    vector<Book> Library;

    while (true) {

        int choice;
        


        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Додати\n";
        cout << "2. Переглянути\n";
        cout << "3. Видалити\n";
        cout << "4. Фільтер по автору\n";
        cout << "5. Фільтер по видавництву\n";
        cout << "6. Фільтер 'рік видання більше заданого числа'\n";
        cout << "7. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;


        switch (choice) {
            //Додати
            case 1: {
                while (true) {
                    Book new_book;

                    cout << "\nВведіть дані або напишіть 'back', щоб вийти:\n";

                    // --- Автор ---
                    cout << "Автор: ";
                    cin >> new_book.author;
                    //getline(cin, new_book.author);
                    if (new_book.author == "back") break;
                    //-+

                    // --- Назва ---
                    cout << "Назва: ";
                    cin >> new_book.title;
                    //getline(cin, new_book.title);
                    if (new_book.title == "back") break;
                    //-++

                    // --- Видавництво ---
                    cout << "Видавництво: ";
                    cin >> new_book.edition;
                    //getline(cin, new_book.edition);
                    if (new_book.edition == "back") break;
                    //-+++

                    // --- Рік видання ---
                    while (true) {
                        cout << "Рік видання: ";
                        string input;
                        getline(cin, input);

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
                        getline(cin, input);

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
            //-+

            //Переглянути
            case 2: {
                int i;
                
                cout << "\nБібліотека:\n\n";

                if(Library.empty()){

                    cout << "Ви ще не ввели жодної книги! \n";
                    break;

                    
                }else{

                    for (i = 0; i < Library.size(); ++i){

                        cout << i + 1 << ": " << "  Автор - " << Library[i].author << "  Назва - " << Library[i].title << "  Видавець" << Library[i].edition << "  Рік видання - " << Library[i].year << "  Кількість сторінок - " << Library[i].pages << ".\n";
    
                    }
                    break;

                }    


            }
            //-++
            
            //Видалити
            case 3: {
            
            if (Library.empty()){

                cout<< "\nВи не ввели ще жодної книги! \n";
                    break;

                }else{

                    int index = 0;     

                    while(true){

                        cout << "\nВедіть рядок який видалити або 'back', щоб вийти: ";
                        string n;
                        cin >> n;
                        cout << "\n";

                        if (n == "back") break;


                            try {
                                index = stoi(n);
                                index--;
                                if (index < 0) {
                                    cout << "Рядок не може бути від’ємним! Спробуйте ще раз.\n";
                                    continue;
                                }
                                
                            } catch (...) {
                                cout << "Невірний формат! Введіть число (наприклад: 4).\n";
                            }

                            if (index < 0 || index >= Library.size()) {
                                cout << "Такого рядка" << "[ " << n << " ]" << "немає! Спробуйте ще раз.\n";
                                continue;
                            }

                            Library.erase(Library.begin() + index);
                            cout << "Рядок " << n << " видалено! \n";
                            break;

                    }
                    break;

                }
            }
            //-+++

            //Фільтер по автору
            case 4: {
                if (Library.empty()){

                    cout<< "\nВи не ввели ще жодної книги! \n";
                    break;

                }else{

                    int j = 0;
                    cout << "Введіть ім'я автора або 'back', щоб вийти: ";
                    string text;
                    cin >> text;
                    cout << "\n";

                    if (text == "back") break;

                    cout << "Всі книги за авторством - " << text << "\n\n";
                    for (int i = 0; i < Library.size(); ++i){

                        if  (Library[i].author == text){

                            cout << i + 1 << ": " << "  Автор - " << Library[i].author << "  Назва - " << Library[i].title << "  Видавець" << Library[i].edition << "  Рік видання - " << Library[i].year << "  Кількість сторінок - " << Library[i].pages << ".\n";
                            j++;
                        }
                    }

                    if (j == 0 ){

                        cout << "Немає книг цього автора! \n";
                        break;
                    }
                    break;

                }
            }
            //-++++
        
            //Фільтер по видавництву
            case 5: {

                if  (Library.empty()){

                    cout<< "\nВи не ввели ще жодної книги! \n";
                    break;
                }else{
                    int j = 0;
                    cout << "Введіть назву видавництва або 'back', щоб вийти: ";
                    string text;
                    cin >> text;
                    cout << "\n";

                    if (text == "back") break;

                    cout << "Всі книги за видавництвом - " << text << "\n\n";
                    for (int i = 0; i < Library.size(); ++i){

                        if  (Library[i].edition == text){

                            cout << i + 1 << ": " << "  Автор - " << Library[i].author << "  Назва - " << Library[i].title << "  Видавець" << Library[i].edition << "  Рік видання - " << Library[i].year << "  Кількість сторінок - " << Library[i].pages << ".\n";
                            j++;
                        }
                    }

                    if (j == 0 ){

                        cout << "Немає книг цього видавництва! \n";
                        break;
                    }
                    break;

                }



            }
            //-+++++

            //Фільтер книги що вийшли після вказаного року
            case 6:{

                if (Library.empty()){

                    cout<< "\nВи не ввели ще жодної книги! \n";
                    break;

                }else{
                    int year, j = 0;   

                    while(true){
                        

                        cout << "\nВведіть рік або 'back', щоб вийти: ";
                        string text;
                        cin >> text;
                        cout << "\n";

                        if (text == "back") break;


                            try {
                                year = stoi(text);
                                
                                if (year < 0) {
                                    cout << "Рік неможе бути від'ємним числом!\n";
                                    continue;
                                }
                                
                            } catch (...) {
                                cout << "Невірний формат! Введіть число (наприклад: 2020).\n";
                            }

                            for (int i = 0; i < Library.size(); ++i){

                                if (Library[i].year > year){

                                    cout << i + 1 << ": " << "  Автор - " << Library[i].author << "  Назва - " << Library[i].title << "  Видавець" << Library[i].edition << "  Рік видання - " << Library[i].year << "  Кількість сторінок - " << Library[i].pages << ".\n";
                                    j++;
                                }


                            }                            

                            if (j == 0 ){

                                cout << "Таких книг немає! \n";

                            }
                            break;

                    }
                    break;
                }
            }
            //-++++++

            //Вихід
            case 7: {

                cout << "Удачи!";
                return 0;

            }
            //-+++++++

            default:
            cout << "\nНевірний вибір спробуйте щераз \n";

        }
    }
}