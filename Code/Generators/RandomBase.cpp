//
//  RandomBase.cpp
//  Mars
//
//  Created by Matthieu Zandecki on 18/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#include "RandomBase.hpp"

using namespace std;

void RandomBase::GetGaussians(MJArray &variates)
{
    GetUniforms(variates);
    
    for (unsigned long i = 0; i < Dimensionality; i++) {
        double x = variates[i];
        variates[i] = InverseCumulativeNormal(x);
    }
}

void RandomBase::ResetDimensionality(unsigned long NeWDimensionality)
{
    Dimensionality = NeWDimensionality;
}

RandomBase::RandomBase(unsigned long Dimensionality_) : Dimensionality(Dimensionality_)
{
    
}
