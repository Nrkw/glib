#include "Debug.hpp"


int Debug::currentDebugLevel = Debug::DEBUG_LEVEL_LOG;

#ifdef DEBUG_MODE
void Debug::attachConsole()
{
    
    AllocConsole();
    FILE *fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);  // 標準出力をコンソールに接続
    freopen_s(&fp, "CONOUT$", "w", stderr); // 標準エラー出力をコンソールに接続
    freopen_s(&fp, "CONIN$", "r", stdin);   // 標準入力をコンソールに接続
    std::wcout.clear();
    std::cout.clear();
}
template<typename T>
void Debug::log(const T& message)
{
    if (currentDebugLevel <= DEBUG_LEVEL_LOG)
        std::wcout << "[LOG]:" << message << std::endl;
}
template<typename T>
void Debug::warn(const T& message)
{
    if (currentDebugLevel <= DEBUG_LEVEL_WARN)
        std::wcout << "[WARN]:" << message << std::endl;
}

template<typename T>
void Debug::err(const T& message)
{
    if (currentDebugLevel <= DEBUG_LEVEL_ERROR)
        std::wcerr << "[ERROR]:" << message << std::endl;
}
#endif
