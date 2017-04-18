//
//  Wrapper.hpp
//  Mars
//
//  Created by Matthieu Zandecki on 18/04/2017.
//  Copyright © 2017 Matthieu Zandecki. All rights reserved.
//

#ifndef Wrapper_hpp
#define Wrapper_hpp

#include <stdio.h>

template <class T>
class Wrapper {
    T* DataPtr;
    
public:
    Wrapper()
    {
        DataPtr = 0;
    }
    
    Wrapper(const T& inner)
    {
        DataPtr = inner.clone();
    }
    
    ~Wrapper()
    {
        if (DataPtr != 0)
            delete DataPtr;
    }
    
    Wrapper(const Wrapper<T>& original)
    {
        if (original.DataPtr != 0) {
            DataPtr = original.DataPtr->clone();
        }
        else
            DataPtr = 0;
    }
    
    Wrapper& operator=(const Wrapper<T>& original)
    {
        if (this != &original) {
            if (DataPtr != 0) {
                delete DataPtr;
            }
            DataPtr = (original.DataPtr != 0) ? original.DataPtr->clone() : 0;
        }
        
        return *this;
    }
    
    T& operator*()
    {
        return *DataPtr;
    }
    
    const T& operator*() const
    {
        return *DataPtr;
    }
    
    const T* const operator->() const
    {
        return DataPtr;
    }
    
    T* operator->()
    {
        return DataPtr;
    }
    
};

#endif /* Wrapper_hpp */
