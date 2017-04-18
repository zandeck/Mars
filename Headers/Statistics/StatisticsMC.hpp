//
//  StatisticsMC.hpp
//  Mars
//
//  Created by Matthieu Zandecki on 18/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#ifndef StatisticsMC_hpp
#define StatisticsMC_hpp

#include <stdio.h>
#include <vector>

class StatisticsMC {
    
public:
    StatisticsMC(){}
    
    virtual void DumpOneResult(double result) = 0;
    virtual std::vector<std::vector<double> > GetResultsSoFar() const = 0;
    virtual StatisticsMC* clone() const = 0;
    virtual ~StatisticsMC(){}
};

class StatisticsMean : public StatisticsMC {
    double RunningSum;
    unsigned long PathsDone;
    
public:
    StatisticsMean();
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double> > GetResultsSoFar() const;
    virtual StatisticsMC* clone() const;
};

#endif /* StatisticsMC_hpp */
