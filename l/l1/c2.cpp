#include <iostream> 
#include <vector>

int main() {

    int t;
    int f = -1;
    int g = -100;
    int gg = -1; 

    std::vector<int> A = {1, 2, -2, -5, 8, -9, 4};
    int count = A.size();

    std::cout << "Введіть значення T: ";
    std::cin >> t;

    for (int i = 0; i < count; ++i){
        if (A[i] == t ){
            f = i;
            break;
        }
    }

    if (f != -1){
    for (int i = 0; i < f; ++i){

        if (A[i] > g && A[i] < 0){
                g = A[i];
                gg = i;
            }
    }
}

    for (int i = 0; i < count; ++i){
        std::cout << A[i] << " ";
    }

   if (gg != -1) {
        std::cout << "\n Номер найбільшого від'ємного числа до першого значення " << t << " = "<< gg + 1;
    } else {
        std::cout << "\nВід'ємні числа не знайдені або T не знайдено.";
    }

return 0;

}

