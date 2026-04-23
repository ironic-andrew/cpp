#include <iostream> 
#include <vector>

int main() {
    int n; 
    int q;

    std::cout << "Введіть значення N: "; 
    std::cin >> n; 
    std::cout << "N = " << n; 

   
    std::vector<int> A(n);

    std::cout << "\nВведіть " << n << " чисел: ";
    
    
    for(int i = 0; i < n; i++) {
        std::cin >> A[i]; 
    }

    std::cout << "Введені числа: ";
    
   

    for(int i = 0; i < n; i++) {
        if(A[i] >= 0){
            ++q;
        }
    }
    
    std::vector<int> S(q);

    q = 0;

    for(int i = 0; i < n; i++) {
        if(A[i] >= 0){
            S[q] = A[i];
            ++q;
        }

    }


    for(int i = 0; i < q; i++) {
        std::cout << S[i] << " ";

    }

    return 0;
}