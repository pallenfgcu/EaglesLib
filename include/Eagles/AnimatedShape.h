//
// Created by pallen on 6/27/2022.
//
#include <SFML/Graphics/Shape.hpp>
#include <vector>

#ifndef FGCU_ANIMATED_SHAPE_H
#define FGCU_ANIMATED_SHAPE_H

namespace fgcu {

    class AnimatedShape : public sf::Shape {
    public:
        AnimatedShape();

        virtual float getHorizontalSpeed() const;
        virtual void setHorizontalSpeed(float speed);

        virtual float getVerticalSpeed() const;
        virtual void setVerticalSpeed(float speed);

        virtual float getRotationalSpeed() const;
        virtual void setRotationalSpeed(float speed);

        virtual bool isVisible() const;
        virtual void setVisible(bool visible);

        virtual void animate(float delta);

        virtual unsigned int getIndex() const;
        virtual void setIndex(unsigned int index);

        std::size_t getPointCount() const override;
        sf::Vector2f getPoint(std::size_t index) const override;

    protected:
        float m_horizontalSpeed;
        float m_verticalSpeed;
        float m_rotationalSpeed;
        bool  m_visible;

        unsigned int m_index;

        std::vector<sf::Vector2f> m_points;
    };

} // fgcu

#endif //FGCU_ANIMATED_SHAPE_H
