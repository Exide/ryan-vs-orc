#ifndef RYAN_VS_ORC_RANDOM_H
#define RYAN_VS_ORC_RANDOM_H

#include <c++/random>
#include <c++/iostream>
#include <c++/ctime>
#include <c++/chrono>

class Random {

    std::default_random_engine engine;

    void initialize(unsigned long int seed) {
        engine = std::default_random_engine{seed};
        std::cout << "Random Seed: " << engine() << std::endl;
    }

public:

    explicit Random() {
        auto durationSinceEpoch = std::chrono::high_resolution_clock::now().time_since_epoch();
        auto seed = static_cast<long unsigned int>(durationSinceEpoch.count());
        initialize(seed);
    }

    explicit Random(long unsigned int seed) {
        initialize(seed);
    }

    int getNumberBetween(int min, int max) {
        std::uniform_int_distribution<int> distribution(min, max);
        int result = distribution(engine);
        return result;
    }

    bool flipCoin() {
        int result = getNumberBetween(0, 1);
        return (result == 0);
    }
};

#endif //RYAN_VS_ORC_RANDOM_H
