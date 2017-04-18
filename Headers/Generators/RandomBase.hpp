//
//  RandomBase.hpp
//  Mars
//
//  Created by Matthieu Zandecki on 18/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#ifndef RandomBase_hpp
#define RandomBase_hpp

#include <stdio.h>
#include "Arrays.hpp"
#include <cstdlib>
#include "Normals.hpp"

class RandomBase {
    unsigned long Dimensionality;
    
public:
    RandomBase(unsigned long Dimensionality);
    
    inline unsigned long GetDimensionality() const;
    
    virtual RandomBase* clone() const = 0;
    virtual void GetUniforms(MJArray& variates) = 0;
    virtual void Skip(unsigned long numberOfPaths) = 0;
    virtual void SetSeed(unsigned long Seed) = 0;
    virtual void Reset() = 0;
    
    virtual void GetGaussians(MJArray& variates);
    virtual void ResetDimensionality(unsigned long NeWDimensionality);
    virtual ~RandomBase(){}
};

unsigned long RandomBase::GetDimensionality() const
{
    return Dimensionality;
}

#endif /* RandomBase_hpp */
