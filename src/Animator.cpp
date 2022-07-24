//
// Created by pallen on 6/20/2022.
//

#include "../include/Eagles/Animator.h"

namespace fgcu {

    Animator::Animator(int fps) {
        fps_ = fps;
        frameRate_ = 1.0f / float(fps);
        frameTime_ = timer_.getElapsedTime();
        currentLag_ = 0.0f;
    }

    void Animator::setFramesPerSecond(int fps) {
        fps_ = fps;
        frameRate_ = 1.0f / float(fps);
    }

    int Animator::getFramesPerSecond() const {
        return fps_;
    }

    float Animator::getFrameRate() const {
        return frameRate_;
    }

    float Animator::getDelta() const {
        return currentLag_;
    }

    void Animator::updateDelta(int n) {
        currentLag_ -= float(n) * frameRate_;
    }

    void Animator::nextFrame() {
        sf::Time stopTime = timer_.getElapsedTime();
        currentLag_ += float(stopTime.asMilliseconds() - frameTime_.asMilliseconds()) / 1000.0f;
        frameTime_ = stopTime;
    }

    void Animator::reset() {
        frameTime_ = timer_.getElapsedTime();
        currentLag_ = 0.0f;
    }

} // fgcu