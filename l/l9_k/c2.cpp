#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Node {  
    string data;  
    Node* next;  
};

class datatype{

    public:

        

        bool isInt(const string& s) {
            int x;
            stringstream ss(s);
            return (ss >> x) && ss.eof();
        };

        bool isFloat(const string& s) {
            float x;
            stringstream ss(s);
            return (ss >> x) && ss.eof();
        };

        void add(Node*& head, const string& value) {
            Node* newNode = new Node{value, nullptr};

            if (head == nullptr) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void print(Node* head) {
            Node* temp = head;

            while (temp != nullptr) {
                string val = temp->data;

                if (isInt(val)) cout << val << " -> int\n";
                else if (isFloat(val)) cout << val << " -> float/double\n";
                else cout << val << " -> string\n";

                temp = temp->next;
            }
        }

        /*
        void check(string& text) {  
            if (isInt(text)) cout << text << " – int\n";
            else if (isFloat(text)) cout << text << " – float/double\n";
            else cout << text << " – string\n";
        };
        */

};

int main(){
    datatype d;

    Node* head = nullptr;
    string input;

    cout << "Вводь дані (exit щоб зупинити):\n";

    while (true) {
        cin >> input;
        if (input == "exit") break;

        d.add(head, input);
    }

    cout << "\nВміст списку:\n";
    d.print(head);

    return 0;
}
