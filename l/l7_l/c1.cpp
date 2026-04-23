#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Клас студент(запис, вивід + сортування, прийняття зміни доступу)
class student{

    protected:

        string name;
        string sure_name;
        string middle_name;
        float mark;
        struct date{
            string s1;
            string s2;
            string s3;
            float m;
            bool access;
        };
        vector<date> vec;
        

    public:
        //запис
        void add (string i_name, string i_sure_name, string i_middle_name, float i_mark){

            date d = {i_name, i_sure_name, i_middle_name, i_mark, false};
            vec.push_back(d);

        }
        //вивід + сортування(з урахуванням доступу)
        void show(){

            if(vec.empty()){

                cout << "\nДані відсутні!\n";

            }else{

                int index = 1;
                sort(vec.begin(), vec.end(), [](const date& a, const date& b){ return a.m > b.m;});

                for (const auto& d : vec){
                    
                    if(d.access){
                    
                        cout << index << ") " << "Ім'я - " << d.s1 << " Прізвище - " << d.s2 << " По батькові - " << d.s3 << " Оцінка - " << d.m << "\n";
                        index++;
                    
                    }
                    
                }

            }
            

        }
        //вивід + сортування(без урахування доступу)
        void showAll(){
            
            if(vec.empty()){

                cout << "\nДані відсутні!\n";

            }else{
            
                int index = 1;
                sort(vec.begin(), vec.end(), [](const date& a, const date& b){ return a.m > b.m;});

                for (const auto& d : vec){
                    
                    cout << index << ") " << "Ім'я - " << d.s1 << " Прізвище - " << d.s2 << " По батькові - " << d.s3 << " Оцінка - " << d.m << " Доступ - " << d.access << "\n";
                    index++;
                    
                }

            }

        }
        //прийняття зміни доступу
        void giveAccess(int index) {
        if (index < vec.size()) {
            vec[index].access = true;
        }
        }

};
//Клас вчитель(вивід + сортування, передання доступу)
class teacher{
    public:
        //вивід + сортування(без урахування доступу)
        void show(student &s){
            
            s.showAll();

        }
        //передання доступу
        void addAccess(student &s, int index){

            s.giveAccess(index);

        }
};





int main(){
    student s;
    teacher t;
    //Головне меню
    while (true){
        int choice;

        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Викладач\n";
        cout << "2. Студент\n";
        cout << "3. Вийти\n";
        cin >> choice;

        switch(choice){

        //Головне меню/Викладач
        case 1:{
            bool y = true;
            while (y){
                int choice_t;

            cout << "\n=== МЕНЮ ===\n";
            cout << "1. Надати доступ до тестів\n";
            cout << "2. Переглянути\n";
            cout << "3. Повернутися назад\n";
            cout << "4. Вийти\n";
            cin >> choice_t;

                //Повернутися до Головного меню
                if(choice_t == 3) break; 

            switch(choice_t){
                //Надання доступу до результатів
                case 1:{
                    bool j = true;
                    string input;
                    int index;
                    t.show(s);
                    
                    while (j){

                        cout << "Введіть номер студента результат якого бажаєте розблокувати: " ;
                        cin >> input;
                        if (input == "back") {

                            j = false;
                            break;

                        }

                        try {
                            index = stoi(input);
                            if (index < 0) {
                                cout << "Номер повинен бути додатнім!\n";
                                continue;
                            }
                            break;
                        }catch (...) {
                            cout << "Невірний формат! Введіть число.\n";
                        }

                    }

                    t.addAccess(s, index - 1);
                    
                    break;
                }
                //Перегляда результатів(без урахуванням достпу)
                case 2:{

                    t.show(s);
                    break;

                }
                //Вихід
                case 4:{

                    cout << "\nУдачи!\n";
                    return 0;

                }

                default: {

                    cout << "\nНевірно веденні дані, спробуйте ще раз!\n";

                }

            }

            }
            break;
        }
        //Головне меню/Студент
        case 2:{
        bool t = true;
        while (t){
            int choice_s;

            cout << "\n=== МЕНЮ ===\n";
            cout << "1. Скласти тест\n";
            cout << "2. Переглянути результати\n";
            cout << "3. Повернутися назад\n";
            cout << "4. Вийти\n";
            cin >> choice_s;

                //Повернутися до Головного меню
                if(choice_s == 3) break; 

            switch(choice_s){
                //Тест + відправка результатів
                case 1: {

                    string name;
                    string sure_name;
                    string middle_name;
                    float mark = 0;
                    string input;

                    while (true){

                        cout << "Введіть ім'я: ";
                        cin >> name;
                        if (name == "back") break;

                        cout << "Введіть прізвище: ";
                        cin >> sure_name;
                        if (sure_name == "back") break;

                        cout << "Введіть по батькові: ";
                        cin >> middle_name;
                        if (middle_name == "back") break;

                        

                        cout << "1. Що означає скорочення CPU?\n"
                                "a) Central Process Unit\n"
                                "b) Central Processing Unit\n"
                                "c) Computer Personal Unit\n"
                                "d) Control Processing Utility\n";
                        cin >> input;
                        if (input == "back") return 0;
                        if (input == "b" || input == "B") mark++;

                        cout << "2. Що таке FPS в іграх?\n"
                                "a) Формат пікселів\n"
                                "b) Кількість кадрів за секунду\n"
                                "c) Швидкість інтернету\n"
                                "d) Частота процесора\n";
                        cin >> input;
                        if (input == "back") return 0;
                        if (input == "b" || input == "B") mark++;

                        cout << "3. Який компонент відповідає за обробку графіки?\n"
                                "a) RAM\n"
                                "b) SSD\n"
                                "c) GPU\n"
                                "d) PSU\n";
                        cin >> input;
                        if (input == "back") return 0;
                        if (input == "c" || input == "C") mark++;

                        cout << "4. Що означає скорочення RAM?\n"
                                "a) Random Access Memory\n"
                                "b) Read Access Memory\n"
                                "c) Run Active Memory\n"
                                "d) Rapid Action Module\n";
                        cin >> input;
                        if (input == "back") return 0;
                        if (input == "a" || input == "A") mark++;

                        cout << "5. Який пристрій використовується для зберігання даних?\n"
                                "a) GPU\n"
                                "b) SSD\n"
                                "c) PSU\n"
                                "d) Cooler\n";
                        cin >> input;
                        if (input == "back") return 0;
                        if (input == "b" || input == "B") mark++;

                        cout << "6. Що вимірюється в гігагерцах (GHz)?\n"
                                "a) Об'єм пам'яті\n"
                                "b) Температура\n"
                                "c) Частота процесора\n"
                                "d) Роздільна здатність\n";
                        cin >> input;
                        if (input == "back") return 0;
                        if (input == "c" || input == "C") mark++;

                        cout << "7. Який компонент відповідає за обробку графіки?\n"
                                "a) RAM\n"
                                "b) SSD\n"
                                "c) GPU\n"
                                "d) HDD\n";
                        cin >> input;
                        if (input == "back") return 0;
                        if (input == "c" || input == "C") mark++;

                        cout << "8. Яка операційна система найчастіше використовується на ПК?\n"
                                "a) Windows\n"
                                "b) iOS\n"
                                "c) Android\n"
                                "d) Linux Mint\n";
                        cin >> input;
                        if (input == "back") return 0;
                        if (input == "a" || input == "A") mark++;

                        cout << "9. Що таке SSD?\n"
                                "a) Тип відеокарти\n"
                                "b) Швидкий накопичувач даних\n"
                                "c) Оперативна пам'ять\n"
                                "d) Блок живлення\n";
                        cin >> input;
                        if (input == "back") return 0;
                        if (input == "b" || input == "B") mark++;

                        cout << "10. Для чого потрібен блок живлення (PSU)?\n"
                                "a) Для охолодження\n"
                                "b) Для зберігання даних\n"
                                "c) Для подачі електроенергії\n"
                                "d) Для обробки графіки\n";
                        cin >> input;
                        if (input == "back") return 0;
                        if (input == "c" || input == "C") mark++;

                        cout << "11. Що означає розгін процесора?\n"
                                "a) Зменшення температури\n"
                                "b) Підвищення частоти роботи\n"
                                "c) Очищення пам'яті\n"
                                "d) Зменшення напруги\n";
                        cin >> input;
                        if (input == "back") return 0;
                        if (input == "b" || input == "B") mark++;

                        cout << "12. Який кабель найчастіше використовують для підключення монітора?\n"
                                "a) HDMI\n"
                                "b) USB\n"
                                "c) LAN\n"
                                "d) AUX\n";
                        cin >> input;
                        if (input == "back") return 0;
                        if (input == "a" || input == "A") mark++;

                        s.add(name, sure_name, middle_name, mark);

                        cout << "\nТест завершено!\n";

                        break;
                    }
                    break;
                }
                //Переглянути результати(з урахуванням доступа)
                case 2: {

                    
                    s.show();

                    break;
                }
                //Вийти
                case 4:{

                    cout << "\nУдачи!\n";
                    return 0;

                }

                default: {

                    cout << "\nНевірно веденні дані, спробуйте ще раз!\n";

                }

            }

            }
        break;
    }
        //Головне меню/Вийти
        case 3:{

            cout << "\nУдачи!\n";
            return 0;

        }

        default: {

                cout << "\nНевірно веденні дані, спробуйте ще раз!\n";

            }

        }
    }

    return 0;
};



