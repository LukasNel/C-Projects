#ifndef PROCESSFILES_H_INCLUDED
#define PROCESSFILES_H_INCLUDED
#include <string>
#include <vector>
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
vector<Theme>  Process_File(char* filename);
inline void GrabText(vector<string>& strBuffer,string& fcurStr,char fcurChar,FSM_Process_States& fcurState);
void PrintTheme(Theme ftheme);


#include "ProcessFiles.cpp"
#endif // PROCESSFILES_H_INCLUDED
