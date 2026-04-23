#include <iostream>
#include "c.h"
#include<vector>
using namespace std;


struct Film{

    string name;
    string rezhiser;
    string genre;
    int year;

};

vector<Film> video;

void Video::add(string name_str, string rezhiser_str, string genre_str, int index){

    Film temp;
    temp.name = name_str;
    temp.rezhiser = rezhiser_str;
    temp.genre = genre_str;
    temp.year = index;

    video.push_back(temp);



};

void Video::show(){

    if(video.size() == 0){
        
        cout<< "\nВи не додали жодного фільму!\n";


    }else{

        cout << "\n";
        for(int i = 0; i < video.size(); i++){

            cout<< i + 1 << ": " << "Назва - " << video[i].name << ", Режисер - "<< video[i].rezhiser << ", Жанр - " << video[i].genre << ", Рік випуску - " << video[i].year << "\n";

        }

    }


};

void Video::filter_rezhiser(){
        
    if(video.size() == 0){
        
        cout<< "\nВи не додали жодного фільму!\n";

    }else{
    
        bool marker = true;

        cout<< "\nВведіть ім'я режесера: ";
        string text;
        cin>> text;
        cout<< "\n";

        for (int j = 0; j < video.size(); ++j){

            if(video[j].rezhiser == text){

                cout<< j + 1 << ": " << "Назва - " << video[j].name << ", Режисер - "<< video[j].rezhiser << ", Жанр - " << video[j].genre << ", Рік випуску - " << video[j].year << "\n";
                marker = false;
            }

        }

        if(marker == true){

            cout << "Не знайдено жодного фільму за участю [" << text << "]!";

        }

    }
    
    

    




};


