/// File: AnimatedCircle.h
/// Florida Gulf Coast University
/// Department of Software Engineering
/// created by pallen on 6/27/2022.
// ----------------------------------------------------------------------------
#include "AnimatedShape.h"

#ifndef FGCU_ANIMATEDCIRCLE_H
#define FGCU_ANIMATEDCIRCLE_H

namespace fgcu {

    /// A circle shape defined by a radius.
    ///
    /// fgcu::AnimatedCircle extends fgcu::AnimatedShape which provides for animation speeds and visibility, and gets all properties and methods of a sf::Shape.

    class AnimatedCircle : public AnimatedShape {
    public:
        /// Construct a circle given a radius. Each point of the circle is calculated as a distance around the circle evenly divided by a number of points.
        /// \param radius The radius of the circle.
        /// \param pointCount The number of points on the outside of the circle. The default is 30 points.
        explicit AnimatedCircle(float radius = 0, std::size_t pointCount = 30);

        /// Alter the radius of the circle.
        /// \param radius The new radius of the circle.
        void setRadius(float radius);

        /// Get the current radius of the circle.
        /// \return The radius of the circle.
        float getRadius() const;

        /// Alter the number of points used to define the circle.
        /// \param count The number of points on the outside of the circle
        void setPointCount(std::size_t count);

        /// Overrides base interface sf::Drawable::getPointCount.
        /// \return The number of points of the shape object.
        std::size_t getPointCount() const override;

        /// Overrides base interface sf::Drawable::getPoint.
        /// \param index The index number of the point on the shape.
        /// \return An (x,y) point location.
        sf::Vector2f getPoint(std::size_t index) const override;

    protected:

        /// Updates the circle if the radius or point-count properties are altered.
        void update();

    private:
        float       m_radius;     ///< Radius of the circle
        std::size_t m_pointCount; ///< Number of points composing the circle

    };

} // fgcu

#endif //FGCU_ANIMATEDCIRCLE_H
