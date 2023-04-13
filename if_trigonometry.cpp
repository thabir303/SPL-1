#include "header.h"
using namespace std;

int all_t=0;
int trigono_token=0,kt=0;

bool trigonometry_function(string equ)
{

    int lnCount=80,trigCount,rootCount=80;
    for(int i=0;i<equ.size();i++)
    {
        if(equ[i] == 'l')
            lnCount=i;
        else if(equ[i]=='t' || equ[i]== 's' || equ[i]=='c')
            trigCount=i;
        else if(equ[i]=='s' && equ[i+1]=='q')
            rootCount=i;
    }

    if(lnCount<trigCount)
        return false;

    if(rootCount<trigCount)
        return false;
    for(int i=0;i<equ.size();i++)
    {
        if(equ[i]=='s' && equ[i+1]=='i' && equ[i+2]=='n')
        {
            trigono_token=1;
            return true;
        }
        else if(equ[i]=='c' && equ[i+2]=='s' && equ[i+3] != 'e')
        {
            trigono_token = 2;
            return true;
        }

        else if(equ[i]=='c' && equ[i+3]=='e')
        {
            trigono_token = 3;
            return true;
        }

        else if(equ[i]=='s' && equ[i+2]=='c')
        {
            trigono_token = 4;
            return true;
        }

        else if(equ[i]=='t' && equ[i+2]=='n')
        {
            trigono_token = 5;
            return true;
        }

        else if(equ[i]=='c' && equ[i+2]=='t')
        {
            trigono_token = 6;
            return true;
        }
    }
    if(trigono_token==0)
        return false;
}

int trigono_sign()
{
    kt++;
    return trigono_token;
}
void all_trigon()
{
    all_t++;
}
void trigo_null()
{
    all_t = 0;
}
string if_trigonometry(string equ){

    string ans7="";

    char trigonometry_chain[1000];
    int j=0,k;
    char trigono_var;

    for(int i=0;i<equ.size();i++)
    {
        if(equ[i]=='(' && i==0)
            continue;
        if(equ[i]=='(' && equ[i+1] == '(')
            continue;

        if(equ[i]== '(' && i != 0)
        {
            if(equ[i+2] ==')' && equ[i+1]!='(')
            {
                k=1;
                int n_type=char_type(equ[i+1]);
                if(n_type==1)
                    trigono_var = equ[i+1];
                else if(n_type==2)
                    trigono_var = '\0';
            }
            else
            {
                trigonometry_chain[j] = equ[i];
                j++;
                trigonometry_chain[j] = equ[i+1];
                j++;
            }
        }
        else if(j>0)
        {
            trigonometry_chain[j] = equ[i+1];
            j++;
        }
        if(equ[i]==')')
        {
            trigonometry_chain[j] = '\0';
        }
    }
    if(all_t>0 && k != 1)
    {
        cout<<"d/d";

        int xt,yt=0;
        char ct='\0';

        for(int i=0;i<equ.size();i++)
        {
            if(equ[i] != '(' && yt==0)
                continue;
            if(char_type(equ[i]) == 1 && char_type(equ[i+1])==1)
                continue;
            if(char_type(equ[i])==1 && equ[i+1]=='(')
                continue;
            else
            {
                yt++;
                xt=char_type(equ[i]);
                if(xt==1)
                {
                    ct=equ[i];
                    break;
                }
            }
        }
        if(ct=='\0')
        {
            ct='x';
            cout<<ct;
        }
        else cout<<ct;

        cout<<trigonometry_chain<<"*";
    }

    if(trigono_token == 2 || trigono_token == 3 || trigono_token == 6 )
    {
        if(kt == 0 )
        {
            ans7 += "-";
            if(all_t>0 && k!=1)
                cout<<"-";
        }
    }
    if( k != 1)
    {
        ans7 += "(";
        ans7 +=for_partition(trigonometry_chain);
        ans7 +="*";
    }
    else
    {
        if(trigono_var == '\0' )
        {
            ans7 = "0";
            return ans7;
        }
        else
        {
            trigonometry_chain[0] = '(';
            trigonometry_chain[1] = trigono_var;
            trigonometry_chain[2] = ')';
            trigonometry_chain[3] = '\0';
        }
    }
    if(trigono_token==2)
    {
        if(all_t>0 && k != 1)
            cout<<"sin"<<trigonometry_chain;
        ans7 += "sin";

        for(int i=0;trigonometry_chain[i] != '\0';i++)
            ans7 += trigonometry_chain[i];
    }
    else if(trigono_token==3)
    {
        if(all_t>0 && k!=1)
            cout<<"cosec"<<trigonometry_chain<<"*cot"<<trigonometry_chain;
        ans7 += "cosec";
        for(int i=0; trigonometry_chain[i] != '\0'; i++)
            ans7 += trigonometry_chain[i];
        ans7 += "*cot";
        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans7 += trigonometry_chain[i];
    }
    else if(trigono_token==1)
    {
        if(all_t>0 && k!=1)
            cout<<"cos"<<trigonometry_chain;
        ans7 += "cos";
        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans7 += trigonometry_chain[i];
    }
    else if(trigono_token==5){
        if(all_t>0 && k!=1)
            cout<<"sec^2"<<trigonometry_chain;
        ans7 += "sec^2";
        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans7 += trigonometry_chain[i];
    }

    else if(trigono_token==6){
        if(all_t>0 && k!=1)
            cout<<"cosec^2"<<trigonometry_chain;
        ans7 += "cosec^2";
        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans7 += trigonometry_chain[i];
    }

    else if(trigono_token==4){
        if(all_t>0 && k!=1)
            cout<<"sec"<<trigonometry_chain<<"*tan"<<trigonometry_chain;
        ans7 += "sec";
        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans7 += trigonometry_chain[i];
        ans7 += "*tan";
        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans7 += trigonometry_chain[i];
    }
    if(all_t>0 && k != 1)
        cout<<"\n\n\t\t\t     = ";
     trigono_token = 0;
     kt=0;
    return ans7;
    trigo_null();
}
