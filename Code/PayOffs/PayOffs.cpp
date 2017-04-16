//
//  PayOffs.cpp
//  Mars
//
//  Created by Matthieu Zandecki on 15/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#include "PayOffs.hpp"

PayOffCall::PayOffCall(double Strike_) : Strike(Strike_)
{
}

PayOffPut::PayOffPut(double Strike_) : Strike(Strike_)
{
}

PayOffDoubleDigit::PayOffDoubleDigit(double LowerLevel_, double UpperLevel_) : LowerLevel(LowerLevel_), UpperLevel(UpperLevel_)
{
}

PayOffPower::PayOffPower(double Strike_, double Alpha_) : Strike(Strike_), Alpha(Alpha_)
{
}

PayOffDigit::PayOffDigit(double Strike_) : Strike(Strike_)
{
}

double PayOffCall::operator()(double Spot) const
{
    return max(Spot - Strike, 0.0);
}

double PayOffPut::operator()(double Spot) const
{
    return max(Strike - Spot, 0.0);
}

double PayOffDoubleDigit::operator()(double Spot) const
{
    return ((LowerLevel < Spot) && (Spot < UpperLevel)) ? 1 : 0;
}

double PayOffPower::operator()(double Spot) const
{
    double p = pow(Spot, Alpha) - Strike;
    return max(p, 0.0);
}

double PayOffDigit::operator()(double Spot) const
{
    return (Spot > Strike) ? 1 : 0;
}
