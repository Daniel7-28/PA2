#include "OverworldState.h"

OverworldState::OverworldState(Player *player, Area *area)
{
    this->player = player;
    camera = new OverworldCamera(player);
    loadArea(area);
    music.setVolume(0.25);
    music.setLoop(true);
}

void OverworldState::loadArea(Area *area)
{
    this->area = area;
    overworldImage = area->getImage();
    music = area->getMusic();
    music.setVolume(0.25);
    music.setLoop(true);
    player->setOX(area->getEntrancePos().x);
    player->setOY(area->getEntrancePos().y);    
}

void OverworldState::tick()
{
    if (!pausedState)
    {
        player->tickOverworld();
        if (moving){
        area->getNPC()->tickOverworld();
        textbox = false;
        textboxKey = false;
        }
        else{
            moving = true;
        }
        if (player->collides(area->getNPC()))
                {
                    moving = false;
                    textbox = true;
                }
        for (unsigned int i = 0; i < area->getEnemies().size(); i++)
        {
            if (!area->getEnemies().at(i)->isDead())
            {
                area->getEnemies().at(i)->tickOverworld();
                if (player->collides(area->getEnemies().at(i)))
                {
                    setEnemy(area->getEnemies().at(i));
                    setNextState("Battle");
                    setFinished(true);
                }
            }
        }
        if(area->getRemainingEnemies() == 0)
        {
            area->getBoss()->tickOverworld();
            if(player->collides(area->getBoss()))
            {
                setEnemy(area->getBoss());
                setNextState("Battle");
                setFinished(true);
            }
        }
        player->setUp(true);
        player->setDown(true);
        player->setRight(true);
        player->setLeft(true);

        if(player->getBounds(player->getOX(),player->getOY() - player->getSpeed()).intersects(area->getEntity()->getBounds())) {
            player->setUp(false);
        }
        if(player->getBounds(player->getOX(),player->getOY() + player->getSpeed()).intersects(area->getEntity()->getBounds())) {
            player->setDown(false);
        }
        if(player->getBounds(player->getOX() + player->getSpeed(), player->getOY()).intersects(area->getEntity()->getBounds())) {
            player->setRight(false); 
            }
        if(player->getBounds(player->getOX() - player->getSpeed(), player->getOY()).intersects(area->getEntity()->getBounds())) {
            player->setLeft(false); 
            }

        camera->tick();
    }
}

void OverworldState::render()
{
    overworldImage.drawSubsection(0, 0, camera->getDimensionX(), camera->getDimensionY(), camera->getLeftCornerX(), camera->getTopCornerY());
    player->renderOverworld();

    int rockDistanceX = area->getEntity()->getOX() - camera->getPlayerX();
    int rockDistanceY = area->getEntity()->getOY() - camera->getPlayerY();
    area->getEntity()->setRenderX(camera->getDimensionX() / 2 + rockDistanceX);
    area->getEntity()->setRenderY(camera->getDimensionY() / 2 + rockDistanceY);
    area->getEntity()->renderOverworld();

    overWorldState.load("font/Gameplay.ttf",8);
    for (unsigned int i = 0; i < area->getEnemies().size(); i++)
    {
        if (!area->getEnemies().at(i)->isDead())
        {
            int playerDistanceX = area->getEnemies().at(i)->getOX() - camera->getPlayerX();
            int playerDistanceY = area->getEnemies().at(i)->getOY() - camera->getPlayerY();
            area->getEnemies().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
            area->getEnemies().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
            area->getEnemies().at(i)->renderOverworld();
            overWorldState.drawString("Enemies Remaining: " + to_string(area->getRemainingEnemies()), 20 , ofGetHeight() - 20);
        }
    }

    int NPCDistanceX = area->getNPC()->getOX() - camera->getPlayerX();
    int NPCDistanceY = area->getNPC()->getOY() - camera->getPlayerY();
    area->getNPC()->setRenderX(camera->getDimensionX() / 2 + NPCDistanceX);
    area->getNPC()->setRenderY(camera->getDimensionY() / 2 + NPCDistanceY);
    area->getNPC()->renderOverworld();

    if (area->getRemainingEnemies() == 0){
        int bossDistanceX = area->getBoss()->getOX() - camera->getPlayerX();
        int bossDistanceY = area->getBoss()->getOY() - camera->getPlayerY();
        area->getBoss()->setRenderX(camera->getDimensionX() / 2 + bossDistanceX);
        area->getBoss()->setRenderY(camera->getDimensionY() / 2 + bossDistanceY);
        area->getBoss()->renderOverworld();
        overWorldState.drawString("BOSS FIGHTING! ", 20, ofGetHeight() - 20);
    }
    overWorldState.load("font/Gameplay.ttf",15);
    overWorldState.drawString(oW, ofGetWidth() / 2 - overWorldState.stringWidth(oW) / 2, 20);
    if(textbox && textboxKey){
    overWorldState.load("font/Gameplay.ttf",5);
    overWorldState.drawString("Hello Adevnturer!", 288, 200);
    }
    overWorldHealthBar();
}

void OverworldState::overWorldHealthBar(){
    ofImage healthbar;
    ofSetColor(255, 255, 255);
    healthbar.load("images/ui/healthbar.png");
    healthbar.draw(ofGetWidth()/2 - 96, 208, 192, 192);

    for (int i = 0; i < 3; i++)
    {
        double playerHealthRatio = (double)player->getCurrentPlayerHealth() / (double)player->getHealth();
        if(playerHealthRatio < 0){
            playerHealthRatio = 0;
        }
        else if (playerHealthRatio < 0.33)
        {
            ofSetColor(200 - i * 20, 60 - i * 20, 60 - i * 20);
        }
        else if (playerHealthRatio < 0.66)
        {
            ofSetColor(180 - i * 20, 200 - i * 20, 60 - i * 20);
        }
        else
        {
            ofSetColor(60 - i * 20, 180 - i * 20, 80 - i * 20);
        }
        ofDrawRectangle(ofGetWidth()/2 - 52, 296 + i * 4, (int)(36 * playerHealthRatio) * 4, 4);
    }
    ofFill();
    ofSetColor(255, 255, 255);
}

void OverworldState::keyPressed(int key)
{
    player->keyPressed(key);

    if(key == 'p') pausedState = !pausedState;
    if(key == 'e') textboxKey = !textboxKey;
}

void OverworldState::keyReleased(int key)
{
    player->keyReleased(key);
}

void OverworldState::mousePressed(int x, int y, int button)
{
}

void OverworldState::reset()
{
    player->keyReleased('w');
    player->keyReleased('a');
    player->keyReleased('s');
    player->keyReleased('d');
    setFinished(false);
    setNextState("");
}