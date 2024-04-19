//
//  ThreadSafeSingleton.hpp
//  ThreadSafeSingleton
//
//  Created by guowei on 13/10/2016.
//  Copyright © 2016 guowei. All rights reserved.
//

#ifndef ThreadSafeSingleton_hpp
#define ThreadSafeSingleton_hpp

#include <stdio.h>
#include <pthread.h>

class noncopyable
{
protected:
    noncopyable() {}
    ~noncopyable() {}
private:  // emphasize the following members are private
    noncopyable( const noncopyable& );
    const noncopyable& operator=( const noncopyable& );
};

template <typename T>
class Singleton : public noncopyable
{
public:
    static T* getInstance() {
        pthread_once(&mOnce, &Singleton::init);
        return mValue;
    }
    
    static void init() {
        mValue = new T();
    }
    
private:
    static T* mValue;
    static pthread_once_t mOnce;
    
};

template<typename T>
T* Singleton<T>::mValue = NULL;

template<typename T>
pthread_once_t Singleton<T>::mOnce = PTHREAD_ONCE_INIT;

#endif /* ThreadSafeSingleton_hpp */
