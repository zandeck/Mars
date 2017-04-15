//
//  MonteCarlo.hpp
//  Mars
//
//  Created by Matthieu Zandecki on 15/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#ifndef MonteCarlo_hpp
#define MonteCarlo_hpp

#include <stdio.h>
#include "Random.hpp"
#include <cmath>
#include "PayOffs.hpp"

double SimpleMonteCarlo(double Expiry,
                        double Strike,
                        double Spot,
                        double Vol,
                        double r,
                        unsigned long NumberOfPaths);

#endif /* MonteCarlo_hpp */
