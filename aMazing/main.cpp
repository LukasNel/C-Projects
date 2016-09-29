#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "ConsoleFunctions.h"
using namespace std;
bool Quit = false;
void reArrange(int* farray,int flen){
    int ci = 0;
    for(int i = 0;i<flen;i++){
        ci = rand()%flen;
        farray[i]  = farray[i] + farray[ci];
        farray[ci] = farray[i] - farray[ci];
        farray[i]  = farray[i] - farray[ci];

    }
}
void Maze_Gen_Recursive_Back_Tracker(short* maze,char* fdirections,int fx,int fy, int fmaxX,int fmaxY){
    for(int i = 0;i<4;i++){
        fdirections[i] = i;
    }
    reArrange(fdirections,4);
    maze[fx + fy*fmaxX] |= 1<<5;
    for(int i = 0;i<4;i++){
        switch(fdirections[i]){
            case 0:break;
            case 1:break;
            case 2:break;
            case 3:break;
            default:break;
        }

    }
}
void MazeGenRecursiveBackTracking(CHAR_INFO* fworldmap,int fmaxX,int fmaxY){
    short* maze = new short[fmaxX*fmaxY];


}
int main()
{
    int maxX = 50,maxY = 50;
    CONSOLE_SCREEN_BUFFER_INFO csbi = screenInfo();

    maxX = csbi.srWindow.Right;
    maxY = csbi.srWindow.Bottom;


    CHAR_INFO* worldmap = NULL;
    worldmap = new CHAR_INFO[maxX*maxY];
    ClearBuffer(worldmap,maxX,maxY);

    while(!Quit){



    }
    return 0;
}
