//
// Created by pallen on 6/27/2022.
//
#include "AnimatedShape.h"

#ifndef EAGLES_ANIMATEDTRIANGLE_H
#define EAGLES_ANIMATEDTRIANGLE_H

namespace fgcu {

    class AnimatedTriangle : public AnimatedShape {
    public:
        explicit AnimatedTriangle(float width=0, float height=0);
        explicit AnimatedTriangle(const sf::Vector2f& size = sf::Vector2f(0, 0));

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

#endif //EAGLES_ANIMATEDTRIANGLE_H
