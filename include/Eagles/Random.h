/// File: Random.h
/// Florida Gulf Coast University
/// Department of Software Engineering
/// created by pallen on 6/27/2022.
// ----------------------------------------------------------------------------
#include <random>
#include <climits>
#include <cfloat>
#include <string>


#ifndef FGCU_RANDOM_H
#define FGCU_RANDOM_H

namespace fgcu {

    /// Utility class implements the std::Random library methods to generate a uniform-distribution random number generator for integers and doubles.
    class Random {
    public:

        /// Default construct.
        Random();

        /// Construct a random number generator for integers.
        /// \param from The minimum starting value.
        /// \param to The maximum value.
        /// \param seed A string used to create a unique seed value for the sequence.  Current time is appended to the string to make it further unique.
        Random(int from, int to, std::string seed="");

        /// Construct a random number generator for floating-point doubles.
        /// \param from The minimum starting value.
        /// \param to The maximum value.
        /// \param seed A string used to create a unique seed value for the sequence.  Current time is appended to the string to make it further unique.
        Random(double from, double to, std::string seed="");

        /// Get the next random integer from the sequence generated by constructing an integer generator.
        /// \return A random integer number between the from and to properties provided to the constructor.
        int nextInt();

        /// Get the next random double from the sequence generated by constructing a floating-point generator.
        /// \return A random double number between the from and to properties provided to the constructor.
        double nextReal();

    private:
        std::default_random_engine defEngine_;
        std::uniform_int_distribution<int> intDistro_;
        std::uniform_real_distribution<double> realDistro_;

        bool initInt_;
        bool initReal_;
    };

} // fgcu

#endif //FGCU_RANDOM_H
