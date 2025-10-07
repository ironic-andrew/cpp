#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

int n, f, value, i, a, s;

cout << "Введіть значення n: ";
cin >> n;

vector<int> numbers;
vector<int> numbersmorethenthree;
vector<int> numbersreverse;

for (i = 0; i < n; ++i){
    
    cout << "Введіть число " << i+1 <<" : ";
    cin >> value ;

    numbers.push_back(value);

}


//Числа > 3
for (i = 0; i < n; ++i){

    if (numbers[i] > 3) {

        numbersmorethenthree.push_back(numbers[i]);

    }

}


if (numbersmorethenthree.size() > 0){

cout << "Числа більше 3: \n";

for (i = 0; i < numbersmorethenthree.size(); ++i){

    cout << i+1 << " : " << numbersmorethenthree[i] << "\n";


    }
}

else{

    cout << "Чисeл більше 3: немає";

}
// -+

// Добуток чисел після найбільшого за модулем
a = 0;
for (i = 0; i < n; ++i){

    

    if (abs(numbers[i]) > a){
        a = numbers[i];
        s = i + 1;
    }


}
a = 1;
for (i = s; i < n; ++i){

    a *= numbers[i];

}

cout << "\nДобуток чисел після найбільшого за модулем: " << a;
// -++

// reverse масив

for (i = 0; i < n; ++i){

    numbersreverse.push_back(numbers[i]);

}


sort(numbersreverse.begin(), numbersreverse.end());

cout << "\n\nReverse масив: \n";
for (i = 0; i < n; ++i){

    cout << i + 1 << " : " << numbersreverse[i] << "\n";

}
// -+++

return 0;

}





