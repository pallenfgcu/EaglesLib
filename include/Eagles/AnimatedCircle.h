//
// Created by pallen on 6/27/2022.
//
#include "AnimatedShape.h"

#ifndef FGCU_ANIMATEDCIRCLE_H
#define FGCU_ANIMATEDCIRCLE_H

namespace fgcu {

    class AnimatedCircle : public AnimatedShape {
    public:
        explicit AnimatedCircle(float radius = 0, std::size_t pointCount = 30);

        void setRadius(float radius);

        float getRadius() const;

        void setPointCount(std::size_t count);

        std::size_t getPointCount() const override;

        sf::Vector2f getPoint(std::size_t index) const override;


    protected:
        void update();

    private:
        float       m_radius;     ///< Radius of the circle
        std::size_t m_pointCount; ///< Number of points composing the circle

    };

} // fgcu

#endif //FGCU_ANIMATEDCIRCLE_H
