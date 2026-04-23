#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;


year_month_day getToday() {
    auto now = system_clock::now();
    sys_days today = floor<days>(now);  
    return year_month_day{today};
}


class pasport{

    public:
        struct Pasport{
            
            string name_struct;
            string surename_struct;
            string middle_name_struct;
            int birthday_struct;
            int birthmonth_struct;
            int birthyear_struct;
            int age_struct;
            string birthplace_struct;
            string sex_struct;
            string nationality_struct;

        };
        vector<Pasport> vec;
        /*
        string name;
        string surename;
        string middle_name;
        int birthday;
        int birthmonth;
        int birthyear;
        string birthplace;
        string sex;
        string nationality;
        int age;
        */

        int age;

        void getAge(int birthday, int birthmonth, int birthyear){
        
            auto today = getToday();

            age = int(today.year()) - birthyear;

            if (unsigned(today.month()) < birthmonth || (unsigned(today.month()) == birthmonth && unsigned(today.day()) < birthday)) {
                age--; 
            }


        };

        void add(string name_main, string surename_main, string middle_name_main, int birthday_main, int birthmonth_main, int birthyear_main, string birthplace_main, string sex_main, string nationality_main){

            Pasport p = {name_main, surename_main, middle_name_main, birthday_main, birthmonth_main, birthyear_main, age, birthplace_main, sex_main, nationality_main};
            
            cout << "\n\ndsajdhsajk: " << vec.size();
            
            vec.push_back(p);
 
            cout << "\n\ndsajdhasdjkkjkdaskjasd: " << vec.size();

        }
    
        void show(){
            
            if(vec.empty()){

                cout << "\nДані ще не введенні!\n";

            }else{

                int index = 1;
                for (int i = 0; i < vec.size(); ++i){

                    cout << "\n----";
                    cout << "Паспортні дані №" << index;
                    cout << "----\n\n";
                    cout << "Ім'я: " << vec[i].name_struct << "\n";
                    cout << "Прізвище: " << vec[i].surename_struct << "\n";
                    cout << "По батькові: " << vec[i].middle_name_struct << "\n";
                    cout << "Дата народження: "  << vec[i].birthday_struct << "." << vec[i].birthmonth_struct << "." << vec[i].birthyear_struct << "\n";
                    cout << "Вік: " << vec[i].age_struct << "\n";
                    cout << "Місце народження: " << vec[i].birthplace_struct << "\n";
                    cout << "Стать: " << vec[i].sex_struct << "\n";
                    cout << "Національність: " << vec[i].nationality_struct << "\n";
                    index++;
            
            }

            }

            

            

        };

};



int main(){

pasport p;
    while(true){
        int choice;
        
        
        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Додати\n";
        cout << "2. Студент\n";
        cout << "3. Вийти\n";
        cin >> choice;

        switch(choice){

            case 1:{
        
                string name_main;
                string surename_main;
                string middle_name_main;
                string birthday_main_text;
                string birthmonth_main_text;
                string birthyear_main_text;
                int birthday_main;
                int birthmonth_main;
                int birthyear_main;
                string birthplace_main;
                string sex_main;
                string nationality_main;


                cout << "Введіть ім'я: ";
                cin >> name_main;
                cout << "Введіть прізвище: ";
                cin >> surename_main;
                cout << "Введіть по батькові: ";
                cin >> middle_name_main;

                while(true){
                    cout << "Введіть день народження: ";
                    cin >> birthday_main_text;

                    try{
                        birthday_main = stoi(birthday_main_text);
                        if(birthday_main <= 0){
                            cout<< "\nДень не може бути від'ємним або нульовим числом!\n\n";
                            continue;
                        }
                        if(birthday_main > 31){
                            cout<< "\nТакого дня немає!\n\n";
                            continue;
                        }

                        break;
                    }catch(...){

                        cout << "\nДень повинен бути числом!\n\n";

                    }
                }

                while(true){
                    cout << "Введіть місяць народження: ";
                    cin >> birthmonth_main_text;

                    try{
                        birthmonth_main = stoi(birthmonth_main_text);
                        if(birthmonth_main <= 0){
                            cout<< "\nМісяць не може бути від'ємним або нульовим числом!\n\n";
                            continue;
                        }
                        if(birthmonth_main > 12){
                            cout<< "\nТакого місяця немає!\n\n";
                            continue;
                        }

                        break;
                    }catch(...){

                        cout << "\nМісяць повинен бути числом!\n\n";

                    }
                }

                while(true){
                    cout << "Введіть рік народження: ";
                    cin >> birthyear_main_text;

                    try{
                        birthyear_main = stoi(birthyear_main_text);
                        if(birthyear_main <= 0){
                            cout<< "\nРік не може бути від'ємним або нульовим числом!\n\n";
                            continue;
                        }
                        if(birthyear_main < 1920){
                            cout<< "\nВи живі! Серйозно!\n\n";
                            continue;
                        }

                        break;
                    }catch(...){

                        cout << "\nРік повинен бути числом!\n\n";

                    }
                }


                cout << "Введіть місце народження: ";
                cin >> birthplace_main;
                cout << "Введіть стать: ";
                cin >> sex_main;
                cout << "Введіть громадянство: ";
                cin >> nationality_main;

                
                p.getAge(birthday_main, birthmonth_main, birthyear_main);
                p.add(name_main, surename_main, middle_name_main, birthday_main, birthmonth_main, birthyear_main, birthplace_main, sex_main, nationality_main);
                
                break;
            }

            case 2:{

                p.show();
                break;

            }

            case 3:{

                cout << "\nУдачи!\n";
                return 0;

            }

            default:{

                cout << "\nСпробуйте вести ще раз\n";

            }

        }
    }

    return 0;

}










