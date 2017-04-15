//
//  PayOffs.cpp
//  Mars
//
//  Created by Matthieu Zandecki on 15/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#include "PayOffs.hpp"

PayOff::PayOff(const double Strike_, const OptionType TheOptionsType_) : Strike(Strike_), TheOptionsType(TheOptionsType_)
{
}

PayOff::PayOff(const double Strike1_, const double Strike2_, const OptionType TheOptionsType_) : Strike(Strike1_), Strike2(Strike2_), TheOptionsType(TheOptionsType_)
{
}

double PayOff::operator()(const double spot) const
{
    switch (TheOptionsType) {
        case call:
            return max(spot - Strike, 0.0);
            break;
            
        case put:
            return max(Strike - spot, 0.0);
            break;
            
            
        case digital:
            return (spot - Strike > 0) ? 1.0 : 0.0;
            break;
            
        case doubleDigital:
            return ((spot > Strike) && (spot < Strike2)) ? 1 : 0;
            break;
            
        default:
            throw("unknow type of option");
            break;
    }
}
