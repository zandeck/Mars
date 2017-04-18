//
//  ParkMiller.cpp
//  Mars
//
//  Created by Matthieu Zandecki on 18/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#include "ParkMiller.hpp"

const long a = 16807;
const long m = 2147483647;
const long q = 127773;
const long r = 2836;

ParkMiller::ParkMiller(long Seed_) : Seed(Seed_)
{
    
}

void ParkMiller::SetSeed(long Seed_)
{
    Seed = Seed_;
    if (Seed == 0)
        Seed = 1;
}

unsigned long ParkMiller::Max()
{
    return m-1;
}

unsigned long ParkMiller::Min()
{
    return 1;
}

long ParkMiller::GetOneRandomInteger()
{
    long k = Seed / q;
    
    Seed = a * (Seed - k * q) - r * k;
    
    if (Seed < 0)
        Seed += m;
    
    return Seed;
}

RandomParkMiller::RandomParkMiller(unsigned long Dimensionality, unsigned long Seed) : RandomBase(Dimensionality), InnerGenerator(Seed), InitialSeed(Seed)
{
    Reciprocal = 1.0 / (1.0 + InnerGenerator.Max());
}

RandomBase* RandomParkMiller::clone() const
{
    return new RandomParkMiller(*this);
}

void RandomParkMiller::GetUniforms(MJArray &variates)
{
    for (unsigned long j = 0; j < GetDimensionality(); j++) {
        variates[j] = InnerGenerator.GetOneRandomInteger() * Reciprocal;
    }
}

void RandomParkMiller::Skip(unsigned long numberOfPaths)
{
    MJArray tmp(GetDimensionality());
    for (unsigned long j = 0; j < numberOfPaths; j++) {
        GetUniforms(tmp);
    }
}

void RandomParkMiller::SetSeed(unsigned long Seed)
{
    InitialSeed = Seed;
    InnerGenerator.SetSeed(Seed);
}

void RandomParkMiller::Reset()
{
    InnerGenerator.SetSeed(InitialSeed);
}

void RandomParkMiller::ResetDimensionality(unsigned long newDimensionality)
{
    RandomBase::ResetDimensionality(newDimensionality);
    InnerGenerator.SetSeed(InitialSeed);
}
