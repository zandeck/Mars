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
    // double alpha = 2;
    
    
    cout << "Expiry : " << Expiry << endl;
    cout << "Strike : " << Strike << endl;
    cout << "Strike2 : " << Strike2 << endl;
    cout << "Spot : " << Spot << endl;
    cout << "Volatility : " << Vol << endl;
    cout << "Rate : " << r << endl;
    cout << "Number Of Paths : " << NumberOfPaths << endl;
    
    
    PayOffCall thePayOffCall(Strike);
    
    VanillaOption theCall(thePayOffCall, Expiry);
    
    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);
    
    RandomParkMiller generator(1);
    AntiThetic GenTwo(generator);
    
    start = clock();
    
    SimpleMonteCarlo(theCall, Spot, Vol, r, NumberOfPaths, gathererTwo, GenTwo);
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    
    cout << "Time for pricing the options : " << duration << endl;
    
    vector<vector<double> > results = gathererTwo.GetResultsSoFar();
    
    for (unsigned long i = 0; i < results.size(); i++) {
        for (unsigned long j = 0; j < results[i].size(); j++) {
            cout << results[i][j] << ' ';
        }
        cout << endl;
    }
    
    
    return 0;
}
