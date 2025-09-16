#include <iostream> 
#include <vector>

int main() {

    int a;
    int b;
    int x1;
    int y1;
    int x2;
    int y2;
    int d1;
    int d2;

    std::cout << "Введіть значення a: ";
    std::cin >> a;
    std::cout << "Введіть значення b: ";
    std::cin >> b;

    
    std::cout << "Введіть значення x1: ";
    std::cin >> x1;
    std::cout << "Введіть значення y1: ";
    std::cin >> y1;

    std::cout << "Введіть значення x2: ";
    std::cin >> x2;
    std::cout << "Введіть значення y2: ";
    std::cin >> y2;

    d1 = (x1 - a) + (y1 - b);
    d2 = (x2 - a) + (y2 - b);

    if (d1 < 0){
       d1 = d1 * -1;
    }

    if (d2 < 0){
       d2 = d2 * -1;
    }

    std::cout << "Відстань до першого будинку: " << d1;
    std::cout << "\nВідстань до другого будинку: " << d2;


return 0;

}