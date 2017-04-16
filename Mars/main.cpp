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
    double Strike2 = 120;
    double Spot = 90;
    double Vol = 0.2;
    double r = 0.01;
    double NumberOfPaths = 10000;
    double alpha = 2;
    
    PayOff *PayOffOption;
    int optionType = 0;
    
    cout << "Expiry : " << Expiry << endl;
    cout << "Strike : " << Strike << endl;
    cout << "Strike2 : " << Strike2 << endl;
    cout << "Spot : " << Spot << endl;
    cout << "Volatility : " << Vol << endl;
    cout << "Rate : " << r << endl;
    cout << "Number Of Paths : " << NumberOfPaths << endl;
    
    cout << "Which option type do you want to create ? " << endl;
    cout << "(0: call - 1: put - 2: double digit - 3: power - 4 : digit)" << endl;
    
    cin >> optionType;
    
    if (optionType == 0)
        PayOffOption = new PayOffCall(Strike);
    else if (optionType == 1)
        PayOffOption = new PayOffPut(Strike);
    else if (optionType == 2)
        PayOffOption = new PayOffDoubleDigit(Strike, Strike2);
    else if (optionType == 3)
        PayOffOption = new PayOffPower(Strike, alpha);
    else
        PayOffOption = new PayOffDigit(Strike);
    
    start = clock();
    
    double resultPricing = SimpleMonteCarlo(*PayOffOption, Expiry, Spot, Vol, r, NumberOfPaths);
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    
    cout << "Time for pricing the options : " << duration << endl;
    
    cout << "Price of the option call: " << resultPricing << endl;
    
    return 0;
}
