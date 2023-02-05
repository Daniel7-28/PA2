#pragma once

// #include "Entity.h" 
#include "Animation.h"
// #include "Fighting.h"
#include "Enemy.h"

class Boss : public Enemy{
    private:
        Enemy *enemy;
    public:
        Boss(string id, int health, int baseDamage, string entityName, int ox, int oy);
        ~Boss();
        void tickOverworld();
        void tickFighting();
        void renderOverworld();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
        // string getId(){ return id; };
        // ofImage getSprite() { return overworldSprite;};
};