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

using namespace std;

class PayOff {
    
public:
    enum OptionType {call, put};
    PayOff(double Strike_, OptionType TheOptionsType_);
    double operator() (double Spot) const;

private:
    double Strike;
    OptionType TheOptionsType;

};

#endif /* PayOffs_hpp */
