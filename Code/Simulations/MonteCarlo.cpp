//
//  MonteCarlo.cpp
//  Mars
//
//  Created by Matthieu Zandecki on 15/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#include "MonteCarlo.hpp"

double SimpleMonteCarlo(const VanillaOption& TheOption,
                        double Spot,
                        const ParametersConstant& Vol,
                        const ParametersConstant& r,
                        unsigned long NumberOfPaths)
{
    double Expiry = TheOption.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;
    
    double movedSpot = Spot * exp(r.Integral(0, Expiry) + itoCorrection);
    double thisSpot;
    double runningSum = 0;
    
    for (unsigned long i = 0; i < NumberOfPaths; i++) {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        
        double thisPayoff = TheOption.OptionPayOff(thisSpot);
        runningSum += thisPayoff;
    }
    
    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r.Integral(0, Expiry) * Expiry);
    
    return mean;
}
