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

weapon *getWA() const{
    return _w_a;
}

void setWA(weapon *wA){
     _w_a=wA;
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

door::door(monster_abs *mA, weapon*  wA, int reward, int stage) : _m_a(mA), _w_a(wA), _reward(reward), _stage(stage) {}
