#include "LoadingState.h"

LoadingState::LoadingState(){
    ofSetBackgroundColor(0);
    loading.load("font/Gameplay.ttf", 15);
}

void LoadingState::tick(){
    timer += 1;
    if(timer> limit){
        setNextState("Overworld");
        setFinished(true);
        timer = 0;
        counter = 0;   
    }
}

void LoadingState::render(){
    loading.drawString(LS, ofGetWidth() / 2 - loading.stringWidth(LS) / 2, ofGetHeight() / 2);
}

void LoadingState::keyPressed(int key){

}

void LoadingState::mousePressed(int x, int y, int button){

}

void LoadingState::reset(){
    setFinished(false);
    setNextState("");
}