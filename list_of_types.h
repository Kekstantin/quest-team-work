#pragma once
#include <list>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>

#define MIN_GENERATION_LIMIT_DOOR_WITHOUT_MONSTER 0
#define MAX_GENERATION_LIMIT_DOOR_WITHOUT_MONSTER 20
#define MAX_GENERATION_LIMIT_SLIME 30
#define MAX_GENERATION_LIMIT_GOBLIN 47
#define MAX_GENERATION_LIMIT_SCP_173 50 

#define MIN_GENERATION_LIMIT_DOOR_WITHOUT_WEAPON 0
#define MAX_GENERATION_LIMIT_DOOR_WITHOUT_WEAPON 20
#define MAX_GENERATION_LIMIT_DOOR_MACE 30
#define MAX_GENERATION_LIMIT_DOOR_SWORD 47
#define MAX_GENERATION_LIMIT_DOOR_BOW 50



enum class_of_the_monster_ {water_, earth_, air_, fire_, lighting_};
enum type_of_the_monster_ {slime_, goblin_, scp_173_};
enum type_of_the_weapon_ {knife_, sword_, bow_, mace_};

using damage_ = int;
using health_ = int;
using balance_ = int;
