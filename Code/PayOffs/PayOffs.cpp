//
//  PayOffs.cpp
//  Mars
//
//  Created by Matthieu Zandecki on 15/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#include "PayOffs.hpp"

PayOff::PayOff(double Strike_, OptionType TheOptionsType_) : Strike(Strike_), TheOptionsType(TheOptionsType_)
{

}

double PayOff::operator()(double spot) const
{
    switch (TheOptionsType) {
        case call:
            return max(spot - Strike, 0.0);
            break;
            
        case put:
            return max(Strike - spot, 0.0);
            break;
            
        default:
            throw("unknow type of option");
            break;
    }
}
