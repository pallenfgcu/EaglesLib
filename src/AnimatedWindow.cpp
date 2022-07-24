//
// Created by pallen on 6/27/2022.
//
#include "../include/Eagles/AnimatedWindow.h"
#include <SFML/Window/Event.hpp>

namespace fgcu {


    AnimatedWindow::AnimatedWindow(unsigned int  width, unsigned int  height, std::string &title, sf::Uint32 style, const sf::ContextSettings& settings)
    {
        create(width, height, title, style, settings);
    }

    void AnimatedWindow::create(unsigned int width, unsigned int  height, std::string& title, sf::Uint32 style, const sf::ContextSettings& settings) {
        m_color = sf::Color::White;
        m_fps = DEFAULT_FPS;
        m_lag = 0.0f;
        m_lastKey = sf::Keyboard::Key::Unknown;
        timerReset();
        p_shapeIndex = 0;
        sf::Window::create(sf::VideoMode(width, height), title, style, settings);
        clear(m_color);
    }

    AnimatedWindow::~AnimatedWindow() {
        for (const auto shape: m_shapes) {
            delete shape;
        }
        m_shapes.clear();
    }

    void AnimatedWindow::setColor(unsigned int color) {
        m_color = sf::Color(color);
    }

    unsigned int AnimatedWindow::getColor() const {
        return m_color.toInteger();
    }

    void AnimatedWindow::setFPS(const int fps) {
        m_fps = fps;
    }

    int AnimatedWindow::getFPS() const {
        return m_fps;
    }

    unsigned int AnimatedWindow::addShape(AnimatedShape *shape) {
        unsigned int index = p_shapeIndex;
        shape->setIndex(index);
        m_shapes.push_back(shape);
        p_shapeIndex++;
        return index;
    }

    AnimatedShape* AnimatedWindow::removeShape(unsigned int index) {
        AnimatedShape* erased = nullptr;
        std::list<AnimatedShape*>::iterator itShape = m_shapes.begin();
        while(itShape != m_shapes.end()) {
            if ((*itShape)->getIndex() == index) {
               erased = (*itShape);
               m_shapes.erase(itShape);
               break;
            }
            itShape++;
        }
        return erased;
    }

    bool AnimatedWindow::nextFrame() {
        bool running = true;

        sf::Event event{};
        while (pollEvent(event)) {
            // "close requested" event: we close the m_window
            if (event.type == sf::Event::Closed) {
                running = false;
            }
            else if (event.type == sf::Event::KeyPressed) { // KeyReleased
                m_lastKey = event.key.code;
            }
        }

        if (running) {
            p_stopTime = m_timer.getElapsedTime();

            m_lag += float(p_stopTime.asMilliseconds() - p_startTime.asMilliseconds());
            p_startTime = p_stopTime;

            float frameRate = (1.0f / float(m_fps)) * 1000.0f;

            int updates = int(m_lag / frameRate);

            for (const auto shape: m_shapes) {
                // render
                if (shape->isVisible()) {
                    AnimatedShape temp = *shape;
                    temp.animate(m_lag / 1000.0f);
                    draw(temp);
                }

                // update
                if (updates) {
                    shape->animate(m_lag / 1000.0f);
                }
            }

            if (updates) {
                m_lag -= frameRate * float(updates);
            }

            display();
            clear(m_color);
        }

        return running;

    }

    sf::Keyboard::Key AnimatedWindow::getLastKey() {
        sf::Keyboard::Key retKey = m_lastKey;
        m_lastKey = sf::Keyboard::Key::Unknown;
        return retKey;
    }

    void AnimatedWindow::timerReset() {
        p_startTime = m_timer.restart();
        p_stopTime = p_startTime;
    }

} // fgcu