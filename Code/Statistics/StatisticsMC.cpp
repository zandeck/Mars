//
//  StatisticsMC.cpp
//  Mars
//
//  Created by Matthieu Zandecki on 18/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#include "StatisticsMC.hpp"

using namespace std;

StatisticsMean::StatisticsMean() : RunningSum(0.0), PathsDone(0UL)
{
    
}

void StatisticsMean::DumpOneResult(double result)
{
    PathsDone++;
    RunningSum += result;
}

vector<vector<double> > StatisticsMean::GetResultsSoFar() const
{
    vector<vector<double> > Results(1);
    
    Results[0].resize(1);
    Results[0][0] = RunningSum / PathsDone;
    
    return Results;
}

StatisticsMC* StatisticsMean::clone() const
{
    return new StatisticsMean(*this);
}
