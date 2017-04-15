//
//  PayOffs.hpp
//  Mars
//
//  Created by Matthieu Zandecki on 15/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#ifndef PayOffs_hpp
#define PayOffs_hpp

#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

class PayOff {
    
public:
    enum OptionType {call, put, digital, doubleDigital};
    PayOff(const double Strike_, const OptionType TheOptionsType_);
    PayOff(const double Strike1_, const double Strike2_, const OptionType TheOptionsType_);
    double operator() (const double Spot) const;

private:
    double Strike, Strike2;
    OptionType TheOptionsType;

};

#endif /* PayOffs_hpp */
