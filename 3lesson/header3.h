#pragma once
#include <random>

namespace SimpleAdd {
    template <typename T>
    T add(T a, T b) {
        return a + b;
    }

    template <typename R, typename T>
    R extended_add(T a, T b) {
        return static_cast<R>(a + b);
    }
}

namespace RandomAdd {
    template <typename T>
    T add(T a, T b) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> value(0, 10000);
        T c = a + b;

        if (value(gen) % 2) {
            c += value(gen);
        }

        return c;
    }

    template <typename R, typename T>
    R extended_add(T a, T b) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> value(0, 10000);
        
        R c = static_cast<R>(a + b);

        if (value(gen) % 2) {
            c += static_cast<R>(value(gen));
        }

        return c;
    }
}