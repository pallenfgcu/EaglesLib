//
// Created by pallen on 6/21/2022.
//

#include "../include/Eagles/Bounds.h"
#include <cmath>

namespace fgcu {

    Bounds::Bounds() {
        x = 0.0;
        y = 0.0;
        originX = 0.0;
        originY = 0.0;
        width = 0.0;
        height = 0.0;
        left = 0.0;
        right = 0.0;
        top = 0.0;
        bottom = 0.0;
        center = 0.0;
        middle = 0.0;
    };

    Bounds::Bounds(sf::FloatRect bounds, sf::Vector2f position) {
        x = position.x;
        y = position.y;
        width = bounds.width;
        height = bounds.height;

        left = bounds.left;
        right = bounds.left + bounds.width;
        top = bounds.top;
        bottom = bounds.top + bounds.height;
        center = bounds.left + bounds.width / 2.0f;
        middle = bounds.top + bounds.height / 2.0f;

        originX = x - left;
        originY = y - top;
    }

    void Bounds::alignLeft(fgcu::Bounds& other) {
        left = other.left;
        x = left + originX;
    }

    void Bounds::alignCenter(fgcu::Bounds& other) {
        left = other.center - width / 2.0f;
        x = left + originX;
    }

    void Bounds::alignRight(fgcu::Bounds& other) {
        left = other.right - width;
        x = left + originX;
    }

    void Bounds::alignTop(fgcu::Bounds& other) {
        top = other.top;
        y = top + originY;
    }

    void Bounds::alignMiddle(fgcu::Bounds& other) {
        top = other.center - height / 2.0f;
        y = top + originY;
    }

    void Bounds::alignBottom(fgcu::Bounds& other) {
        top = other.bottom - height;
        y = top + originY;
    }

    void Bounds::toLeftOf(fgcu::Bounds& other, float padding) {
        left = other.left - width - padding;
        x = left + originX;
    }

    void Bounds::toRightOf(fgcu::Bounds& other, float padding) {
        left = other.right + padding;
        x = left + originX;
    }

    void Bounds::toTopOf(fgcu::Bounds& other, float padding) {
        top = other.top - height - padding;
        y = top + originY;
    }

    void Bounds::toBottomOf(fgcu::Bounds& other, float padding) {
        top = other.bottom + padding;
        y = top + originY;
    }

    sf::Vector2f Bounds::closestPoint(Bounds &other, bool fromCenter) {
        float closestX = fromCenter ? center : left;
        float closestY = fromCenter ? middle : top;

        if (closestX < other.left)
            closestX = other.left;
        else if (closestX > other.right)
            closestX = other.right;

        if (closestY < other.top)
            closestY = other.top;
        else if (closestY > other.bottom)
            closestY = other.bottom;

        return {closestX, closestY};
    }

    float Bounds::distanceToClosestPoint(Bounds &other, bool fromCenter) {
        float thisX = fromCenter ? center : left;
        float thisY = fromCenter ? middle : top;

        sf::Vector2f closest = closestPoint(other, fromCenter);

        float diffX = closest.x - thisX;
        float diffY = closest.y = thisY;

        float distance = std::sqrt(std::pow(diffX, 2.0f) + std::pow(diffY, 2.0f));

        return distance;
    }

    float Bounds::angleToClosestPoint(Bounds &other, bool fromCenter) {
        float thisX = fromCenter ? center : left;
        float thisY = fromCenter ? middle : top;

        sf::Vector2f closest = closestPoint(other, fromCenter);

        float diffX = closest.x - thisX;
        float diffY = closest.y = thisY;

        double theta = std::atan2(diffY, diffX);
        double angle = 90.0 - theta * 180.0 / M_PI;
        if (angle <= 0.0)
            angle += 360;

        return float(angle);
    }


} // fgcu