#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ifstream file("dat7.dat");
    vector<string> text;
    string texti;

    while (file >> texti) {
        text.push_back(texti);
    }
    string t;
    int index;
    bool marker = false;

    while(true){

        cout << "Введіть один з перелічених шифрів: ";
        for(int i = 0; i < text.size(); ++i){
            cout << text[i] << "\n";
        }
        cout << "Ваш вибір: ";
        cin >> t;
        
        for(int i = 0; i < text.size(); ++i){
            if(t == text[i]){
                index = i;
                marker = true;
                break;
            }
        }


        if(marker){
            double qnr, qnk, rnk, fun, u;
            double wnr, wnk, gnk, gold, v;
            double x_i, t_x_i, u_x_i;
            double y_i, t_y_i, u_y_i;
            double z_i, t_z_i, u_z_i;
            string text_i;
            text_i = text[index];

            ifstream file("dat4.dat");
            vector<double> x, t_x, u_x;
            double xi, t_xi, u_xi;

            while (file >> xi >> t_xi >> u_xi) {
                x.push_back(xi);
                t_x.push_back(t_xi);
                u_x.push_back(u_xi);
            }

            ifstream file_y("dat5.dat");
            vector<double> y, t_y, u_y;
            double yi, t_yi, u_yi;

            while (file_y >> yi >> t_yi >> u_yi) {
                y.push_back(yi);
                t_y.push_back(t_yi);
                u_y.push_back(u_yi);
            }

            ifstream file_z("dat6.dat");
            vector<double> z, t_z, u_z;
            double zi, t_zi, u_zi;

            while (file_z >> zi >> t_zi >> u_zi) {
                z.push_back(zi);
                t_z.push_back(t_zi);
                u_z.push_back(u_zi);
            }

            /*
            cout << "x = " << x.size() << "\n";
            cout << "t_x = " << t_x.size() << "\n";
            cout << "u_x = " << u_x.size() << "\n";
            cout << "y = " << y.size() << "\n";
            cout << "t_y = " << t_y.size() << "\n";
            cout << "u_y = " << u_y.size() << "\n";
            cout << "z = " << z.size() << "\n";
            cout << "t_z = " << t_z.size() << "\n";
            cout << "u_z = " << u_z.size() << "\n";
            */

            x_i = x[index];
            t_x_i = t_x[index];
            u_x_i = u_x[index];

            y_i = y[index];
            t_y_i = t_y[index];
            u_y_i = u_y[index];

            z_i = z[index];
            t_z_i = t_z[index];
            u_z_i = u_z[index];


            if(y[index] == 0){
            
                qnr = 1;
            
            }else if(x_i > y_i && (10 * pow(y_i, 4) - x_i) >= 0 && y_i != 0){
            
                qnr = x_i * x_i * sqrt(10 * pow(y_i, 4) - x_i);
            
            }else if(x_i <= y_i && 3.0*x_i > y_i && (10.0*pow(x_i,4) - y_i) >= 0 && y_i != 0){

                qnr = pow(x_i, 3) * log(10.0*pow(x_i,4) - y_i);

            }else if(x_i <= y_i && 3.0 * x_i <= y_i && (pow(y_i, 4) - 2.0 * x_i) >= 0 && y_i != 0){

                qnr = pow(y_i, 2) * (pow(y_i, 4) - 2.0 * x_i);

            }else{

                qnr = 2;

            }

            qnk = 10.5 * (qnr * 2) - 3.75 * (qnr * 2);
            rnk = x_i * qnk + y_i * qnk + z_i * qnk;
            fun = x_i * rnk + rnk * rnk;
            u = fun;

            if(x_i > y_i){

                wnr = t_x_i - u_x_i * u_y_i;

            }else if(x_i <= y_i){

                wnr = t_x_i * t_y_i - t_x_i;

            }

            wnk = 10.5 * wnr * 2 - 3.75 * wnr * 2;
            gnk = x_i * wnk + y_i * wnk + z_i * wnk;
            gold = x_i * gnk + gnk * gnk;
            v = gold * 2;

            cout << "Відповідь: func(" << u << "," << v << "," << text_i << ")";
            break;
        }else{
            cout << "Ви вели невірний шифр!" << '\n';
        }




    }

    /*
    ifstream file("dat4.dat");
    vector<double> x, t_x, u_x;
    double xi, t_xi, u_xi;

    while (file >> xi >> t_xi >> u_xi) {
        x.push_back(xi);
        t_x.push_back(t_xi);
        t_x.push_back(u_xi);
    }
    */

    /*  
    for (int i = 0; i < x.size(); ++i) {
        
        cout << x[i] << "\n";
    }

    for (int i = 0; i < t_x.size(); ++i) {
        
        cout << t_x[i] << "\n";
    }

    for (int i = 0; i < u_x.size(); ++i) {
        
        cout << u_x[i] << "\n";
    }
    */

    return 0;
    }