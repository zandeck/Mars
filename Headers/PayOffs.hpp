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
#include <iostream>

using namespace std;

class PayOff {
public:
    PayOff(){};
    virtual double operator()(double Spot) const = 0;
    virtual ~PayOff(){}
};


class PayOffCall : public PayOff {
public:
    PayOffCall(double Strike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffCall(){};
    
private:
    double Strike;
};


class PayOffPut : public PayOff {
public:
    PayOffPut(double Strike);
    virtual double operator()(double Spot) const;
    virtual ~PayOffPut(){}
    
private:
    double Strike;
};



#endif /* PayOffs_hpp */
