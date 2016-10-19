//
//  TestClass.cpp
//  ThreadSafeSingleton
//
//  Created by guowei on 13/10/2016.
//  Copyright © 2016 guowei. All rights reserved.
//

#include "TestClass.hpp"

int TestClass::mInstanceNumber = 0;

TestClass::TestClass()
{
    mInstanceNumber++;
}

int TestClass::getInstanceNumber()
{
    return mInstanceNumber;
}

TestClass::~TestClass()
{
    mInstanceNumber--;
}
