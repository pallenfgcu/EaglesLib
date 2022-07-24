//
// Created by pallen on 6/26/2022.
//
#include <random>
#include <climits>
#include <cfloat>
#include <string>


#ifndef EAGLES_RANDOM_H
#define EAGLES_RANDOM_H

namespace fgcu {

    class Random {
    public:
        Random(int from, int to, std::string seed="");

        Random(double from, double to, std::string seed="");

        int nextInt();

        double nextReal();

    private:
        std::default_random_engine defEngine_;
        std::uniform_int_distribution<int> intDistro_;
        std::uniform_real_distribution<double> realDistro_;

        bool initInt_;
        bool initReal_;
    };

} // fgcu

#endif //EAGLES_RANDOM_H
