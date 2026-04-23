#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include <map>
using namespace std;




int main() {
    int choice;

map<char, string> morse = {
        {'A', ".--"},
        {'B', "-..."},
        {'C', "-.-."},
        {'D', "-.."},
        {'E', "."},
        {'F', "..-."},
        {'G', "--."},
        {'H', "...."},
        {'I', ".."},
        {'J', ".---"},
        {'K', "-.-"},
        {'L', ".-.."},
        {'M', "--"},
        {'N', "-."},
        {'O', "---"},
        {'P', ".--."},
        {'Q', "--.-"},
        {'R', ".-."},
        {'S', "..."},
        {'T', "-"},
        {'U', "..-"},
        {'V', "...-"},
        {'W', ".--"},
        {'X', "-..-"},
        {'Y', "-.--"},
        {'Z', "--.."}
    };

    while (true) {
        cout << "\n=== МЕНЮ ===\n";
        cout << "1. AVG\n";
        cout << "2. Магічний куб\n";
        cout << "3. Вгадай число\n";
        cout << "4. Переклад на морзянку\n";
        cout << "5. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:{
                int n, i, value, s = 0;
                vector<int> numbers;
                
                cout << "\nВедіть значення: ";
                cin >> n; 



                for (i = 0; i < n; ++i){

                    cout << i+1 << " : ";
                    cin >> value;
                    numbers.push_back(value);

                }

                for (i = 0; i < n; ++i){

                    s += numbers[i];

                }

                s = s/numbers.size();

                cout << "\nРезультат: " << s  << "\n";

                break;

            }

            case 2:{

                int n = 0 , b = 0, i = 0, value = 0, j = 0, row_up = 0, row_down = 0, row_diagonal = 0, s = 0, ss = 0, row_diagonal_reverse = 0;
                bool magic = true;
                n = 3;
                b = 3;

                 vector<vector<int>> numbers(n, vector<int>(b));
                vector<int> row_up_n; 
                vector<int> row_down_n; 

                

                 for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < b; ++j) {
                        cout << "Введіть число для [" << i + 1 << "][" << j + 1 << "]: ";
                        cin >> value;
                        numbers[i][j] = value; 
                    }
                }


                 cout << "\nМатриця:\n";
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < b; ++j) {
                        cout << numbers[i][j] << " ";
                    }
                    cout << endl; 
                }


                s = 0;
                ss = b - 1;

                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < b; ++j) {

                        row_up += numbers[i][j];
                        row_down += numbers[j][i];
                        
                        

                    }
                row_diagonal += numbers[i][s];
                row_diagonal_reverse += numbers[i][ss];

                s++;
                ss--;

                row_up_n.push_back(row_up);
                row_down_n.push_back(row_down);

                row_up = 0;
                row_down = 0;
                }
                


                for (int i = 0; i < row_up_n.size(); ++i) {
                   if (row_up_n[0] != row_up_n[i]){

                    cout << "\nМатриця не є магічним кубом\n";
                    magic = false;
                    break;
                   }
                }
                if (magic != true){

                    break;

                }


                for (int i = 0; i < row_down_n.size(); ++i) {
                   if (row_down_n[0] != row_down_n[i]){

                    cout << "\nМатриця не є магічним кубом\n";
                    magic = false;
                    break;
                   }
                }

                if (magic != true){

                    break;

                }

                if (row_diagonal != row_down_n[0] or row_diagonal_reverse != row_up_n[0] or row_down_n[0] != row_up_n[0]){

                    cout << "\nМатриця не є магічним кубом\n";
                    break;

                }else{

                    cout << "\nМатриця є магічним кубом\n";
                    break;

                }


            }
        
            case 3:{
                int i, j = 0, n = 0;
                bool marker = true; 
                string number_q, number_r;
                vector<string> number_q_v;
                vector<string> number_r_v;

                cout << "Задайте число: ";
                cin >> number_q;

                cout << "Спробуйте вгадати число: ";
                cin >> number_r;


                for (char c : number_q) {
                    number_q_v.push_back(string(1, c)); 
                }

                for (char c : number_r) {
                    number_r_v.push_back(string(1, c));
                }



                
                
                //cout << "number_q_v.size() = " << number_q_v.size() << endl;
                //cout << "number_r_v.size() = " << number_r_v.size() << endl;

                if (number_q_v.size() > number_r_v.size()){

                    n = number_r_v.size();

                }else{

                    n = number_q_v.size();

                }


                for (i = 0; i < n; ++i){

                    if(number_q_v[i] == number_r_v[i]){
                        marker = false;
                        cout << j + 1<< " : " << " [ " << number_q_v[i] << " ] " << " що є "<< i + 1 << " по порядку" << " збігається з " << " [ " << number_r_v[i]<< " ] " << " що є " << i + 1 << " по порядку " << number_q << " - " << number_r << "\n";  
                        j++;
                    }

                }

                break;

                if(marker != false){

                    cout<< "Нуль збігів" << number_q << " - " << number_r;
                    break;
                }


            }

            case 4:{
                int i;
                bool marker = true;
                string text;
                vector<string> text_v;

                cout << "Введіть  дані які треба перевести: ";
                cin >> text;


                for (char c : text) {
                    char upper_c = toupper(c);  
                    if (morse.count(upper_c)) {
                        cout << "\n" << morse[upper_c] << " \n";
                    }else{
                        cout << "? "; 
                    }
                }

                break;
                }
                
            case 5:{

                cout << "\n Удачи!";
                return 0;


            }

            default:
            cout << "\nНевірний вибір спробуйде щераз \n";

        }
    
    
   
    }
 
}