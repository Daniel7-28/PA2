#pragma once

#include "Entity.h" 
#include "Animation.h"
#include "Fighting.h"

#define INIT_X 100
#define INIT_Y 100
#define CENTER_X 288
#define CENTER_Y 208

#define OXDIMENSION 2688
#define OYDIMENSION 2560


class Player : public Entity , public Fighting{
    private:
        Direction direction = Direction::up;
        int speed = 8;
        bool up = true , down = true, right = true, left = true;
        bool walking = false;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        Animation *fighting;
        vector<char> pressedKeys;
        int currentHealthPlayer;
    
    public:
        Player(int health, int baseDamage);
        ~Player();
        void tickOverworld();
        void tickFighting();
        void renderOverworld();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
        void setUp(bool u){this->up = u;};
        void setDown(bool d){this->down = d;};
        void setRight(bool r){this->right = r;};
        void setLeft(bool l){this->left = l;};
        int getSpeed(){ return speed;};
        int getCurrentPlayerHealth(){return currentHealthPlayer;};
        void setCurrentPlayerHealth(int currentHealthPlayer){this->currentHealthPlayer = currentHealthPlayer;};
        };