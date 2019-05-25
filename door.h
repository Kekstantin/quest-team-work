//
// Created by aylhttd on 25.05.19.
//

#ifndef GAME_OF_DOORS_DOOR_H
#define GAME_OF_DOORS_DOOR_H


#include "list_of_monsters.h"

class door {
public:
	door() {}
	door(monster_abs *mA, weapon*  wA, int reward, int stage) : _m_a(mA), _w_a(wA), _reward(reward), _stage(stage) {}
    monster_abs *getMA() const;
    void setMA(monster_abs *mA);
    weapon* getWA() const;
    void setWA(weapon *wA);
    int getReward() const;
    void setReward(int reward);
    int getStage() const;
    void setStage(int stage);

private:
    monster_abs* _m_a = nullptr;
    weapon* _w_a = nullptr;
    int _reward;
    int _stage;


};


#endif //GAME_OF_DOORS_DOOR_H
