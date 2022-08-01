//
// Created by pallen on 6/27/2022.
//

#include "../include/Eagles/AnimatedCircle.h"
#include <cmath>

namespace fgcu {

    AnimatedCircle::AnimatedCircle() : AnimatedShape(){
        m_radius = 0;
        m_pointCount = 30;
    };

    AnimatedCircle::AnimatedCircle(float radius, std::size_t pointCount) :
    m_radius(radius),
    m_pointCount(pointCount)
    {
        update();
    }

    void AnimatedCircle::setRadius(float radius) {
        m_radius = radius;
        update();
    }

    float AnimatedCircle::getRadius() const {
        return m_radius;
    }

    void AnimatedCircle::setPointCount(std::size_t count) {
        m_pointCount = count;
        update();
    }

    std::size_t AnimatedCircle::getPointCount() const {
        return fgcu::AnimatedShape::getPointCount();
    }

    sf::Vector2f AnimatedCircle::getPoint(std::size_t index) const {
        return fgcu::AnimatedShape::getPoint(index);
    }

    void AnimatedCircle::update() {
        for (int i=0; i < m_pointCount; i++) {
            float angle = i * 2 * M_PI / m_pointCount - M_PI / 2;
            float x = std::cos(angle) * m_radius;
            float y = std::sin(angle) * m_radius;
            m_points.emplace_back(m_radius + x, m_radius + y);
        }
        sf::Shape::update();
    }
} // fgcu