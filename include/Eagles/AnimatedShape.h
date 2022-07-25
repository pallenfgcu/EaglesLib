/// File: AnimatedShape.h
/// Florida Gulf Coast University
/// Department of Software Engineering
/// created by pallen on 6/27/2022.
// ----------------------------------------------------------------------------
#include <SFML/Graphics/Shape.hpp>
#include <vector>

#ifndef FGCU_ANIMATED_SHAPE_H
#define FGCU_ANIMATED_SHAPE_H

namespace fgcu {

    /// Abstract base class derived from sf::Shape.
    ///
    /// fgcu::AnimatedShape provides base properties and methods to manage speed and visibility of shapes for animating.
    class AnimatedShape : public sf::Shape {
    public:
        /// fgcu::AnimatedShape objects are not instantiable.  This constructor initializes base property values for derived classes.
        AnimatedShape();

        /// Get the horizontal speed of the shape.
        /// \return The horizontal speed of the shape.
        virtual float getHorizontalSpeed() const;

        /// Set the horizontal speed of the shape.
        /// \param speed The horizontal speed of the shape.
        virtual void setHorizontalSpeed(float speed);

        /// Get the vertical speed of the shape.
        /// \return The vertical speed of the shape.
        virtual float getVerticalSpeed() const;

        /// Set the vertical speed of the shape.
        /// \param speed The vertical speed of the shape.
        virtual void setVerticalSpeed(float speed);

        /// Get the rotational speed of the shape.
        /// \return The rotational speed of the shape.
        virtual float getRotationalSpeed() const;

        /// Set the rotational speed of the shape.
        /// \param speed The rotational speed of the shape.
        virtual void setRotationalSpeed(float speed);

        /// Get the visibility property of the shape.
        /// \return True if the shape is visible.
        virtual bool isVisible() const;

        /// Set the visibility property of the shape.
        /// \param visible True to make the shape visiblie, false to prevent the shape from being drawn.
        virtual void setVisible(bool visible);

        /// Moves and rotates the shape based on current speeds and relative to current frame-time.
        virtual void animate(float delta);

        /// Get the index property value of the Shape.  This value is typically set when adding a shape to an fgcu::AnimatedWindow shapes collection.
        /// \return The index property of the shape.
        virtual unsigned int getIndex() const;

        /// Set the index property value of the Shape.  This value is typically set when adding a shape to an fgcu::AnimatedWindow shapes collection.
        /// \param index The index property of the shape.
        virtual void setIndex(unsigned int index);

        /// Overrides base interface sf::Drawable::getPointCount.
        /// \return The number of points of the shape object.
        std::size_t getPointCount() const override;

        /// Overrides base interface sf::Drawable::getPoint.
        /// \param index The index number of the point on the shape.
        /// \return An (x,y) point location.
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
