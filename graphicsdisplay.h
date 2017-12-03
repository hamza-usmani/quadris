#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include <iostream>
#include <vector>
#include "observer.h"
#include "window.h"
#include "cell.h"
#include "block.h"

class GraphicsDisplay: public Observer {
    int width, height, winSize;
    int gLevel, gScore, gHighscore;
    Xwindow xw;
    Block *next;
    bool nextChanged; 
    void drawNext();
public:
    GraphicsDisplay(int width, int height, int winSize);
    void setNext(Block *b);
    void notify(Cell &whoNotified) override;
};
#endif
