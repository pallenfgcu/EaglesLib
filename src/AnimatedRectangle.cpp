//
// Created by pallen on 6/27/2022.
//

#include "../include/Eagles/AnimatedRectangle.h"

namespace fgcu {

    AnimatedRectangle::AnimatedRectangle() : AnimatedShape() {};

    AnimatedRectangle::AnimatedRectangle(float width, float height) {
        setSize(sf::Vector2f(width, height));
    }

    AnimatedRectangle::AnimatedRectangle(const sf::Vector2f &size) {
        setSize(size);
    }

    void AnimatedRectangle::setSize(float width, float height) {
        setSize(sf::Vector2f(width, height));
    }

    void AnimatedRectangle::setSize(const sf::Vector2f &size) {
        m_size = size;
        m_points.emplace_back(0, 0);
        m_points.emplace_back(m_size.x, 0);
        m_points.emplace_back(m_size.x, m_size.y);
        m_points.emplace_back(0, m_size.y);
        update();
    }

    float AnimatedRectangle::getWidth() const {
        return m_size.x;
    }

    float AnimatedRectangle::getHeight() const {
        return m_size.y;
    }

    const sf::Vector2f &AnimatedRectangle::getSize() const {
        return m_size;
    }

    std::size_t AnimatedRectangle::getPointCount() const {
        return fgcu::AnimatedShape::getPointCount();
    }

    sf::Vector2f AnimatedRectangle::getPoint(std::size_t index) const {
        return fgcu::AnimatedShape::getPoint(index);
    }

} // fgcu