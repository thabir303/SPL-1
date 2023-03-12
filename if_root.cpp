#include "header.h"

using namespace std;

int token_root=0;
int all_r=0;

bool root_function(string equ)
{
    const char* if_root=strstr(equ.c_str(),"sqrt");

    if(if_root)
        return true;

    else return false;
}


void all_root(){
    all_r++;
}

string if_root(string equ)
{

    string ans8="";
    string root_chain;
    int j=0,k;
    char root_var;

    for(int i=0; i<equ.size(); i++)
    {

        if(equ[i]=='(')
        {
            if(equ[i+2]==')' && equ[i+3]==')')
            {
                k=1;
                int if_type=char_type(equ[i+1]);
                if(if_type==1)
                    root_var=equ[i+1];
                else if(if_type==2)
                    root_var='\0';
            }
        }
        else
        {
            root_chain[j]=equ[i+1];
            j++;
        }
        if(equ[i]==')')
        {
            root_chain[j] = '\0';
        }
    }

    bool trigono_track_root = trigonometry_function(root_chain);
    bool ln_track_root = ln_function(root_chain);

    if(k!=1 && trigono_track_root==false && ln_track_root==false)
    {

        ans8 += "(";
        ans8 += for_partition(root_chain);

        ans8 += "/2*sqrt";
        for(int i=0; root_chain[i]!='\0'; i++)
            ans8 += root_chain[i];
    }

    else if(k==1 && trigono_track_root==false && ln_track_root==false)
    {
        if(all_r>0)
        {
            int xr, yr=0;
            char cr ='\0';

            cout<<"d/d";

            for(int i=0; i<equ.size(); i++)
            {
                if(equ[i]!='(' && yr==0)
                    continue;

                else
                {
                    yr++;
                    xr = char_type(equ[i]);
                    if(xr==1)
                    {
                        cr = equ[i];
                        break;
                    }
                }
            }

            if(cr=='\0')
            {
                cr = 'x';
                cout<<cr;
            }

            else
                cout<<cr;

            cout<<root_chain<<"/";

        }

        if(root_var=='\0')
        {
            ans8 = "0";
            return ans8;
        }
        else
        {
            root_chain[0] = root_var;
            root_chain[1] = ')';
            root_chain[2] = '\0';

            ans8 += "1/";
            ans8 += "2*sqrt(";
            for(int i=0; root_chain[i]!='\0'; i++)
                ans8 += root_chain[i];
        }

        if(all_r>0)
        {
            cout<<root_chain;
            cout<<"\n\n\t\t\t    = ";
        }
    }

    else if(trigono_track_root==true || ln_track_root==true)
    {
        if(trigono_track_root==true)
            ans8 += if_trigonometry(root_chain);

        else if(ln_track_root==true)
            ans8 += if_ln(root_chain);

        ans8 += "/2*sqrt(";
        for(int i=0; root_chain[i]!='\0'; i++)
        {
            if(root_chain[i]=='(' && i==0)
                continue;
            if(root_chain[i]=='(' && root_chain[i+1]=='(')
                continue;
            ans8 += root_chain[i];
        }
        ans8 += ")";
    }
    return ans8;
}
