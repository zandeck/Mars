//
//  Random.cpp
//  Mars
//
//  Created by Matthieu Zandecki on 15/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#include "Random.hpp"

#if !defined(_MSC_VER)
using namespace std;
#endif

double GetOneGaussianBySummation()
{
    double resultat;
    
    for (unsigned long j = 0; j < 12; j ++)
        resultat += rand()/static_cast<double>(RAND_MAX);
    
    resultat -= 6.0;
    
    return resultat;
}



double GetOneGaussianByBoxMuller()
{
    double x, y, result, sizeSquared;
    
    do{
        x = 2.0 * rand() / static_cast<double>(RAND_MAX)-1;
        y = 2.0 * rand() / static_cast<double>(RAND_MAX)-1;
        sizeSquared = x * x + y * y;
        
    } while (sizeSquared >= 1.0);
    
    result = x * sqrt(-2 * log(sizeSquared) / sizeSquared);
    
    return result;
}
