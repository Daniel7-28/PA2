#pragma once

#include "Player.h"
#include "Enemy.h"
#include "OverworldCamera.h"
#include "NPC.h"
#include"Boss.h"

class Area 
{
    private:
        ofImage areaImage;
        ofSoundPlayer areaMusic;
        ofImage areaStage;
        ofPoint entrancePosition;
        std::vector<Enemy*> enemies;
        Area *nextArea;
        Entity *entity;
        NPC *npc1;
        Boss *boss;

    public:
        Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies,Entity *entity, NPC *npc1, Boss *boss);
        void resetEnemies();
        ofImage getImage() { return areaImage;};
        ofSoundPlayer getMusic() { return areaMusic;};
        ofImage getStage() { return areaStage;};
        ofPoint getEntrancePos() { return entrancePosition;};
        void setEnemies(std::vector<Enemy*> enemies) { this->enemies = enemies;};
        vector<Enemy*> getEnemies() { return enemies;};
        int getRemainingEnemies();
        Area* getNextArea() { return nextArea;};
        Entity* getEntity() {return entity;};
        NPC* getNPC() {return npc1;};
        Boss* getBoss(){return boss;};
        void resetBoss();
        int getRemainingBoss();

        
};