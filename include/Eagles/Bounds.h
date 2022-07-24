//
// Created by pallen on 6/21/2022.
//
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

#ifndef EAGLES_BOUNDS_H
#define EAGLES_BOUNDS_H

namespace fgcu {

    class Bounds {
    public:
        Bounds(sf::FloatRect bounds, sf::Vector2f position);

        void alignLeft(fgcu::Bounds& other);
        void alignCenter(fgcu::Bounds& other);
        void alignRight(fgcu::Bounds& other);
        void alignTop(fgcu::Bounds& other);
        void alignMiddle(fgcu::Bounds& other);
        void alignBottom(fgcu::Bounds& other);
        
        void toLeftOf(fgcu::Bounds& other, float padding);
        void toRightOf(fgcu::Bounds& other, float padding);
        void toTopOf(fgcu::Bounds& other, float padding);
        void toBottomOf(fgcu::Bounds& other, float padding);

        sf::Vector2f closestPoint(fgcu::Bounds& other, bool fromCenter=true);
        float distanceToClosestPoint(fgcu::Bounds& other, bool fromCenter=true);
        float angleToClosestPoint(fgcu::Bounds& other, bool fromCenter=true);

        float x;
        float y;
        float originX;
        float originY;
        float width;
        float height;
        float left;
        float right;
        float top;
        float bottom;
        float center;
        float middle;
    };

} // fgcu

#endif //EAGLES_BOUNDS_H
