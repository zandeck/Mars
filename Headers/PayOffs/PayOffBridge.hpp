//
//  PayOffBridge.hpp
//  Mars
//
//  Created by Matthieu Zandecki on 17/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#ifndef PayOffBridge_hpp
#define PayOffBridge_hpp

#include <stdio.h>
#include "PayOffs.hpp"


class PayOffBridge {
    PayOff* thePayOffPtr;
    
public:
    PayOffBridge(const PayOffBridge& original);
    PayOffBridge(const PayOff& innerPayOff);
    
    inline double operator()(double Spot) const;
    PayOffBridge& operator=(const PayOffBridge& original);
    ~PayOffBridge();
};

inline double PayOffBridge::operator()(double Spot) const
{
    return thePayOffPtr->operator()(Spot);
}

#endif /* PayOffBridge_hpp */
