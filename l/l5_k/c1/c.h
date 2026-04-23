#ifndef C_H
#define C_H

#include<iostream>
#include<vector>
using namespace std;

class Video{

public:

void add(string name_str, string rezhiser_str, string genre_str, int index);
void show();
void filter_rezhiser();

};


#endif