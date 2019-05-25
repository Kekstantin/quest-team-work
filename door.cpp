//
// Created by aylhttd on 25.05.19.
//

#include "door.h"

monster_abs *door::getMA() const {
    return _m_a;
}

void door::setMA(monster_abs *mA) {
    _m_a = mA;
}

int door::getReward() const {
    return _reward;
}

void door::setReward(int reward) {
    _reward = reward;
}

int door::getStage() const {
    return _stage;
}

void door::setStage(int stage) {
    _stage = stage;
}

door::door(monster_abs *mA, int reward, int stage) : _m_a(mA), _reward(reward), _stage(stage) {}
