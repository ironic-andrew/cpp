#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

bool marker = true;

void filter(string text){
    bool mark = true;
    string word;
    vector<string> words;
    words.clear();

    string ABC = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    stringstream ss(text);

    while(ss >> word){

        words.push_back(word);

    }
    
    for(int i = 0; i < words.size(); ++i){
        for(int j = 0; j < words[i].size(); ++j){

            char c = words[i][j];

            if (ABC.find(c) == string::npos) {
                
                mark = false;

            } else {
                
                cout << c << "ok\n";
            }

        }
    }

    if(mark){

        for(int i = 0; i < words.size(); ++i){
        
            cout << i + 1 << ") " << words[i] << " - " << words[i][0] << "-" << words[i][words[i].size() - 1] << "\n" ;

        }
        marker = false;

    }else{

        cout << "\nСимволи мають бути латинецею!\n";

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
                marker = true;

                while(marker){

                    cout << "Введіть символи латинецею: ";
                    cin.ignore();
                    getline(cin, text); 

                    if(text == "Back" or text == "back" or text == "B" or text == "b") break;

                    filter(text);
                }


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


