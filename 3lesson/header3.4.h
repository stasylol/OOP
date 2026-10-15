#pragma once
#include <random>

namespace RandomAdd {
    template <typename R, typename T>
    R extended_add(T a, T b) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> value(0, 100);
        
        R c = static_cast<R>(a + b);
        if (value(gen) % 2) {
            c += static_cast<R>(value(gen));
        }
        return c;
    }
}