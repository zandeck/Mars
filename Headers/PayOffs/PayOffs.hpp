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
#include <cmath>

using namespace std;

class PayOff {
public:
    PayOff(){};
    virtual double operator()(double Spot) const = 0;
    virtual PayOff* clone() const = 0;
    virtual ~PayOff(){}
};


class PayOffCall : public PayOff {
public:
    PayOffCall(double Strike_);
    virtual double operator()(double Spot) const;
    virtual PayOff* clone() const;
    virtual ~PayOffCall(){};
    
private:
    double Strike;
};


class PayOffPut : public PayOff {
public:
    PayOffPut(double Strike);
    virtual double operator()(double Spot) const;
    virtual PayOff* clone() const;
    virtual ~PayOffPut(){}
    
private:
    double Strike;
};

class PayOffDoubleDigit : public PayOff
{
public:
    PayOffDoubleDigit(double LowerLevel_, double UpperLevel_);
    virtual double operator()(double Spot) const;
    virtual PayOff* clone() const;
    virtual ~PayOffDoubleDigit(){}
    
private:
    double LowerLevel;
    double UpperLevel;
};

class PayOffPower : public PayOff
{
public:
    PayOffPower(double Strike_, double Alpha_);
    virtual double operator()(double Spot) const;
    virtual PayOff* clone() const;
    virtual ~PayOffPower(){}
    
private:
    double Strike;
    double Alpha;
};

class PayOffDigit : public PayOff
{
public:
    PayOffDigit(double Strike_);
    virtual double operator()(double Spot) const;
    virtual PayOff* clone() const;
    virtual ~PayOffDigit(){}
    
private:
    double Strike;
};

#endif /* PayOffs_hpp */
