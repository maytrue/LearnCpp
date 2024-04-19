//
//  TestClass.hpp
//  ThreadSafeSingleton
//
//  Created by guowei on 13/10/2016.
//  Copyright © 2016 guowei. All rights reserved.
//

#ifndef TestClass_hpp
#define TestClass_hpp

#include <stdio.h>

class TestClass
{
public:
    TestClass();
    ~TestClass();
    static int getInstanceNumber();
private:
    static int mInstanceNumber;
};

#endif /* TestClass_hpp */
