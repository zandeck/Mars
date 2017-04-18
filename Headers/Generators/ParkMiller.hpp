//
//  ParkMiller.hpp
//  Mars
//
//  Created by Matthieu Zandecki on 18/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#ifndef ParkMiller_hpp
#define ParkMiller_hpp

#include <stdio.h>
#include "RandomBase.hpp"

class ParkMiller {
    long Seed;
    
public:
    ParkMiller(long Seed = 1);
    
    long GetOneRandomInteger();
    void SetSeed(long Seed);
    
    static unsigned long Max();
    static unsigned long Min();
};

class RandomParkMiller : public RandomBase {
    ParkMiller InnerGenerator;
    unsigned long InitialSeed;
    double Reciprocal;
    
public:
    RandomParkMiller(unsigned long Dimensionality, unsigned long Seed = 1);
    virtual RandomBase* clone() const;
    virtual void GetUniforms(MJArray& variates);
    virtual void Skip(unsigned long numberOfPaths);
    virtual void SetSeed(unsigned long Seed);
    virtual void Reset();
    virtual void ResetDimensionality(unsigned long newDimensionality);
};

#endif /* ParkMiller_hpp */
