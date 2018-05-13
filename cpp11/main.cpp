#include <iostream>
#include <future>
#include <zconf.h>
#include "activator.hpp"

int main() {
    std::cout << "cpp11 mutex condvar test" << std::endl;

    activator a;
    a.start();

    auto task = std::async(std::launch::async, [&a] {
        sleep(5);
        a.notify();
    });

    return 0;
}