

void PrintTheme(Theme ftheme){
            cout << ftheme.theme<< endl;
            for(int j = 0;j<ftheme.objadjs.size();j++)cout << ftheme.objadjs[j]<< endl;
             cout << endl;
            for(int j = 0;j<ftheme.objs.size();j++)cout << ftheme.objs[j]<< endl;
            cout << endl;
            for(int j = 0;j<ftheme.roomadjectives.size();j++)cout << ftheme.roomadjectives[j]<< endl;
            cout << endl;
            for(int j = 0;j<ftheme.trap_mechas.size();j++)cout << ftheme.trap_mechas[j]<< endl;
            cout << endl;
            for(int j = 0;j<ftheme.creatures.size();j++)cout << ftheme.creatures[j]<< endl;
            cout << endl;
            for(int j = 0;j<ftheme.adj_entrance.size();j++)cout << ftheme.adj_entrance[j]<< endl;
            cout << endl;

}
inline void GrabText(vector<string>& strBuffer,string& fcurStr,char fcurChar,FSM_Process_States& fcurState){
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

vector<Theme> Process_File(char* filename){
    vector<Theme> fthemes;
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

                    GrabText(tTheme.objadjs,curStr,cc,curState);
                    break;
                case ROOMADJS:

                    GrabText(tTheme.roomadjectives,curStr,cc,curState);
                    break;
                case TRAPMECHAS:

                    GrabText(tTheme.trap_mechas,curStr,cc,curState);

                    break;
                case OBJS:

                    GrabText(tTheme.objs,curStr,cc,curState);
                    break;
                case CREATURES:

                    GrabText(tTheme.creatures,curStr,cc,curState);
                    break;
                case DOORADJS:

                    GrabText(tTheme.adj_entrance,curStr,cc,curState);
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

                            fthemes.push_back(tTheme);
                            tTheme = Theme();

                        }
                    break;


            }
            cout << curStr << endl;

        }
        for(int i = 0;i<fthemes.size();i++){
          PrintTheme(fthemes[i]);
        }
    }
    return fthemes;

}

