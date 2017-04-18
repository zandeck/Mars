//
//  MonteCarlo.cpp
//  Mars
//
//  Created by Matthieu Zandecki on 15/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#include "MonteCarlo.hpp"

void SimpleMonteCarlo(const VanillaOption& TheOption,
                        double Spot,
                        const ParametersConstant& Vol,
                        const ParametersConstant& r,
                        unsigned long NumberOfPaths,
                        StatisticsMC& gatherer)
{
    double Expiry = TheOption.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;
    
    double movedSpot = Spot * exp(r.Integral(0, Expiry) + itoCorrection);
    double discounting = exp(-r.Integral(0, Expiry));
    double thisSpot;
    
    for (unsigned long i = 0; i < NumberOfPaths; i++) {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        
        double thisPayoff = TheOption.OptionPayOff(thisSpot);
        gatherer.DumpOneResult(thisPayoff * discounting);
    }
}
