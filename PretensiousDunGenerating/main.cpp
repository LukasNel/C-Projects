#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
struct Theme{
    string         theme;
    vector<string> objadjs;
    vector<string> objs;
    vector<string> roomadjectives;
    vector<string> trap_mechas;
    vector<string> creatures;
    vector<string> adj_entrance;
    Theme(){
        theme = "";
    }
};
struct Creature{
    string* adjectives;
    int CR;
};
vector<Creature> creatures;
vector<Theme> themes;
void Process_File(char* filename);
int main()
{
    cout << "Hello world!" << endl;
    Process_File("text.txt");
    return 0;
}

enum FSM_Process_States{
    NULLSTATE,
    THEME,
    OBJS,
    OBJADJS,
    ROOMADJS,
    TRAPMECHAS,
    CREATURES,
    DOORADJS,
    CHECK_STATE
};
void CopyInText(vector<string>& strBuffer,string& fcurStr,char fcurChar,FSM_Process_States& fcurState){
    if(fcurChar == ','){
         strBuffer.push_back(fcurStr);
         fcurStr = "";
    }else if(fcurChar == ';'){
         strBuffer.push_back(fcurStr);
         fcurStr = "";
         fcurState = CHECK_STATE;
     }else{
         fcurStr += fcurChar;
     }
}
void Process_File(char* filename){
    FILE* f ;
    f = fopen(filename,"r");
    if(f != NULL){
        char cc = 0;
        string curStr = "";
        FSM_Process_States curState = NULLSTATE;
        Theme tTheme = Theme();
        while((cc=fgetc(f))!=EOF){
            switch(curState){
                case NULLSTATE:
                    curStr = "";
                    if(cc == '['){
                        curState = THEME;
                    }

                    break;
                case THEME:
                    if(cc == '{'){
                        tTheme.theme = curStr;
                        curStr = "";
                        curState = CHECK_STATE;
                    }else if(cc != ' ' && cc != '\t'){
                        curStr+=cc;
                    }

                    break;
                case OBJADJS:

                    /*if(cc == ','){
                        tTheme.objadjs.push_back(curStr);
                        curStr = "";
                    }else if(cc == ';'){
                      tTheme.objadjs.push_back(curStr);
                      curStr = "";
                      curState = CHECK_STATE;
                    }else{
                        curStr += cc;
                    }*/
                        CopyInText(tTheme.objadjs,curStr,cc,curState);
                    break;
                case ROOMADJS:
                    if(cc == ','){
                        tTheme.roomadjectives.push_back(curStr);
                        curStr = "";
                    }else if(cc == ';'){
                      tTheme.roomadjectives.push_back(curStr);
                      curStr = "";
                      curState = CHECK_STATE;
                    }else{
                        curStr += cc;
                    }
                    break;
                case TRAPMECHAS:
                    if(cc == ','){
                        tTheme.trap_mechas.push_back(curStr);
                        curStr = "";

                    }else if(cc == ';'){
                      tTheme.trap_mechas.push_back(curStr);
                      curStr = "";
                      curState = CHECK_STATE;
                    }else{
                        curStr += cc;
                    }
                    break;
                case OBJS:
                    if(cc == ','){
                        tTheme.objs.push_back(curStr);
                        curStr = "";
                    }else if(cc == ';'){
                      tTheme.objs.push_back(curStr);
                      curStr = "";
                      curState = CHECK_STATE;
                    }else{
                        curStr += cc;
                    }
                    break;
                case CREATURES:
                    if(cc == ','){
                        tTheme.creatures.push_back(curStr);
                        curStr = "";
                    }else if(cc == ';'){
                      tTheme.creatures.push_back(curStr);
                      curStr = "";
                      curState = CHECK_STATE;
                    }else{
                        curStr += cc;
                    }
                    break;
                case DOORADJS:
                    if(cc == ','){
                        tTheme.adj_entrance.push_back(curStr);
                        curStr = "";
                    }else if(cc == ';'){
                      tTheme.adj_entrance.push_back(curStr);
                      curStr = "";
                      curState = CHECK_STATE;
                    }else{
                        curStr += cc;
                    }
                    break;
                case CHECK_STATE:
                        if(cc != ' ' && cc != '\n' && cc != '\t')curStr += cc;

                        if(!curStr.compare("Objects:")){
                            curState = OBJS;
                            curStr = "";
                        }else if(!curStr.compare("RoomAdjectives:")){
                             curState = ROOMADJS;
                             curStr = "";
                        }else if(!curStr.compare("TrapMechanisms:")){
                             curState = TRAPMECHAS;
                             curStr = "";
                        }else if(!curStr.compare("Creatures:")){
                             curState = CREATURES;
                             curStr = "";
                        }else if(!curStr.compare("DoorAdjectives:")){
                             curState = DOORADJS;
                             curStr = "";
                        }else if(!curStr.compare("ObjectAdjectives:")){
                             curState = OBJADJS;
                             curStr = "";
                        }else if(cc == '}'){
                            curState = NULLSTATE;
                            curStr = "";
                            themes.push_back(tTheme);
                            tTheme = Theme();
                        }
                    break;


            }
            cout << curStr << endl;

        }
        for(int i = 0;i<themes.size();i++){
            cout << themes[i].theme<< endl;
            for(int j = 0;j<themes[i].objadjs.size();j++)cout << themes[i].objadjs[j]<< endl;
             cout << endl;
            for(int j = 0;j<themes[i].objs.size();j++)cout << themes[i].objs[j]<< endl;
            cout << endl;
            for(int j = 0;j<themes[i].roomadjectives.size();j++)cout << themes[i].roomadjectives[j]<< endl;
            cout << endl;
            for(int j = 0;j<themes[i].trap_mechas.size();j++)cout << themes[i].trap_mechas[j]<< endl;
            cout << endl;
            for(int j = 0;j<themes[i].creatures.size();j++)cout << themes[i].creatures[j]<< endl;
            cout << endl;
            for(int j = 0;j<themes[i].adj_entrance.size();j++)cout << themes[i].adj_entrance[j]<< endl;
            cout << endl;
            }
/*

struct Theme{
    string         theme;
    vector<string> objadjs;
    vector<string> objs;
    vector<string> roomadjectives;
    vector<string> trap_mechas;
    vector<string> creatures;
    vector<string> adj_entrance;
    Theme(){
        theme = "";
    }
};*/

    }else return;

}
