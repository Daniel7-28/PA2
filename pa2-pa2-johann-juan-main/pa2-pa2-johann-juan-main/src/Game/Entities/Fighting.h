#pragma once
#include "ofMain.h"
class Fighting {
    protected:
        int health;
        int baseDamage;
        int fx, fy, fw, fh;
        ofImage fightingSprite;

    public:
        Fighting(int fx, int fy, int fw, int fh, int health, int baseDamage, string fightingPath);
        virtual void tickOverworld() = 0;
        virtual void tickFighting() = 0;
        virtual void renderFighting();
        int getHealth() { return health; };
        void setHealth(int health) { this->health = health; };
        int getDmg() { return baseDamage; };
        void setDmg(int baseDamage) { this->baseDamage = baseDamage; };

};