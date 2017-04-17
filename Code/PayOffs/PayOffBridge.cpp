//
//  PayOffBridge.cpp
//  Mars
//
//  Created by Matthieu Zandecki on 17/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#include "PayOffBridge.hpp"

PayOffBridge::PayOffBridge(const PayOffBridge& original)
{
    thePayOffPtr = original.thePayOffPtr->clone();
}

PayOffBridge::PayOffBridge(const PayOff& original)
{
    thePayOffPtr = original.clone();
}

PayOffBridge::~PayOffBridge()
{
    delete thePayOffPtr;
}

PayOffBridge& PayOffBridge::operator=(const PayOffBridge &original)
{
    if (this != &original)
    {
        delete thePayOffPtr;
        thePayOffPtr = original.thePayOffPtr->clone();
    }
    
    return *this;
}
