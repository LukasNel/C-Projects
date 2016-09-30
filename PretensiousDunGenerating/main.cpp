#include <iostream>

#include <stdio.h>
#include <stdlib.h>

using namespace std;
#include "ProcessFiles.h"
vector<Theme> themes;
vector<Creature> creatures;
struct Room{
    Room* roomCameFrom;
    vector<string> objs;
    vector<string> creatures;
    vector<string> entrance;
    vector<string> roomadjs;
    vector<Room*> connectingRooms;
    Room(){
        roomCameFrom = NULL;
    }
};
vector<string> MergeStrVectors(vector<string>& v1,vector<string>& v2){
    vector<string> tV;
    for(int i = 0;i<v1.size();i++)tV.push_back(v1[i]);
    for(int i = 0;i<v2.size();i++)tV.push_back(v2[i]);
    return tV;
}
void GenRoom(Room& curRoom,Theme& curTheme,int numroomsleft){
   if(numroomsleft){
    int cRand = rand()%4+1;
    for(int i = 0;i<cRand;i++)curRoom.creatures.push_back(curTheme.creatures[rand()%curTheme.creatures.size()]);
    cRand = rand()%4+1;
    for(int i = 0;i<cRand;i++)curRoom.objs.push_back(curTheme.objadjs[rand()%curTheme.objadjs.size()] + " " + curTheme.objs[rand()%curTheme.objs.size()]);
    cRand = rand()%4+1;
    for(int i = 0;i<cRand;i++)curRoom.entrance.push_back(curTheme.entrance[rand()%curTheme.entrance.size()]);
    cRand = rand()%4+1;
    for(int i = 0;i<cRand;i++)curRoom.roomadjs.push_back(curTheme.roomadjs[rand()%curTheme.roomadjs.size()]);
    cRand = rand()%4+1;
    if(curRoom.roomCameFrom){
        curRoom.roomadjs.push_back(curRoom.roomCameFrom->roomadjs[rand()%curRoom.roomCameFrom->roomadjs.size()]);
    }
   }

}
Room GenerateRoomList(vector<Theme> fthemes){
    Theme generalTheme;
    Room startRoom;
    int randomTheme1=rand()%fthemes.size(),randomTheme2=rand()%fthemes.size();
    generalTheme.theme          = fthemes[randomTheme1].theme + fthemes[randomTheme2].theme;
    generalTheme.creatures      = MergeStrVectors(fthemes[randomTheme1].creatures,      fthemes[randomTheme1].creatures);
    generalTheme.adj_entrance   = MergeStrVectors(fthemes[randomTheme1].adj_entrance,   fthemes[randomTheme1].adj_entrance);
    generalTheme.objadjs        = MergeStrVectors(fthemes[randomTheme1].objadjs,        fthemes[randomTheme1].objadjs);
    generalTheme.objs           = MergeStrVectors(fthemes[randomTheme1].objs,           fthemes[randomTheme1].objs);
    generalTheme.roomadjectives = MergeStrVectors(fthemes[randomTheme1].roomadjectives, fthemes[randomTheme1].roomadjectives);
    generalTheme.trap_mechas    = MergeStrVectors(fthemes[randomTheme1].trap_mechas,    fthemes[randomTheme1].trap_mechas);
    int roomNum = rand()%10 + 1;


}
int main()
{
    cout << "Hello world!" << endl;
    themes = Process_File("text.txt");

    return 0;
}
