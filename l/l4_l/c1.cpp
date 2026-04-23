#include<iostream>
#include<vector>
using namespace std;


class VectorLong{

private:

    vector<long> v;
    bool codeError;

public:

    VectorLong(){

        
        v = vector<long>(1);
        codeError = false;

    };

    VectorLong(int size){

        v.resize(size);
        codeError = false;

        for(int i = 0;i < v.size(); ++i){

            v[i] = 0;

        }

    };

    VectorLong(int size, bool marker){

        v = vector<long>(size);
        codeError = marker;

    };

    VectorLong(const VectorLong& other){

    v = other.v;
    codeError = other.codeError;

    };

    ~VectorLong(){



    }

        VectorLong operator++(){

        for(int i = 0; i < v.size(); ++i){

            v[i]++;

        }

        return *this;

    };

        VectorLong operator++(int){

        for(int i = 0; i < v.size(); ++i){

            v[i]++;

        }

        return *this;

    };

        VectorLong operator--(){

        for(int i = 0; i < v.size(); ++i){

            v[i]--;

        }

        return *this;

    };

        VectorLong operator--(int){

        for(int i = 0; i < v.size(); ++i){

            v[i]--;

        }

        return *this;

    };

        bool operator!=(int value) const {

            return v.size() != value;

        };

        VectorLong operator ~() const {

            VectorLong s = *this;
            for(int i = 0; i < s.v.size(); ++i){

                s.v[i] = ~s.v[i];

            }

            return s;

        };

        VectorLong operator=(const VectorLong& other){

            v = other.v;
            codeError = other.codeError;

            return *this;

        };

        VectorLong operator+=(const VectorLong& other){

            if(v.size() != other.v.size()){

                codeError = true;
                return *this;

            }
            
            for(int i = 0; i < v.size(); ++i){

                v[i] += other.v[i];

            }

            return *this;

        };

        VectorLong operator-=(const VectorLong& other){

            if(v.size() != other.v.size()){

                codeError = true;
                return *this;

            }
            
            for(int i = 0; i < v.size(); ++i){

                v[i] -= other.v[i];

            }

            return *this;

        };

        VectorLong operator*=(const VectorLong& other){

            if(v.size() != other.v.size()){

                codeError = true;
                return *this;

            }
            
            for(int i = 0; i < v.size(); ++i){

                v[i] *= other.v[i];

            }

            return *this;

        };

        VectorLong operator/=(int value){
            
            for(int i = 0; i < v.size(); ++i){

                v[i] /= value;

            }

            return *this;

        };

        VectorLong operator%=(int value){
            
            for(int i = 0; i < v.size(); ++i){

                v[i] %= value;

            }

            return *this;

        };

        VectorLong operator|=(const VectorLong& other){

            if(v.size() != other.v.size()){

                codeError = true;
                return *this;

            }
            
            for(int i = 0; i < v.size(); ++i){

                v[i] |= other.v[i];

            }

            return *this;

        };

        VectorLong operator^=(const VectorLong& other){

            if(v.size() != other.v.size()){

                codeError = true;
                return *this;

            }
            
            for(int i = 0; i < v.size(); ++i){

                v[i] ^= other.v[i];

            }

            return *this;

        };

        VectorLong operator&=(const VectorLong& other){

            if(v.size() != other.v.size()){

                codeError = true;
                return *this;

            }
            
            for(int i = 0; i < v.size(); ++i){

                v[i] &= other.v[i];

            }

            return *this;

        };

        VectorLong operator+(const VectorLong& other){

            if(v.size() != other.v.size()){

                codeError = true;
                return *this;

            }
            
            for(int i = 0; i < v.size(); ++i){

                v[i] += other.v[i];

            }

            return *this;

        };

        VectorLong operator-(const VectorLong& other){

            if(v.size() != other.v.size()){

                codeError = true;
                return *this;

            }
            
            for(int i = 0; i < v.size(); ++i){

                v[i] -= other.v[i];

            }

            return *this;

        };

        VectorLong operator*(const VectorLong& other){

            if(v.size() != other.v.size()){

                codeError = true;
                return *this;

            }
            
            for(int i = 0; i < v.size(); ++i){

                v[i] *= other.v[i];

            }

            return *this;

        };

        VectorLong operator/(int value){
            
            for(int i = 0; i < v.size(); ++i){

                v[i] /= value;

            }

            return *this;

        };

        VectorLong operator%(int value){
            
            for(int i = 0; i < v.size(); ++i){

                v[i] %= value;

            }

            return *this;

        };

        VectorLong operator|(const VectorLong& other){

            if(v.size() != other.v.size()){

                codeError = true;
                return *this;

            }
            
            for(int i = 0; i < v.size(); ++i){

                v[i] |= other.v[i];

            }

            return *this;

        };

        VectorLong operator^(const VectorLong& other){

            if(v.size() != other.v.size()){

                codeError = true;
                return *this;

            }
            
            for(int i = 0; i < v.size(); ++i){

                v[i] ^= other.v[i];

            }

            return *this;

        };

        VectorLong operator&(const VectorLong& other){

            if(v.size() != other.v.size()){

                codeError = true;
                return *this;

            }
            
            for(int i = 0; i < v.size(); ++i){

                v[i] &= other.v[i];

            }

            return *this;

        };

        VectorLong operator>>(int value){

            for(int i = 0; i < v.size(); ++i){

                v[i] = v[i] >> value;

            }

            return *this;

        };

        VectorLong operator<<(int value){

            for(int i = 0; i < v.size(); ++i){

                v[i] = v[i] << value;

            }

            return *this;

        };

        bool operator==(const VectorLong& other) const {
            return v == other.v && codeError == other.codeError;
        }

        bool operator!=(const VectorLong& other) const {
            return !(*this == other);
        }

        VectorLong operator[](int value){

            for(int i = 0; i < v.size(); ++i){

                if(v[i] == value){

                    codeError = false;
                    return *this;

                }

            }

                codeError = true;
                return *this;

        };

        void* operator new[](size_t size) {
            return malloc(size);
        }

        void operator delete[](void* ptr) noexcept {
            free(ptr);
        }

        VectorLong operator()(int value){

            v.resize(value);
            return *this;

        };

        bool operator>(const VectorLong& other) const{

            return(v.size() > other.v.size());

        };

        bool operator>=(const VectorLong& other) const{

            return(v.size() >= other.v.size());

        };

        bool operator<(const VectorLong& other) const{

            return(v.size() < other.v.size());

        };

        bool operator<=(const VectorLong& other) const{

            return(v.size() <= other.v.size());

        };


    void show(){
        int index = 1;
        cout << "\ncodeError - " << codeError << "\n";
        cout << "Масив: \n";
        for(int i = 0;i < v.size(); ++i){

            cout << index << ": " << v[i] << "\n";
            index ++;
        }

    };


};


int main(){

    cout << "--- 1. Конструктор за замовчуваням ---\n";
    VectorLong t1{};
    t1.show();


    cout << "\n--- 2. Конструктор з параметром size ---\n";
    VectorLong t2(5);
    t2.show();

    cout << "\n--- 3. Конструктор з параметрами size, codeError ---\n";
    VectorLong t3(4, true);
    t3.show();

    cout << "\n--- 4. Конструктор копіювання ---\n";
    VectorLong t4{};
    cout << "\nОригінал: ";
    t3.show();
    t4 = t3;
    cout << "\nКопія: ";
    t4.show();

    cout << "\n--- 5. Перенавантаження ++ ---\n";
    cout << "\nОригінал";
    t3.show();
    cout << "\n++ префіксний: ";
    ++t3;
    t3.show();
    cout << "\n++ потфіксний: ";
    t3++;
    t3.show();
    cout << "\n-- префіксний: ";
    --t3;
    t3.show();
    cout << "\n-- потфіксний: ";
    t3--;
    t3.show();
   
    cout << "\n--- 6. Перенавантаження  ---\n";
    
    if (t2 != 0)
        cout << "\nВектор не порожній\n\n";
    else
        cout << "\nВектор порожній\n\n"; 

    cout << "Масив";
    t2.show();

    cout << "\n--- 7. Перенавантаження  ---\n";
    cout << "\nОригінал";
    t3.show();
    cout << "\n~";
    ~t3;
    t3.show();

    cout << "\n--- 8. Перевантаження = ---\n";
    cout << "\nОригінал: ";
    t3.show();
    t2 = t3;
    cout << "\nКопія: ";
    t2.show();

    cout << "\n--- 9. Перенавантаження += ---\n";
    t3 += t4;
    t3.show();

    cout << "\n--- 10. Перенавантаження -= ---\n";
    t3 -= t4;
    t3.show();

    cout << "\n--- 11. Перенавантаження *= ---\n";
    t3 *= t4;
    t3.show();

    cout << "\n--- 12. Перенавантаження /= ---\n";
    t3 /= 2;
    t3.show();

    cout << "\n--- 13. Перенавантаження %= ---\n";
    t3 %= 2;
    t3.show();

    cout << "\n--- 14. Перенавантаження |= ---\n";
    t3 |= t4;
    t3.show();

    cout << "\n--- 15. Перенавантаження ^= ---\n";
    t3 ^= t4;
    t3.show();

    cout << "\n--- 16. Перенавантаження &= ---\n";
    t3 &= t4;
    t3.show();

    cout << "\n--- 17. Перенавантаження + ---\n";
    t1 = t3 + t4;
    t1.show();

    cout << "\n--- 18. Перенавантаження + ---\n";
    t1 = t3 - t4;
    t1.show();

    cout << "\n--- 19. Перенавантаження + ---\n";
    t1 = t3 * t4;
    t1.show();

    cout << "\n--- 20. Перенавантаження + ---\n";
    t1 = t3/2;
    t1.show();

    cout << "\n--- 21. Перенавантаження + ---\n";
    t1 = t3%2;
    t1.show();

    cout << "\n--- 22. Перенавантаження | ---\n";
    t1 = t3 | t4;
    t1.show();

    cout << "\n--- 23. Перенавантаження ^ ---\n";
    t1 = t3 ^= t4;
    t1.show();

    cout << "\n--- 24. Перенавантаження & ---\n";
    t1 = t3 &= t4;
    t1.show();

    cout << "\n--- 25. Перенавантаження >> ---\n";
    t2 >> 1;
    t2.show();

    cout << "\n--- 26. Перенавантаження << ---\n";
    t2 << 1;
    t2.show();

    cout << "\n--- 27. Перенавантаження == ---\n";
    if(t2 == t3)cout << "\ncodeError - false\n";
    
    else cout << "\ncodeError - true\n";
    

    cout << "\n--- 28. Перенавантаження != ---\n";
    if(t2 != t3)cout << "\ncodeError - false\n";
    
    else cout << "\ncodeError - true\n";


    cout << "\n--- 29. Перенавантаження [] ---\n";
    t1[3];
    t1.show();

    cout << "\n--- 30. Перенавантаження new[] ---\n";
    VectorLong* t5 = new VectorLong[5];

    cout << "\n--- 31. Перенавантаження delete[] ---\n";
    delete[] t5;

    cout << "\n--- 32. Перенавантаження () ---\n";
    t2(5);
    t2.show();

    cout << "\n--- 33. Перенавантаження > ---\n";
    if(t2 > t3)cout << "\ncodeError - false\n";
    
    else cout << "\ncodeError - true\n";

    cout << "\n--- 33. Перенавантаження >= ---\n";
    if(t2 >= t3)cout << "\ncodeError - false\n";
    
    else cout << "\ncodeError - true\n";

    cout << "\n--- 33. Перенавантаження <= ---\n";
    if(t2 < t3)cout << "\ncodeError - false\n";
    
    else cout << "\ncodeError - true\n";

    cout << "\n--- 33. Перенавантаження <= ---\n";
    if(t2 <= t3)cout << "\ncodeError - false\n";
    
    else cout << "\ncodeError - true\n";

    
    return 0;
}













