#include <iostream> 


int main() {
    int b; 
    int d;
    int a; 
    int c;
    int s;


    std::cout << "Введіть значення b: "; 
    std::cin >> b; 
    std::cout << "Введіть значення d: "; 
    std::cin >> d; 
    std::cout << "Введіть значення a: "; 
    std::cin >> a; 
    std::cout << "Введіть значення c: "; 
    std::cin >> c; 


    s = ((b << 11) + b) + ((d * 15 + 12 * a) >> 11) - c * 100 + ((d << 6) + (d << 5) + (d << 3));
    // s = 2049 * b + (d * 15 + 12 * a)/2048 - c * 100 + d * 104;


    std::cout << "Відповідь: " << s ;






}