//
//  ConvergenceTable.hpp
//  Mars
//
//  Created by Matthieu Zandecki on 18/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#ifndef ConvergenceTable_hpp
#define ConvergenceTable_hpp

#include <stdio.h>
#include "Wrapper.hpp"
#include "StatisticsMC.hpp"

class ConvergenceTable : public StatisticsMC {
    Wrapper<StatisticsMC> Inner;
    std::vector<std::vector<double> > ResultsSoFar;
    unsigned long StoppingPoint;
    unsigned long PathsDone;
    
public:
    ConvergenceTable(const Wrapper<StatisticsMC>& Inner_);
    virtual StatisticsMC* clone() const;
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double> > GetResultsSoFar() const;
};

#endif /* ConvergenceTable_hpp */
