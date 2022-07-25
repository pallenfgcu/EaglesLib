//
// Created by pallen on 6/27/2022.
//
#include "AnimatedShape.h"

#ifndef EAGLES_ANIMATEDTRIANGLE_H
#define EAGLES_ANIMATEDTRIANGLE_H

namespace fgcu {

    /// A 3 sided equilateral triangle defined by a base=width and height property values.
    ///
    /// fgcu::AnimatedTriangle extends fgcu::AnimatedShape which provides for animation speeds and visibility, and gets all properties and methods of a sf::Shape.
    class AnimatedTriangle : public AnimatedShape {
    public:
        /// Construct an equilateral triangle given the base=width and height as float values.
        /// \param width The length of the base of the triangle.
        /// \param height The length of the height of the triangle.
        explicit AnimatedTriangle(float width=0, float height=0);

        /// Construct an equilateral triangle given the base=width and height as float values.
        /// \param size the length of the base and height of the triangle are provided in an (x,y) sf::Vector2f structure.
        explicit AnimatedTriangle(const sf::Vector2f& size = sf::Vector2f(0, 0));

        /// Alter the size of the triangle.
        /// \param width The new length of the base of the triangle.
        /// \param height The new height of the triangle.
        void setSize(float width, float height);

        /// Alter the size of the triangle.
        /// \param size The length of the base and height of the triangle are provided in an (x,y) sf::Vector2f structure.
        void setSize(const sf::Vector2f& size);

        /// Get the length of the base width of the triangle.
        /// \return The length of the base width of the triangle.
        float getWidth() const;

        /// Get the length of the height of the triangle.
        /// \return The length of the height of the triangle.
        float getHeight() const;

        /// Get the current size of the triangle.
        /// \return The current length of the base and height of the triangle are provided in an (x,y) sf::Vector2f structure.
        const sf::Vector2f& getSize() const;

        /// Overrides base interface sf::Drawable::getPointCount.
        /// \return The number of points of the shape object.
        std::size_t getPointCount() const override;

        /// Overrides base interface sf::Drawable::getPoint.
        /// \param index The index number of the point on the shape.
        /// \return An (x,y) point location.
        sf::Vector2f getPoint(std::size_t index) const override;

    private:
        sf::Vector2f m_size;
    };

} // fgcu

#endif //EAGLES_ANIMATEDTRIANGLE_H
