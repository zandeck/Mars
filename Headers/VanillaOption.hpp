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

class VanillaOption {
    double Expiry;
    PayOff* ThePayOff;
    
public:
    VanillaOption(PayOff& ThePayOff_, double Expiry_);
    VanillaOption(const VanillaOption& original);
    VanillaOption& operator=(const VanillaOption& original);
    ~VanillaOption();
    
    double GetExpiry() const;
    double OptionPayOff(double Spot) const;
};

#endif /* VanillaOption_hpp */
