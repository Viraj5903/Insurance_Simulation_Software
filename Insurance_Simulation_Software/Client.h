#pragma once
#include <iostream>
#include <vector>
#include "Person.h"
using namespace std;

class Client : public Person
{
private:
    string occupation;

public:
    Client()  //Constructor
    {
        vector<string>names;
        names = { "Viraj","Rohan","Dil","Aryan","Harsh","Manpreet","Harsharan","Payal","Hetul","Manik","Seemant" };
        int random = rand() % names.size();
        name = names[random];
    }
};