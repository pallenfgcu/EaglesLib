//
// Created by pallen on 6/27/2022.
//
#include "AnimatedShape.h"

#ifndef FGCU_ANIMATEDRECTANGLE_H
#define FGCU_ANIMATEDRECTANGLE_H

namespace fgcu {

    class AnimatedRectangle : public fgcu::AnimatedShape {
    public:
        explicit AnimatedRectangle(float width, float height);
        explicit AnimatedRectangle(const sf::Vector2f& size = sf::Vector2f(0, 0));

        void setSize(float width, float height);
        void setSize(const sf::Vector2f& size);

        float getWidth() const;
        float getHeight() const;
        const sf::Vector2f& getSize() const;

        std::size_t getPointCount() const override;

        sf::Vector2f getPoint(std::size_t index) const override;

    private:
        sf::Vector2f m_size;
    };

} // fgcu

#endif //FGCU_ANIMATEDRECTANGLE_H
