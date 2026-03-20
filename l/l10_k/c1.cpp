#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;


class complex_c{

    private:

        struct complex_s
        {
        
        float f_n;
        string symb;
        float s_n;
        string i_symb;

        };

        
        vector<complex_s> c;
        float f_n_i, s_n_i;
        string symb_i, i_symb_i;

    public:

        void start_c()
        {

            ifstream file_c("complex.txt");
            while (file_c >> f_n_i >> symb_i >> s_n_i >> i_symb_i) {
                complex_s com;
                com.f_n = f_n_i; 
                com.symb = symb_i;
                com.s_n = s_n_i;
                com.i_symb = i_symb_i;
                
                c.push_back(com);

            }

            cout << "Комлексні числа: " << endl;

            for(int i = 0; i < c.size(); ++i){

                cout << i + 1 << ") " << c[i].f_n << " " << c[i].symb << " " << c[i].s_n << c[i].i_symb << endl ;

            }

            file_c.close();
        };


};

class fraction_f{

    private:

        struct fraction_s
        {
            
            float f_n;
            string symb;
            float s_n;

        };

        vector<fraction_s> f;
        float f_n_i, s_n_i;
        string symb_i;

    public:

        void start_f()
        {

            ifstream file_f("fraction.txt");
            while (file_f >> f_n_i >> symb_i >> s_n_i) {
                fraction_s fra;
                fra.f_n = f_n_i; 
                fra.symb = symb_i;
                fra.s_n = s_n_i;
                
                
                f.push_back(fra);

            }

            cout << "Фракціоні числа числа: " << endl;

            for(int i = 0; i < f.size(); ++i){

                cout << i + 1 << ") " << f[i].f_n << f[i].symb << f[i].s_n  << endl ;

            }
            file_f.close();
        };




};

class vector_v{

    private:
        int count = 0, i;
        float n_i;


    public:

        void start_v()
        {
            ifstream file_v("vector.txt");
            while (file_v >> n_i) {

                count ++;
                
            }


            i = 0;
            float* arr = new float[count];
            file_v.clear();
            file_v.seekg(0);

            for(int i = 0; i < count; ++i){

                file_v >> arr[i];

            }


            cout << "Векторні числа: " << endl;
            for(int j = 0;j < count; ++j){

                cout << j + 1 << ") " << arr[j] << endl; 

            }

            for (int i = 0; i < n; i++) {
                delete[] arr[i];
            }
            delete[] arr;

            file_v.close();
        };




};

class matrix_m{

    private:
        int n, m, count_n = 0, count_m = 0, i;
        float n_i;
        string line;

    public:

        void start_m(){

            ifstream file_m("matrix.txt");
            while (getline(file_m, line)){

                count_n++;

            }

            file_m.clear();
            file_m.seekg(0);

            istringstream numb(line);
            while (numb >> n_i){

                count_m++;

            }

            n = count_n;
            m = count_m;

            float** arr = new float*[n];
            for (int i = 0; i < n; i++) {
                arr[i] = new float[m];
            }

            i = 0;
            while (getline(file_m, line)) {
                istringstream iss(line);
                for (int j = 0; j < m; j++) {
                    iss >> arr[i][j];
                }
                i++;
            }

            cout << "Числа матриці: " << endl;

            for(i = 0;i < n; ++i){
                for(int j = 0;j < m; ++j){

                    cout << arr[i][j] << " ";

                }
                cout << endl;

            }

            for (int i = 0; i < n; i++) {
                delete[] arr[i];
            }
            delete[] arr;

            file_m.close();
        };
        




};

class 

int main(){

    complex_c c;
    fraction_f f;
    vector_v v;
    matrix_m m;
    
    c.start_c();
    f.start_f();
    v.start_v();
    m.start_m();


    return 0;
}