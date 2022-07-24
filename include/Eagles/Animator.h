//
// Created by pallen on 6/20/2022.
//
#include <SFML/Graphics.hpp>

#ifndef EAGLES_ANIMATOR_H
#define EAGLES_ANIMATOR_H

namespace fgcu {


    class Animator {
    public:
        explicit Animator(int fps=30);

        void setFramesPerSecond(int fps);
        [[nodiscard]] int getFramesPerSecond() const;

        [[nodiscard]] float getFrameRate() const;

        [[nodiscard]] float getDelta() const;

        void updateDelta(int n=1);

        void nextFrame();

        void reset();

    private:
        int fps_;
        float frameRate_;

        sf::Clock timer_;
        sf::Time frameTime_;
        float currentLag_;

    };
}


#endif //EAGLES_ANIMATOR_H
