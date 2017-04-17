//
//  VanillaOption.cpp
//  Mars
//
//  Created by Matthieu Zandecki on 17/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#include "VanillaOption.hpp"

VanillaOption::VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_) : Expiry(Expiry_), ThePayOff(ThePayOff_)
{
}

double VanillaOption::GetExpiry() const
{
    return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const
{
    return ThePayOff(Spot);
}
