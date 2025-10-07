#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int pow_f(int n, int i){
    return pow(i, n);
}

double sqrt_f(int i){
    return sqrt(i);
}

int sixten_to_ten(string x){
    return stoi(x, nullptr, 16);
}


int main(){
vector<int> numbers;
vector<string> text = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

int n, i, value;

cout << "Введіть значення n: ";
cin >> n;

cout<< "Введіть числа: \n";

for (i = 0; i < n; ++i){

    cout << i + 1 << " : ";
    cin >> value;
    numbers.push_back(value);

}
//Піднесення до степення n
cout << "\n Піднесення до степення n = " << n << "\n";
for (i = 0; i < n; ++i){

    cout << i + 1<< " : " << pow_f(n, numbers[i])<< "\n";

}
// -+

//Корінь від числа
cout << "\n Корінь від числа"<< "\n";
for (i = 0; i < n; ++i){

 cout << i + 1 << " : " << sqrt_f(numbers[i]) << "\n";  

}
// -++

//Функція з перетворення шіснацяткової системи обчислення в десяткову

cout << "'0' '1' '2' '3' '4' '5' '6' '7' '8' '9' 'A' 'B' 'C' 'D' 'E' 'F' - Переводячи в десяткову це буде: \n";
for (i = 0; i < text.size(); ++i){

    cout << "'" << sixten_to_ten(text[i]) << "' ";

}
// -+++


return 0;
}












