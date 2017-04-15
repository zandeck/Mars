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
    double Strike2 = 110;
    double Spot = 90;
    double Vol = 0.2;
    double r = 0.01;
    double NumberOfPaths = 10000;
    
    PayOff callPayOff(Strike, PayOff::call);
    PayOff putPayOff(Strike, PayOff::put);
    PayOff digitalPayOff(Strike, PayOff::digital);
    PayOff doubleDigitalPayOff(Strike, Strike2, PayOff::doubleDigital);
    
    cout << "Expiry : " << Expiry << endl;
    cout << "Strike : " << Strike << endl;
    cout << "Spot : " << Spot << endl;
    cout << "Volatility : " << Vol << endl;
    cout << "Rate : " << r << endl;
    cout << "Number Of Paths : " << NumberOfPaths << endl;
    
    start = clock();
    
    double resultCall = SimpleMonteCarlo(callPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
    double resultPut = SimpleMonteCarlo(putPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
    double resultDigital = SimpleMonteCarlo(digitalPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
    double resultDoubleDigital = SimpleMonteCarlo(doubleDigitalPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
    
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    
    cout << "Time for pricing the options : " << duration << endl;
    
    cout << "Price of the option call: " << resultCall << endl;
    cout << "Price of the option put: " << resultPut << endl;
    cout << "Price of the option digital: " << resultDigital << endl;
    cout << "Price of the option double digital: " << resultDoubleDigital << endl;
    
    return 0;
}
