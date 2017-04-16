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

double PayOffCall::operator()(double Spot) const
{
    return max(Spot - Strike, 0.0);
}

double PayOffPut::operator()(double Spot) const
{
    return max(Strike - Spot, 0.0);
}
