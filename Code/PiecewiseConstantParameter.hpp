//
//  PiecewiseConstantParameter.hpp
//  Mars
//
//  Created by Matthieu Zandecki on 17/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#ifndef PiecewiseConstantParameter_hpp
#define PiecewiseConstantParameter_hpp

#include <stdio.h>
#include "Parameters.hpp"
#include <vector>

using namespace std;

class PiecewiseConstantParameter : public ParametersInner {
    vector<double> Pillars;
    vector<double> Values;
    
public:
    PiecewiseConstantParameter(vector<double> Pillars_, vector<double> Values_);
    virtual ParametersInner* clone() const;
    virtual double Integral(double time1, double time2) const;
    virtual double IntegralSquare(double time1, double time2) const;
    
};


#endif /* PiecewiseConstantParameter_hpp */
