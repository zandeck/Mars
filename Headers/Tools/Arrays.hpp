//
//  Arrays.hpp
//  Mars
//
//  Created by Matthieu Zandecki on 18/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#ifndef Arrays_hpp
#define Arrays_hpp

#ifdef USE_VAL_ARRAY

#include <valarray>

typedef std::valarray<double> MJArray;

#else
#include <stdio.h>
#include <algorithm>
#include <numeric>

class MJArray {
    double* ValuesPtr;
    double* EndPtr;
    unsigned long Size;
    unsigned long Capacity;
    
public:
    explicit MJArray(unsigned long size = 0);
    MJArray(const MJArray& original);
    
    ~MJArray();
    
    MJArray& operator=(const MJArray& original);
    MJArray& operator=(const double& val);
    
    MJArray& operator+=(const MJArray& operand);
    MJArray& operator-=(const MJArray& operand);
    MJArray& operator/=(const MJArray& operand);
    MJArray& operator*=(const MJArray& operand);
    MJArray& operator+=(const double& operand);
    MJArray& operator-=(const double& operand);
    MJArray& operator/=(const double& operand);
    MJArray& operator*=(const double& operand);
    
    MJArray apply(double f(double)) const;
    
    inline double operator[](unsigned long i) const;
    inline double& operator[](unsigned long i);
    
    inline unsigned long size() const;
    
    void resize(unsigned long newSize);
    
    double sum() const;
    double min() const;
    double max() const;
};

inline double MJArray::operator[](unsigned long i) const
{
#ifdef RANGE_CHECKING
    if (i >= Size) {
        throw("Index out of bounds");
    }
#endif
    
    return ValuesPtr[i];
}

inline double& MJArray::operator[](unsigned long i)
{
#ifdef RANGE_CHECKING
    if (i >= Size) {
        throw("Index out of bounds");
    }
#endif
    return ValuesPtr[i];
}

inline unsigned long MJArray::size() const
{
    return Size;
}

#endif
#endif /* Arrays_hpp */
