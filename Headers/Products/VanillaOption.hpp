//
//  VanillaOption.hpp
//  Mars
//
//  Created by Matthieu Zandecki on 17/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#ifndef VanillaOption_hpp
#define VanillaOption_hpp

#include <stdio.h>
#include "PayOffs.hpp"
#include "PayOffBridge.hpp"

class VanillaOption {
    double Expiry;
    PayOffBridge ThePayOff;
    
public:
    VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_);
    
    double GetExpiry() const;
    double OptionPayOff(double Spot) const;
};

#endif /* VanillaOption_hpp */
