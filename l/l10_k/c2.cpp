#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class text{

    private:
        string s;
        int index;

    public:

        void getline_reverse(string text){

            index = text.size();

            for(int i = 0; i < index; i++){
                
                s.push_back(text[index - 1 - i]);
                
            }
            
            cout << "Реверснутий рядок: " << endl;
            cout << s; 

        };

};

class convert{

    private:
        vector<string> ones = {"","один","два","три","чотири","п’ять","шість","сім","вісім","дев’ять"};
        vector<string> teens = {"десять","одинадцять","дванадцять","тринадцять","чотирнадцять","п’ятнадцять","шістнадцять","сімнадцять","вісімнадцять","дев’ятнадцять"};
        vector<string> tens = {"","десять","двадцять","тридцять","сорок","п’ятдесят","шістдесят","сімдесят","вісімдесят","дев’яносто"};
        vector<string> hundreds = {"","сто","двісті","триста","чотириста","п’ятсот","шістсот","сімсот","вісімсот","дев’ятсот"};
        string t1, text;
        string f_t, s_t;
        int f_t_i, s_t_i, rem;
        string result_f = "";
        string result_s = "";

    public:
        void convert_in_text(){


            while(true){
                cout << "Введіть цифри: " << endl;
                getline(cin, text);

                if(text == "Back" or text == "back" or text == "B" or text == "b") break;

                stringstream t1(text);

                getline(t1, f_t, ',');
                getline(t1, s_t, ',');

                if(f_t != "" and s_t != ""){

                    try{

                        f_t_i = stoi(f_t);
                        s_t_i = stoi(s_t);
                        break;

                    }catch(...){

                        cout << "Дані введені невірно!" << endl;

                    }

                }else if(f_t != "" and s_t == ""){

                    try{

                        f_t_i = stoi(f_t);
                        break;

                    }catch(...){

                        cout << "Дані введені невірно!" << endl;

                    }

                    cout << "Ви невели мілілітри!" << endl;

                }else if(f_t == "" and s_t != ""){

                    try{

                        s_t_i = stoi(s_t);
                        break;

                    }catch(...){

                        cout << "Дані введені невірно!" << endl;

                    }

                    cout << "Ви невели літри!" << endl;

                }else{

                    cout << "Дані введені некоректно!" << endl;

                }

            }


            result_f += hundreds[f_t_i / 100] + " ";        
            rem = f_t_i % 100;

            if(rem < 10){
                result_f += ones[rem];                  
            }else if(rem < 20){
                result_f += teens[rem - 10];           
            }else{
                result_f += tens[rem / 10] + " " + ones[rem % 10]; 
            }

            result_s += hundreds[s_t_i / 100] + " ";        
            rem = s_t_i % 100;

            if(rem < 10){
                result_s += ones[rem];                  
            }else if(rem < 20){
                result_s += teens[rem - 10];           
            }else{
                result_s += tens[rem / 10] + " " + ones[rem % 10]; 
            }


            cout << "Літрів - " << result_f << " мілілітрів - " << result_s << endl;

        };
        

};




int main(){

    text t;
    convert c;
    string text;

    cout << "Введіть текст: " << endl;
    getline(cin, text);

    t.getline_reverse(text);    
    cout << endl;

    c.convert_in_text();

    return 0;
}


