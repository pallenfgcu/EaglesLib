//
// Created by pallen on 6/27/2022.
//
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "AnimatedShape.h"
#include <string>
#include <list>

#ifndef FGCU_ANIMATEDWINDOW_H
#define FGCU_ANIMATEDWINDOW_H

namespace fgcu {

    const int DEFAULT_FPS = 30;

    class AnimatedWindow : public sf::RenderWindow {
    public:
        AnimatedWindow(unsigned int width, unsigned int  height, std::string& title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings& settings = sf::ContextSettings());

        void create(unsigned int width, unsigned int  height, std::string& title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings& settings = sf::ContextSettings());

        ~AnimatedWindow();

        void setColor(unsigned int color);
        unsigned int getColor() const;

        void setFPS(int fps);
        int getFPS() const;

        unsigned int addShape(AnimatedShape* shape);
        AnimatedShape* removeShape(unsigned int index);

        bool nextFrame();

        sf::Keyboard::Key getLastKey();

        void timerReset();

    protected:
        std::list<fgcu::AnimatedShape*> m_shapes;

        sf::Color m_color;

        sf::Clock m_timer;
        int m_fps;
        float m_lag;

        sf::Keyboard::Key m_lastKey;

    private:
        sf::Time p_startTime;
        sf::Time p_stopTime;

        unsigned int p_shapeIndex;

    };

} // fgcu

#endif //FGCU_ANIMATEDWINDOW_H
