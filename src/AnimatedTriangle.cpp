//
// Created by pallen on 6/27/2022.
//

#include "../include/Eagles/AnimatedTriangle.h"

namespace fgcu {

    AnimatedTriangle::AnimatedTriangle(float width, float height) {
        setSize(sf::Vector2f(width, height));
    }

    AnimatedTriangle::AnimatedTriangle(const sf::Vector2f &size) {
        setSize(size);
    }

    void AnimatedTriangle::setSize(float width, float height) {
        setSize(sf::Vector2f(width, height));
    }

    void AnimatedTriangle::setSize(const sf::Vector2f &size) {
        m_size = size;
        m_points.emplace_back(m_size.x / 2.0f, 0);
        m_points.emplace_back(0, m_size.y);
        m_points.emplace_back(m_size.x, m_size.y);
        update();
    }

    float AnimatedTriangle::getWidth() const {
        return m_size.x;
    }

    float AnimatedTriangle::getHeight() const {
        return m_size.y;
    }

    const sf::Vector2f &AnimatedTriangle::getSize() const {
        return m_size;
    }

    std::size_t AnimatedTriangle::getPointCount() const {
        return fgcu::AnimatedShape::getPointCount();
    }

    sf::Vector2f AnimatedTriangle::getPoint(std::size_t index) const {
        return fgcu::AnimatedShape::getPoint(index);
    }

} // fgcu