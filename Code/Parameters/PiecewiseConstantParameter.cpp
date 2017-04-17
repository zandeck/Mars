//
//  PiecewiseConstantParameter.cpp
//  Mars
//
//  Created by Matthieu Zandecki on 17/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#include "PiecewiseConstantParameter.hpp"

PiecewiseConstantParameter::PiecewiseConstantParameter(vector<double> Pillars_, vector<double> Values_) : Pillars(Pillars_), Values(Values_)
{
    
}

ParametersInner* PiecewiseConstantParameter::clone() const
{
    return new PiecewiseConstantParameter(*this);
}

double PiecewiseConstantParameter::Integral(double time1, double time2) const
{
    double i1 = 0;
    double i2 = 0;
    int i = 0;
    size_t n = Pillars.size();
    
    while (Pillars[i+1] <= time1) {
        if ((i + 1) != n)
            i1 += (Pillars[i+1] - Pillars[i]) * Values[i];
        else
            break;
        i++;
    }
    
    i2 = i1;
    i1 += (time1 - Pillars[i]) * Values[i];
    
    while (Pillars[i+1] <= time2) {
        if ((i + 1) != n)
            i2 += (Pillars[i+1] - Pillars[i]) * Values[i];
        else
            break;
        i++;
    }
    
    i2 += (time2 - Pillars[i]) * Values[i];
    
    return i2 - i1;
}

double PiecewiseConstantParameter::IntegralSquare(double time1, double time2) const
{
    double i1 = 0;
    double i2 = 0;
    int i = 0;
    size_t n = Pillars.size();
    
    while (Pillars[i+1] <= time1) {
        if ((i + 1) != n)
            i1 += (Pillars[i+1] - Pillars[i]) * Values[i] * Values[i];
        else
            break;
        i++;
    }
    
    i2 = i1;
    i1 += (time1 - Pillars[i]) * Values[i] * Values[i];
    
    while (Pillars[i+1] <= time2) {
        if ((i + 1) != n)
            i2 += (Pillars[i+1] - Pillars[i]) * Values[i] * Values[i];
        else
            break;
        i++;
    }
    
    i2 += (time2 - Pillars[i]) * Values[i] * Values[i];
    
    return i2 - i1;
}


