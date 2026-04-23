#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


year_month_day getToday() {
    auto now = system_clock::now();
    sys_days today = floor<days>(now);  
    return year_month_day{today};
}



class pasport{

    public:
        /*
        struct Pasport{
            
            string name_struct;
            string surename_struct;
            string middle_name_struct;
            int birthday_struct;
            int birthmonth_struct;
            int birthyear_struct;
            string birthplace_struct;
            string sex_struct;
            string nationality_struct;

        }
        */

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

        pasport(string name_main, string surename_main, string middle_name_main, int birthday_main, int birthmonth_main, int birthyear_main, string birthplace_main, string sex_main, string nationality_main){

            name = name_main;
            surename = surename_main;
            middle_name = middle_name_main;
            birthday = birthday_main;
            birthmonth = birthmonth_main;
            birthyear = birthyear_main;
            birthplace = birthplace_main;
            sex = sex_main;
            nationality = nationality_main;

        }

    void getAge(){
        
        auto today = getToday();

        age = int(today.year()) - birthyear;

        if (unsigned(today.month()) < birthmonth || (unsigned(today.month()) == birthmonth && unsigned(today.day()) < birthday)) {
            age--; 
        }


    };

        void show(){
            
            cout << "\n----";
            cout << "Паспортні дані";
            cout << "----\n\n";
            cout << "Ім'я: " << name << "\n";
            cout << "Прізвище: " << surename << "\n";
            cout << "По батькові: " << middle_name << "\n";
            cout << "Дата народження: "  << birthday << "." << birthmonth << "." << birthyear << "\n";
            cout << "Вік: " << age << "\n";
            cout << "Місце народження: " << birthplace << "\n";
            cout << "Стать: " << sex << "\n";
            cout << "Національність: " << nationality << "\n";

        };



    


};



int main(){

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

    pasport p(name_main, surename_main, middle_name_main, birthday_main, birthmonth_main, birthyear_main, birthplace_main, sex_main, nationality_main);
    p.getAge();
    p.show();









    return 0;

}










