#include "computation.hpp"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <syncstream>

#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    std::osyncstream(std::cout) << "Обчислення розпочато.\n";
    const auto start = std::chrono::steady_clock::now();

    Computation computation;
    computation.run();

    const std::chrono::duration<double> elapsed = std::chrono::steady_clock::now() - start;
    std::osyncstream(std::cout) << "Обчислення завершено. Тривалість обчислення "
                                << std::fixed << std::setprecision(2) << elapsed.count() << " секунд.\n";
}
