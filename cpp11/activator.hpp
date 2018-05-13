//
// Created by jbakst on 5/13/18.
//

#ifndef CPP11_ACTIVATOR_HPP
#define CPP11_ACTIVATOR_HPP


#include <cstdint>
#include <condition_variable>
#include <future>

class activator final {
public:
    activator() = default;
    ~activator() = default;

    void start();
    void notify();

private:
    int32_t doActivation(uint16_t type);
    int32_t doActivationAp(uint32_t address);

    std::mutex m_activatemutex;
    std::condition_variable m_activatecond;
    std::future<void> m_activatetask;
};


#endif //CPP11_ACTIVATOR_HPP
