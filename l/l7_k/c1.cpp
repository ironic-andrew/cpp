#include <iostream>
using namespace std;

struct new_date{

    string destination_place;
    int flight_number;
    string name;
    string sure_name;
    string middle_name;
    int day;
    int month;
    int year;
    int hour;
    int minutes;

    };

class Flight_date{



    public:
        int size = 0;
        new_date* arr = nullptr;

        void add(new_date d){
                
            new_date* new_arr = new new_date[size + 1];

            for (int i = 0; i < size; i++){

                    
                new_arr[i] = arr[i];

            }

                
            new_arr[size] = d;

            delete[] arr;
            arr = new_arr;
            size++;
        };

        void show(){

            if(size > 0){

                for (int i = 0; i < size; ++i){

                    cout << "\n----\n";
                    cout << "Квиток №" << i + 1;
                    cout << "\n----\n";

                    cout << "Місце призначення: " << arr[i].destination_place << "\n";
                    cout << "Номер рейсу: " << arr[i].flight_number << "\n";
                    cout << "ПІБ: " << arr[i].name << " " << arr[i].sure_name << " " << arr[i].middle_name  << "\n";
                    cout << "Бажана дата відправки: " << arr[i].day << ":" << arr[i].month << ":" << arr[i].year << "\n";
                    cout << "Точний час: " << arr[i].hour << ":" << arr[i].minutes << "\n";
                }

            }else{

                cout << "\nСписок пустий!\n";

            }
            
        };

        void del(){
            if (size > 0){

                delete[] arr;
                size = 0;

            }else{

                cout << "\nСписок пустий!\n";

            }
            

        };

        void filter_flight_number(int index){

            if (size > 0){

                for(int i = 0; i < size; ++i){
                    if(arr[i].flight_number == index){

                        cout << "\n----\n";
                        cout << "Квиток №" << i + 1;
                        cout << "\n----\n";

                        cout << "Місце призначення: " << arr[i].destination_place << "\n";
                        cout << "Номер рейсу: " << arr[i].flight_number << "\n";
                        cout << "ПІБ: " << arr[i].name << " " << arr[i].sure_name << " " << arr[i].middle_name  << "\n";
                        cout << "Бажана дата відправки: " << arr[i].day << ":" << arr[i].month << ":" << arr[i].year << "\n";
                        cout << "Точний час: " << arr[i].hour << ":" << arr[i].minutes << "\n";

                    }
                    

                }

            }else{

                cout << "\nСписок пустий!\n";

            }

        };

        void filter_date(int index1, int index2, int index3, int index4, int index5){

            if (size > 0){

                for(int i = 0; i < size; ++i){
                    if(arr[i].day == index1 and arr[i].month == index2 and arr[i].year == index3 and arr[i].hour == index4, arr[i].minutes == index5){

                        cout << "\n----\n";
                        cout << "Квиток №" << i + 1;
                        cout << "\n----\n";

                        cout << "Місце призначення: " << arr[i].destination_place << "\n";
                        cout << "Номер рейсу: " << arr[i].flight_number << "\n";
                        cout << "ПІБ: " << arr[i].name << " " << arr[i].sure_name << " " << arr[i].middle_name  << "\n";
                        cout << "Бажана дата відправки: " << arr[i].day << ":" << arr[i].month << ":" << arr[i].year << "\n";
                        cout << "Точний час: " << arr[i].hour << ":" << arr[i].minutes << "\n";

                    }
                    

                }

            }else{

                cout << "\nСписок пустий!\n";

            }

        }
  
        void end(){

            delete[] arr;

        }




};


int main(){
    Flight_date f;
    new_date n;
    while(true){
        int choice;

        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Додати\n";
        cout << "2. Переглянути\n";
        cout << "3. Очистити список\n";
        cout << "4. Знайти за номером рейсу\n";
        cout << "5. Знайти за датою\n";
        cout << "6. Вийти\n";
        cin >> choice;

        switch(choice){

            case 1:{
                string text;

                cout << "\nВведіть наступні данні: \n";

                cout << "Місце прибуття: ";
                cin >> n.destination_place;

                while(true){
                    cout << "Номер рейсу: ";
                    cin >> text;

                    try{
                        n.flight_number = stoi(text);
                        break;
                    }catch(...){

                        cout << "\nВедіть число!\n";

                    }
                    
                }

                cout << "Ім'я: ";
                cin >> n.name;

                cout << "Прізвище: ";
                cin >> n.sure_name;

                cout << "Побатькові: ";
                cin >> n.middle_name;

                while(true){
                    cout << "День: ";
                    cin >> text;

                    try{
                        n.day = stoi(text);
                        if(n.day > 31 or n.day < 1){
                            cout << "\nШось тут нетак!\n";
                            continue;
                        }
                        break;
                    }catch(...){

                        cout << "\nВедіть число!\n";

                    }
                    
                }

                while(true){
                    cout << "Місяць: ";
                    cin >> text;

                    try{
                        n.month = stoi(text);
                        if(n.month > 12 or n.month < 1){
                            cout << "\nШось тут нетак!\n";
                            continue;
                        }
                        break;
                    }catch(...){

                        cout << "\nВедіть число!\n";

                    }
                    
                }

                while(true){
                    cout << "Рік: ";
                    cin >> text;

                    try{
                        n.year = stoi(text);
                        if(n.year < 2026){
                            cout << "\nШось тут нетак!\n";
                            continue;
                        }

                        break;
                    }catch(...){

                        cout << "\nВедіть число!\n";

                    }
                    
                }

                while(true){
                    cout << "Година: ";
                    cin >> text;

                    try{
                        n.hour = stoi(text);
                        if(n.hour > 24 or n.hour < 1){
                            cout << "\nШось тут нетак!\n";
                            continue;
                        }

                        break;
                    }catch(...){

                        cout << "\nВедіть число!\n";

                    }
                    
                }
                
                while(true){
                    cout << "Хвилини: ";
                    cin >> text;

                    try{
                        n.minutes = stoi(text);
                        if(n.minutes > 60 or n.minutes < 1){
                            cout << "\nШось тут нетак!\n";
                            continue;
                        }

                        break;
                    }catch(...){

                        cout << "\nВедіть число!\n";

                    }
                    
                }

                f.add(n);
                break;
            }

            case 2:{

                f.show();
                break;
            }

            case 3:{

                f.show();

                string text;
                cout << "Ви впевненні що хочете видалити всі квитки(yes or no): ";
                cin >> text;

                if(text == "yes" or text == "y"){

                    f.del();

                }else{

                    break;

                }

                break;
            }

            case 4:{

                f.show();

                while(true){
                    string text;
                    int index;
                    cout << "Введіть номер рейсу: ";
                    cin >> text;

                    try{
                        index = stoi(text);
                        if(index < 1){
                            cout << "\nЧисло має бути дадатнім\n";
                            continue;
                        }

                        f.filter_flight_number(index);
                        break;
                    }catch(...){

                        cout << "\nВведіть число!\n";

                    }

                    
            

                }

                break;
            }

            case 5:{

                f.show();

                string text;
                int index1, index2, index3, index4, index5;

                cout << "\nВведіть наступні дані: \n";

                while(true){
                    cout << "День: ";
                    cin >> text;

                    try{
                        index1 = stoi(text);
                        if(index1 > 31 or index1 < 1){
                            cout << "\nШось тут нетак!\n";
                            continue;
                        }
                        break;
                    }catch(...){

                        cout << "\nВедіть число!\n";

                    }
                    
                }

                while(true){
                    cout << "Місяць: ";
                    cin >> text;

                    try{
                        index2 = stoi(text);
                        if(index2 > 12 or index2 < 1){
                            cout << "\nШось тут нетак!\n";
                            continue;
                        }
                        break;
                    }catch(...){

                        cout << "\nВедіть число!\n";

                    }
                    
                }

                while(true){
                    cout << "Рік: ";
                    cin >> text;

                    try{
                        index3 = stoi(text);
                        if(index3 < 2026){
                            cout << "\nШось тут нетак!\n";
                            continue;
                        }

                        break;
                    }catch(...){

                        cout << "\nВедіть число!\n";

                    }
                    
                }

                while(true){
                    cout << "Година: ";
                    cin >> text;

                    try{
                        index4 = stoi(text);
                        if(index4 > 24 or index4 < 1){
                            cout << "\nШось тут нетак!\n";
                            continue;
                        }

                        break;
                    }catch(...){

                        cout << "\nВедіть число!\n";

                    }
                    
                }
                
                while(true){
                    cout << "Хвилини: ";
                    cin >> text;

                    try{
                        index5 = stoi(text);
                        if(index5 > 60 or index5 < 1){
                            cout << "\nШось тут нетак!\n";
                            continue;
                        }

                        break;
                    }catch(...){

                        cout << "\nВедіть число!\n";

                    }
                    
                }

                f.filter_date(index1, index2, index3, index4, index5);
                break;

            }

            case 6:{

                f.end();
                cout << "\nУдачи!\n";
                return 0;

            }

            default: {

                cout << "\nНеправильний вибір, спробуйте ще раз!\n";

            }

        }
    }

}