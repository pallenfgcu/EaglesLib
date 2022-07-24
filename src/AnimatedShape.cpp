//
// Created by pallen on 6/27/2022.
//
#include <iostream>
#include "../include/Eagles/AnimatedShape.h"

namespace fgcu {

    AnimatedShape::AnimatedShape() {
        m_horizontalSpeed = 0.0f;
        m_verticalSpeed = 0.0f;
        m_rotationalSpeed = 0.0f;
        m_visible = true;
    }

    float AnimatedShape::getHorizontalSpeed() const {
        return m_horizontalSpeed;
    }

    void AnimatedShape::setHorizontalSpeed(float speed) {
        m_horizontalSpeed = speed;
    }

    float AnimatedShape::getVerticalSpeed() const {
        return m_verticalSpeed;
    }

    void AnimatedShape::setVerticalSpeed(float speed) {
        m_verticalSpeed = speed;
    }

    float AnimatedShape::getRotationalSpeed() const {
        return m_rotationalSpeed;
    }

    void AnimatedShape::setRotationalSpeed(float speed) {
        m_rotationalSpeed = speed;
    }

    bool AnimatedShape::isVisible() const {
        return m_visible;
    }

    void AnimatedShape::setVisible(bool visible) {
        m_visible = visible;
    }

    void AnimatedShape::animate(float delta) {
        sf::Shape::move(m_horizontalSpeed * delta, m_verticalSpeed * delta);
        sf::Shape::rotate(m_rotationalSpeed * delta);
    }

    unsigned int AnimatedShape::getIndex() const {
        return m_index;
    }

    void AnimatedShape::setIndex(unsigned int index) {
        m_index = index;
    }


    std::size_t AnimatedShape::getPointCount() const {
        return m_points.size();
    }

    sf::Vector2f AnimatedShape::getPoint(std::size_t index) const {
        return m_points[index];
    }


} // fgcu