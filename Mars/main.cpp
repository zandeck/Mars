//
//  main.cpp
//  Mars
//
//  Created by Matthieu Zandecki on 15/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#include <iostream>
#include "MonteCarlo.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    double Expiry = 1;
    double Strike = 100;
    double Spot = 90;
    double Vol = 0.2;
    double r = 0.01;
    double NumberOfPaths = 100;
    
    cout << "Expiry : " << Expiry << endl;
    cout << "Strike : " << Strike << endl;
    cout << "Spot : " << Spot << endl;
    cout << "Volatility : " << Vol << endl;
    cout << "Rate : " << r << endl;
    cout << "Number Of Paths : " << NumberOfPaths << endl;
    
    double result = SimpleMonteCarlo(Expiry, Strike, Spot, Vol, r, NumberOfPaths);
    
    cout << "Price of the option : " << result << endl;
    
    return 0;
}
