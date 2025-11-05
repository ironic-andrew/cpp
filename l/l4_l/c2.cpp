#include <iostream>
#include <vector>
#include <string>
using namespace std;

class library{
    bool codeError = false;

    struct Book {
        int id;         
        string title;   
    };

    struct Inventory {
        int inventoryNumber;  
        int bookId;

    };

    private:

    vector<Book> books = {
        {1, "Harry Potter"},
        {2, "Lord of the Rings"},
        {3, "1984"}
    };

    
    vector<Inventory> inventory = {
        {1001, 1}, 
        {1002, 2}, 
        {1003, 3}, 
        {1004, 1}  
    };

    public:

    void operator[](int value) {
        codeError = false;
        int index = 0;

        cout << "\nBook";
        for(int i = 0; i < books.size(); i++){
            if(books[i].id == value){
                cout << "\nКнига з номером " << books[i].id << " є: " << books[i].title << "\n";
                cout << "Код помилки - " << codeError;
                index++;
            }
        }
        if (index == 0){
            codeError = true;
            cout << "\nКнига незнайдена\n" << "код помилки - " << codeError << "\n";
        
        }

        index = 0;

        cout << "\nInventory";
        for(int i = 0; i < inventory.size(); i++){
            if(inventory[i].bookId == value){
                cout << "\nКнига з номером " << inventory[i].bookId << " є: " << inventory[i].inventoryNumber << "\n";
                cout << "Код помилки - " << codeError;
                index++;
            }
        }
        if (index == 0){
            codeError = true;
            cout << "\nКнига незнайдена\n" << "код помилки - " << codeError << "\n";
        
        }
    
    };

};

int main() {
    int index;
    string input;
    library t;
    

    cout << "Введіть індекс: \n";
    while (true){
        
        cin >> input;

        try{
            index = stoi(input);
            if(index <= 0){

                cout<< "\nЧисло має бути додатнім!\n";
                continue;
            }
            break;
        }catch(...){

            cout << "\nВведіть число типу int!\n";

        }

        }

        t[index];

    

    return 0;
}