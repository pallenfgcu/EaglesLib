//
// Created by pallen on 6/26/2022.
//

#include "../include/Eagles/Random.h"
#include <chrono>

namespace fgcu {

    Random::Random(int from, int to, std::string seed) {
        defEngine_ = std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count());
        if (!seed.empty()) {
            std::string fullSeed = seed + std::to_string(std::chrono::system_clock::now().time_since_epoch().count());
            std::seed_seq seedSeq (fullSeed.begin(), fullSeed.end());
            defEngine_.seed(seedSeq);
        }
        intDistro_ = std::uniform_int_distribution<int>(from, to);
        initInt_ = true;
        initReal_ = false;
        nextInt();
    }

    Random::Random(double from, double to, std::string seed) {
        defEngine_ = std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count());
        if (!seed.empty()) {
            std::string fullSeed = seed + std::to_string(std::chrono::system_clock::now().time_since_epoch().count());
            std::seed_seq seedSeq (fullSeed.begin(), fullSeed.end());
        }
        realDistro_ = std::uniform_real_distribution<double>(from, to);
        initInt_ = false;
        initReal_ = true;
        nextReal();
    }

    int Random::nextInt() {
        int next = 0;
        if (initInt_)
            next = intDistro_(defEngine_);
        return next;
    }

    double Random::nextReal() {
        double next = 0;
        if (initReal_)
            next = realDistro_(defEngine_);
        return next;
    }
} // fgcu