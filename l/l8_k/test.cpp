#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void filter(string text){
    string word;
    vector<string> words;

    stringstream ss(text);

    while(ss >> word){

        words.push_back(word);

    }

    for(int i = 0; i < words.size(); ++i){
        
        cout << i + 1 << ") " << words[i] << " - " << words[i][0] << "-" << words[i][words[i].size() - 1] << "\n" ;

    }

};








int main(){

    while(true){

        int choice;

        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Спробувати відфільтрувати\n";
        cout << "2. Вийти\n";
        cin >> choice;

        switch(choice){

            case 1:{
                string text;
                cout << "Введіть символи латинецею: ";
                cin >> text;

                cout << text;

                //filter(text);

                break;
            }


            
            case 2:{

                cout << "\nУдачи!\n";
                return 0;

            }

            default:{

                cout << "\nСпробуйте ще раз\n" ;

            }

        }

    }

    
}


