#include "graphicsdisplay.h"
#include <iostream>
#include "global.h"
#include "block.h"

using namespace std;

GraphicsDisplay::GraphicsDisplay(int width, int height, int winSize): width{width}, height{height}, winSize{winSize}, xw{winSize, winSize}, next{nullptr}, nextChanged{false}{
    xw.fillRectangle(0, 0, winSize, winSize, Xwindow::Black);
    xw.drawBigString(80, 40, "Quadris", 8);
    int gLevel = 0, gScore = 0, gHighscore = 0;
    
    string levelstring = "Level: "+ to_string(gLevel);
    string scorestring = "Score: " + to_string(gScore);
    string hiscorestring = "Hi Score: "+ to_string(gHighscore);
    xw.drawString(400, 100, levelstring, 6);
    xw.drawString(400, 130, scorestring, 5);
    xw.drawString(400, 160, hiscorestring, 3);
    
    xw.drawString(400, 250, "Next Block:", 8);
    xw.drawString(400, 520, "Made by Hamza Usmani", 8);
    xw.drawString(400, 540, "Sebastian Hothaza &", 8);
    xw.drawString(400, 560, "Miguel Angel Mesa", 8);
}


void GraphicsDisplay::setNext(Block *b){
    if (b == next) return;
    else{
        this->next = b;
        this->nextChanged = true;
    }
}

void GraphicsDisplay::drawNext(){
    if (!next) return;
    vector<vector<State>> nextBlock = next->printBlock();
    int nextX = 395, nextY = 270;
    xw.fillRectangle(nextX, nextY, 90, 50, Xwindow::Black);
    
    for (auto i: nextBlock){
        for (auto j: i){
            nextX += 15;
            if (j== State::I) xw.fillRectangle(nextX, nextY, 15, 15, Xwindow::Green);
            else if (j == State::J) xw.fillRectangle(nextX, nextY, 15, 15, Xwindow::Blue);
            else if (j == State::L) xw.fillRectangle(nextX, nextY, 15, 15, Xwindow::Red);
            else if (j == State::O) xw.fillRectangle(nextX, nextY, 15, 15, Xwindow::Cyan);
            else if (j == State::S) xw.fillRectangle(nextX, nextY, 15, 15, Xwindow::Yellow);
            else if (j == State::Z) xw.fillRectangle(nextX, nextY, 15, 15, Xwindow::Orange);
            else if (j == State::T) xw.fillRectangle(nextX, nextY, 15, 15, Xwindow::Brown);
        }
        nextX = 395;
        nextY +=15;
    }
}


void GraphicsDisplay::notify(Cell &whoNotified) {
    if (gLevel != default_level){
        string levelstring = "Level: "+ to_string(default_level);
        xw.fillRectangle(395, 88, 70, 15, Xwindow::Black);
        xw.drawString(400, 100, levelstring, 6);
    }
    
    if (gScore != curscore){
         string scorestring = "Score: " + to_string(curscore);
         xw.fillRectangle(395, 118, 70, 15, Xwindow::Black);
         xw.drawString(400, 130, scorestring, 5);
    }
    
    if (gHighscore != highscore){
        string hiscorestring = "Hi Score: "+ to_string(highscore);
        xw.fillRectangle(395, 148, 70, 15, Xwindow::Black);
        xw.drawString(400, 160, hiscorestring, 3);
    }
    if (nextChanged) {
        drawNext();
        nextChanged = false;
    }
    
    int cellSize = winSize / height - 5;
    int col = whoNotified.getPosition().x;
    int row = whoNotified.getPosition().y + 2;
    State curState = whoNotified.getState();
    
    switch(curState) {
        case State::Hint:
            xw.drawBigString((col * cellSize) + 2, (row * cellSize) + 25, "x");
            break;
        case State::Star:
            xw.fillRectangle(col * cellSize, row * cellSize, cellSize, cellSize, Xwindow::Black);
            break;
        case State::I:
            xw.fillRectangle(col * cellSize, row * cellSize, cellSize, cellSize, Xwindow::Green);
            break;
        case State::J:
            xw.fillRectangle(col * cellSize, row * cellSize, cellSize, cellSize, Xwindow::Blue);
            break;
        case State::L:
            xw.fillRectangle(col * cellSize, row * cellSize, cellSize, cellSize, Xwindow::Red);
            break;
        case State::O:
            xw.fillRectangle(col * cellSize, row * cellSize, cellSize, cellSize, Xwindow::Cyan);
            break;
        case State::S:
            xw.fillRectangle(col * cellSize, row * cellSize, cellSize, cellSize, Xwindow::Yellow);
            break;
        case State::Z:
            xw.fillRectangle(col * cellSize, row * cellSize, cellSize, cellSize, Xwindow::Orange);
            break;
        case State::T:
            xw.fillRectangle(col * cellSize, row * cellSize, cellSize, cellSize, Xwindow::Brown);
            break;
        case State::NONE:
            xw.fillRectangle(col * cellSize, row * cellSize, cellSize, cellSize, Xwindow::White);
    }
    gLevel = default_level;
    gScore = curscore;
    gHighscore = highscore;
}
