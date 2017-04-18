//
//  AntiThetic.hpp
//  Mars
//
//  Created by Matthieu Zandecki on 18/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#ifndef AntiThetic_hpp
#define AntiThetic_hpp

#include <stdio.h>
#include "RandomBase.hpp"
#include "Wrapper.hpp"

class AntiThetic : public RandomBase
{
    Wrapper<RandomBase> InnerGenerator;
    bool OddEven;
    MJArray NextVariates;
    
public:
    AntiThetic(const Wrapper<RandomBase>& innerGenerator);
    virtual RandomBase* clone() const;
    virtual void GetUniforms(MJArray& variates);
    virtual void Skip(unsigned long numberOfPaths);
    virtual void SetSeed(unsigned long Seed);
    virtual void ResetDimensionality(unsigned long NewDimensionality);
    virtual void Reset();
};

#endif /* AntiThetic_hpp */
