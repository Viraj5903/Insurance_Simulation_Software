#pragma once
#include <iostream>
#include "Client.h"
using namespace std;

class InsuranceAgreement
{
public:
    Client client; // creating client object
    double yearlyFee;
    double risk;
    double accident;
    double insuranceAmount;
    bool isClaimed = false;
    double totalPayout = 0;

    InsuranceAgreement() //Constructor:  Generating random Insurance Agreement
    {
        int random = rand();
        client = Client();
        yearlyFee = (random % (5000 - 1000)) + 1000;
        risk = (random % (101 - 5)) + 5;
        accident = (random % (21 - 5)) + 5;
        insuranceAmount = yearlyFee * accident;
    };
    double GetNetProfit()
    {
        return yearlyFee - totalPayout;
    }
    void nextYearlyFee()
    {
        int Random = rand();
        yearlyFee += Random % (1000 - 100) + 100;
        //insuranceAmount = yearlyFee * accident;
    }
};
