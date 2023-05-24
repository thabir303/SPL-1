#include "header.h"

string str_match(string equ)
{
    queue<string> stc;

    string temp="";

    for(int i=0; i<equ.size(); i++)
    {
        if(equ[i]==')')
        {
            stc.push(temp);
            break;
        }

        if(equ[i]=='(')
        {
            stc.push(temp);
            temp="";
        }
        else
        {
            temp+=equ[i];
        }
    }
    string match=stc.front();
    if(match[0]=='(')
    {
        for (int i = 0; i < match.size()-1; i++)
        {
            match[i] = match[i + 1];
        }
        match[match.size()-1] = '\0';
    }
    return match;
}
