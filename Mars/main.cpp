//
//  main.cpp
//  Mars
//
//  Created by Matthieu Zandecki on 15/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#include <iostream>
#include "MonteCarlo.hpp"
#include <ctime>

using namespace std;

int main(int argc, const char * argv[]) {
    
    clock_t start;
    double duration;
    
    double Expiry = 1;
    double Strike = 100;
    double Spot = 90;
    double Vol = 0.2;
    double r = 0.01;
    double NumberOfPaths = 10000;
    
    PayOff *PayOffOption;
    int optionType = 0;
    
    cout << "Expiry : " << Expiry << endl;
    cout << "Strike : " << Strike << endl;
    cout << "Spot : " << Spot << endl;
    cout << "Volatility : " << Vol << endl;
    cout << "Rate : " << r << endl;
    cout << "Number Of Paths : " << NumberOfPaths << endl;
    
    cout << "Which option type do you want to create ? " << endl;
    cout << "(0: call - 1: put)" << endl;
    
    cin >> optionType;
    
    if (optionType == 0)
        PayOffOption = new PayOffCall(Strike);
    else
        PayOffOption = new PayOffPut(Strike);
    
    start = clock();
    
    double resultPricing = SimpleMonteCarlo(*PayOffOption, Expiry, Spot, Vol, r, NumberOfPaths);
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    
    cout << "Time for pricing the options : " << duration << endl;
    
    cout << "Price of the option call: " << resultPricing << endl;
    
    return 0;
}
