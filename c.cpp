#include <iostream>
#include <vector>
using namespace std;

int main(){
    int i, j, k = 1, n, m, f = 1, value;

/*
vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
                      };
*/

    cout << "Введіть довжину: ";
    cin >> n;
    cout << "Введіть ширину: ";
    cin >> m;

    vector<vector<int>> A (n, vector<int>(m));

    cout << "\nВведи числа: \n";

    for (i = 0; i < n; ++i){
        for (j = 0; j < m; ++j){
            cout << f <<" : ";
            cin >> value;
            A[i][j] = value;
            f++;
        }


    }

    for (i = 0; i < n; ++i){
        for (j = 0; j < m; ++j){
            k *= A[i][j];


        }


    }

    cout << "Відповідь: " <<k;



    return 0;
}