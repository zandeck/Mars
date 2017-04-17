//
//  VanillaOption.cpp
//  Mars
//
//  Created by Matthieu Zandecki on 17/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#include "VanillaOption.hpp"

VanillaOption::VanillaOption(PayOff& ThePayOff_, double Expiry_) : Expiry(Expiry_)
{
    ThePayOff = ThePayOff_.clone();
}

VanillaOption::VanillaOption(const VanillaOption& original)
{
    Expiry = original.Expiry;
    ThePayOff = original.ThePayOff->clone();
}

VanillaOption& VanillaOption::operator=(const VanillaOption &original)
{
    if (this != &original)
    {
        Expiry = original.GetExpiry();
        delete ThePayOff;
        ThePayOff = original.ThePayOff->clone();
    }
    return *this;
}

VanillaOption::~VanillaOption()
{
    delete ThePayOff;
}

double VanillaOption::GetExpiry() const
{
    return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const
{
    return (*ThePayOff)(Spot);
}
