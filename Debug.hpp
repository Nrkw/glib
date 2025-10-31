#ifndef DEBUG_HPP
#define DEBUG_HPP

#include<windows.h>
#include <string>
#include<iostream>

class Debug
{
    public:

    constexpr static int DEBUG_LEVEL_LOG = 1;
    constexpr static int DEBUG_LEVEL_WARN = 2;
    constexpr static int DEBUG_LEVEL_ERROR = 3;
    static int currentDebugLevel;
    
    #ifdef DEBUG_MODE
     static void attachConsole();
     
    //Debug::log。ログ用の関数。l()
    template<typename T>
    static void log(const T& message);
    template<typename T>
    static void warn(const T& message);

    template<typename T>
    static void err(const T& message);
    #else

    static void attachConsole(){}

    template<typename T>
    static void log(const T& message){}

    template<typename T>
    static void err(const T& message){}
    #endif

};

#endif