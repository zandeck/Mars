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
#include "VanillaOption.hpp"
#include "Parameters.hpp"
#include "PiecewiseConstantParameter.hpp"
#include "StatisticsMC.hpp"

void SimpleMonteCarlo(const VanillaOption& TheOption,
                        double Spot,
                        const ParametersConstant& Vol,
                        const ParametersConstant& r,
                        unsigned long NumberOfPaths,
                        StatisticsMC& gatherer);

#endif /* MonteCarlo_hpp */
