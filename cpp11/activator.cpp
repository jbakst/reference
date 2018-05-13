//
// Created by jbakst on 5/13/18.
//

#include <mutex>
#include <iostream>
#include "activator.hpp"


int32_t activator::doActivation(uint16_t type) {
    std::cerr << "activator::doActivation()" << "\n";
    //std::unique_lock<std::mutex> lock(m_activatemutex);
    uint16_t address = 0x716;   // this is the ecuid for ECG CCPU (QNX)
    int32_t result = doActivationAp(address);
    return 0;
}

int32_t activator::doActivationAp(uint32_t address) {
    std::cerr << "activator::doActivationAp()" << "\n";

    std::cerr << "try_lock" << "\n";
    if (m_activatemutex.try_lock()) {
        std::cerr << "unlock" << "\n";
        m_activatemutex.unlock();
        std::cerr << "setup" << "\n";
        std::unique_lock<std::mutex> lock(m_activatemutex);
        std::cerr << "waiting" << "\n";
        m_activatecond.wait(lock);
        std::cerr << "notified" << "\n";
    } else {
        std::cerr << "already locked" << "\n";
    }

    return 0;
}

void activator::start() {
    std::cerr << "activator::start()" << "\n";
    uint16_t type = 0;

    m_activatetask = std::async(std::launch::async, [this, type] {
        int32_t result = doActivation(type);
        if (result == 0) {

        }
    });

}

void activator::notify() {
    std::cerr << "notify" << "\n";
    m_activatecond.notify_one();
}