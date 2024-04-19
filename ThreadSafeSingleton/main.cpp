//
//  main.cpp
//  ThreadSafeSingleton
//
//  Created by guowei on 13/10/2016.
//  Copyright © 2016 guowei. All rights reserved.
//

#include <iostream>
#include "TestClass.hpp"
#include "ThreadSafeSingleton.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /*TestClass *a = new TestClass();
    std::cout << "Instance Number = " << TestClass::getInstanceNumber() << std::endl;
    
    TestClass *b = new TestClass();
    std::cout << "Instance Number = " << TestClass::getInstanceNumber() << std::endl;
    
    delete a;
    a = NULL;
    std::cout << "Instance Number = " << TestClass::getInstanceNumber() << std::endl;
    
    delete b;
    b = NULL;
    std::cout << "Instance Number = " << TestClass::getInstanceNumber() << std::endl;*/
    
    
    TestClass *c = Singleton<TestClass>::getInstance();
    std::cout << "Instance Number = " << TestClass::getInstanceNumber() << std::endl;
    
    
    TestClass *d = Singleton<TestClass>::getInstance();
    std::cout << "Instance Number = " << TestClass::getInstanceNumber() << std::endl;
    
    
    
    
    return 0;
}
