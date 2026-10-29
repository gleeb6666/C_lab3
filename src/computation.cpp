#include "computation.hpp"

#include "action.hpp"

#include <thread>

void Computation::run()
{
    std::jthread t1(&Computation::thread1, this);
    std::jthread t2(&Computation::thread2, this);
    std::jthread t3(&Computation::thread3, this);
    std::jthread t4(&Computation::thread4, this);
}

std::latch* Computation::completion_of(char set)
{
    switch (set) {
    case 'a': return &a_done_;
    case 'b': return &b_done_;
    case 'c': return &c_done_;
    case 'd': return &d_done_;
    case 'h': return &h_done_;
    case 'i': return &i_done_;
    default: return nullptr;
    }
}

void Computation::execute(char set, int first, int last)
{
    std::latch* done = completion_of(set);
    for (int i = first; i <= last; ++i) {
        f(set, i);
        if (done) {
            done->count_down();
        }
    }
}

void Computation::thread1()
{
    execute('a', 1, 4);
    a_done_.wait();
    execute('h', 1, 5);
    execute('c', 1, kC);
    h_done_.wait();
    d_done_.wait();
    execute('j', 1, 3);
}

void Computation::thread2()
{
    execute('a', 5, kA);
    execute('b', 1, 1);
    a_done_.wait();
    execute('h', 6, kH);
    execute('g', 1, kG);
    h_done_.wait();
    d_done_.wait();
    execute('j', 4, 4);
}

void Computation::thread3()
{
    execute('b', 2, 5);
    b_done_.wait();
    execute('d', 1, 4);
    execute('i', 1, 4);
    execute('k', 1, 2);
    c_done_.wait();
    i_done_.wait();
    execute('n', 1, 1);
    h_done_.wait();
    d_done_.wait();
    execute('j', 5, kJ);
}

void Computation::thread4()
{
    execute('b', 6, kB);
    b_done_.wait();
    execute('d', 5, kD);
    execute('i', 5, kI);
    execute('k', 3, kK);
    c_done_.wait();
    i_done_.wait();
    execute('n', 2, kN);
}
