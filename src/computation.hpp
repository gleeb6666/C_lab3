#pragma once

#include <latch>

class Computation {
public:
    void run();

private:
    static constexpr int kA = 7;
    static constexpr int kB = 9;
    static constexpr int kC = 4;
    static constexpr int kD = 8;
    static constexpr int kG = 7;
    static constexpr int kH = 9;
    static constexpr int kI = 8;
    static constexpr int kJ = 5;
    static constexpr int kK = 4;
    static constexpr int kN = 3;

    std::latch a_done_{kA};
    std::latch b_done_{kB};
    std::latch c_done_{kC};
    std::latch d_done_{kD};
    std::latch h_done_{kH};
    std::latch i_done_{kI};

    std::latch* completion_of(char set);
    void execute(char set, int first, int last);

    void thread1();
    void thread2();
    void thread3();
    void thread4();
};
