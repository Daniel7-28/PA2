#include "Area.h"

Area::Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies,Entity *entity, NPC *npc1, Boss *boss)
{
    this->nextArea = nextArea;
    areaImage.load(areaImagePath);
    areaMusic.load(areaMusicPath);
    areaStage.load(areaStagePath);
    this->entrancePosition = entrancePosition;
    this->enemies = enemies;
    this->entity = entity;
    this->npc1 = npc1;
    this->boss = boss;
}

void Area::resetEnemies(){
    for(unsigned int i = 0; i < enemies.size(); i++){
        enemies.at(i)->revive();
    }
}

int Area::getRemainingEnemies(){
    int count = 0;
    for(unsigned int i = 0; i < enemies.size(); i++){
        if(!enemies.at(i)->isDead()){
            count++;
        }
    }
    return count;
}

void Area::resetBoss(){
        getBoss()->revive();
}


int Area::getRemainingBoss(){
    int count = 0;
        if(!getBoss()->isDead()){
            count = 1;
    }
    return count;
}
