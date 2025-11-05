#include <iostream>
using namespace std;


class Computer{

    public:
        void show(){

        cout << "Комп'ютер\n";

        };
        string computer_text = "Комп'ютер";
};


class CPU:public Computer{

    private:

    string clock_speed, cores, cache, architecture, cpu;
    

    public:
        void show(){

            cout << computer_text << " - " << "процесор\n";

        };
        string cpu_text = "процесор";

        CPU(){

            clock_speed = "Дані відсутні";
            cores = "Дані відсутні";
            cache = "Дані відсутні";
            architecture = "Дані відсутні";

        };

        CPU(string cpu1){

            cpu = cpu1;
            clock_speed = "3,7 - 4,6 GHz";
            cores = "6";
            cache = "L3 = 32 MB";
            architecture = "x86";

        };

        ~CPU(){

            cpu = "";
            clock_speed = "";
            cores = "";
            cache = "";
            architecture = "";

        };

        void show_result(){

            cout << "Процесор: " << cpu << ":\n";
            cout << "Частота - "  << clock_speed << "\n";
            cout << "Ядра - " << cores << "\n";
            cout << "Кеш - " << cache << "\n";
            cout << "Архітектура - " << architecture << "\n\n";

        };

};


class GPU:public Computer{

    private:

     string clock_speed, vram, bandwidth, memory_bus_width, gpu;

    public:
        void show(){

            cout << computer_text << " - " << "відеокарта\n";

        };
        string gpu_text = "процесор";

        GPU(){

            clock_speed = "Дані відсутні";
            vram = "Дані відсутні";
            bandwidth = "Дані відсутні";
            memory_bus_width = "Дані відсутні";

        };

        GPU(string gpu1){

            gpu = gpu1;
            clock_speed = "1320 MHz";
            vram = "12 GB";
            bandwidth = "360 GB/s";
            memory_bus_width = "192 beat";

        };

        ~GPU(){

            gpu = "";
            clock_speed = "";
            vram = "";
            bandwidth = "";
            memory_bus_width = "";

        };

        void show_result(){

            cout << "Відеокарта: " << gpu << ":\n";
            cout << "Частота - " << clock_speed << "\n";
            cout << "Відео пам'ть - " << vram << "\n";
            cout << "Пропускна здатність - " << bandwidth << "\n";
            cout << "Шина пам'ті - " << memory_bus_width << "\n\n";

        };

};


class Monitor:public Computer{

    private:

        string resolution, matrixType, monitor, brightness, refreshRate;

    public:
        void show(){

            cout << computer_text << " - " << "монітор\n";

        };
        string monitor_text = "монітор";

        Monitor(){

            resolution = "Дані відсутні";   
            brightness = "Дані відсутні";              
            refreshRate = "Дані відсутні";              
            matrixType = "Дані відсутні";

        };


        Monitor(string monitor1){

            monitor = monitor1;
            resolution = "1920x1080";   
            brightness = "250 ніт";              
            refreshRate = "75 Гц";              
            matrixType = "IPS"; 

        };


        ~Monitor(){

            monitor = "";
            resolution = "";   
            brightness = "";              
            refreshRate = "";              
            matrixType = "";

        };


        void show_result(){

            cout << "Монітор: " << monitor << ":\n";
            cout << "Роздільна здатність - " << resolution << "\n";
            cout << "Яскравість - " << brightness << "\n";
            cout << "Частота оновлень - " << refreshRate << "\n";
            cout << "Тип матриці - " << matrixType << "\n\n";

        };

};




int main(){

    Computer t1;
    CPU t1_1;
    GPU t1_2;
    Monitor t1_3;


    t1.show();


    t1_1.show();
    CPU q1("AMD Ryzen 5 5600X");
    q1.show_result();


    t1_2.show();
    GPU q2("rtx 3060");
    q2.show_result();


    t1_3.show();
    Monitor q3("Samsung S27R350");
    q3.show_result();



    return 0;
}