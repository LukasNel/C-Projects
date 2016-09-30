#include <iostream>

#include <stdio.h>
#include <stdlib.h>

using namespace std;
#include "ProcessFiles.h"

struct Room{
    int directionOfRoomCameFrom;
    Room* roomCameFrom;
    vector<string> objs;
    vector<string> creatures;
    vector<string> entrance;
    vector<string> roomadjs;
    vector<Room*> connectingRooms;
    Room(){
        roomCameFrom = NULL;
        directionOfRoomCameFrom = 0;
    }
};
vector<string> MergeStrVectors(vector<string>& v1,vector<string>& v2){
    vector<string> tV;
    for(int i = 0;i<v1.size();i++)tV.push_back(v1[i]);
    for(int i = 0;i<v2.size();i++)tV.push_back(v2[i]);
    return tV;
}
void GenRoom(Room& curRoom,Theme& curTheme,int numroomsleft){

    int cRand = rand()%4+1;
    for(int i = 0;i<cRand;i++)curRoom.creatures.push_back(curTheme.creatures[rand()%curTheme.creatures.size()]);
    cRand = rand()%4+1;
    for(int i = 0;i<cRand;i++)curRoom.objs.push_back(curTheme.objadjs[rand()%curTheme.objadjs.size()] + " " + curTheme.objs[rand()%curTheme.objs.size()]);
    cRand = rand()%4+1;
    for(int i = 0;i<cRand;i++)curRoom.entrance.push_back(curTheme.adj_entrance[rand()%curTheme.adj_entrance.size()]);
    cRand = rand()%4+1;
    for(int i = 0;i<cRand;i++)curRoom.roomadjs.push_back(curTheme.roomadjectives[rand()%curTheme.roomadjectives.size()]);
    cRand = rand()%4+1;
    if(curRoom.roomCameFrom){
        curRoom.roomadjs.push_back(curRoom.roomCameFrom->roomadjs[rand()%curRoom.roomCameFrom->roomadjs.size()]);
    }
    if(numroomsleft){
        cRand = rand()%4;
        for(int i = 0;i<cRand;i++){
            Room* nextRoom = new Room();
            nextRoom->roomCameFrom = &curRoom;
            nextRoom->directionOfRoomCameFrom = (curRoom.directionOfRoomCameFrom + i)%4;
            curRoom.connectingRooms.push_back(nextRoom);
        }
        for(int i = 0;i<curRoom.connectingRooms.size();i++){
            GenRoom((*curRoom.connectingRooms[i]),curTheme,numroomsleft-1);
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
    int roomNum = rand()%5 + 1;
    GenRoom(startRoom,generalTheme,roomNum);
    return startRoom;
}
void PrintRoom(Room& froom, int curRoomNum){
    cout << endl << "Room " << curRoomNum << endl;
    for(int i = 0;i<froom.creatures.size();i++)cout << froom.creatures[i] << endl;
    for(int i = 0;i<froom.roomadjs.size();i++)cout << froom.roomadjs[i] << endl;
    for(int i = 0;i<froom.objs.size();i++)cout << froom.objs[i] << endl;
    cout << "Has a ";
    for(int i = 0;i<froom.entrance.size();i++)cout << froom.entrance[i] << " ";
    cout << " door";
    for(int i = 0;i<froom.connectingRooms.size();i++)PrintRoom((*froom.connectingRooms[i]),curRoomNum+i+1);
}
void OutputDungeon(Room &froom,char* filename){
FILE* f;
f = fopen(filename);

fclose(f);
}
void OutputRooms(Room& froom, int curRoomNum,FILE* f){
    fprintf(f,"\nRoom %i\n",curRoomNum);
    for(int i = 0;i<froom.creatures.size();i++){fprintf(f,froom.creatures[i].c_str());fprintf(f,"\n");}
    for(int i = 0;i<froom.roomadjs.size();i++){fprintf(f,froom.creatures[i].c_str());fprintf(f,"\n");}
    for(int i = 0;i<froom.objs.size();i++){fprintf(f,froom.creatures[i].c_str());fprintf(f,"\n");}
    fprintf(f,"Has a ");
    for(int i = 0;i<froom.entrance.size();i++){fprintf(f,froom.creatures[i].c_str());fprintf(f," ");}
     fprintf(f," door");
    for(int i = 0;i<froom.connectingRooms.size();i++)PrintRoom((*froom.connectingRooms[i]),curRoomNum+i+1);
}
int main()
{
    vector<Theme> themes;
    vector<Creature> creatures;
    cout << "Hello world!" << endl;
    themes = Process_File("text.txt");
    Room cRoom = GenerateRoomList(themes);
    PrintRoom(cRoom,1);
    return 0;
}
