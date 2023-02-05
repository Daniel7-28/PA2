#pragma once

#include "State.h"
#include"Animation.h"

class LoadingState : public State 
{
    private:
        ofTrueTypeFont loading;
        int timer = 0;
        int limit = 75;
        int counter=0;

    public:
    LoadingState();
        string LS = "Loading...";
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void reset();
};