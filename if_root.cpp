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
void all_root()
{
    all_r++;
}
void root_null()
{
    all_r=0;
}
string if_root(string equ)
{
    string ans8="";
    char root_chain[1000];
    if(equ[0]=='(')
    {
        for (int i = 0; i < equ.size()-1; i++)
        {
            equ[i] = equ[i + 1];
        }
        equ[equ.size()-1] = '\0';
    }
    if(equ[1]=='(')
    {
        for (int i = 2; i < equ.size(); i++)
        {
            equ[i-1] = equ[i];
        }
        equ[equ.size()-1] = '\0';
    }

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
            else
            {
                root_chain[j]=equ[i];
                j++;
                root_chain[j] = equ[i+1];
                j++;
            }
        }
        else if(j>0)
        {
            root_chain[j]  = equ[i+1];
            j++;
        }
        if(equ[i]==')')
        {
            root_chain[j] = '\0';
        }
    }
    int ob=0,i;
    for( i=0;i<strlen(root_chain);i++)
    {
        if(root_chain[i]=='(')
            ob++;
        else break;
    }
    for(int j=i;j<=strlen(root_chain);j++)
        root_chain[j-ob]=root_chain[j];

    bool trigono_track_root = trigonometry_function(root_chain);
    bool ln_track_root = ln_function(root_chain);
    bool exp_track_root = exp_function(root_chain);
    bool root_track_root = root_function(root_chain);

    if(k!=1 && trigono_track_root==false && ln_track_root==false && exp_track_root == false  )
    {
        ans8 += "(";
        ans8 += for_partition(root_chain);

        ans8 += "/2*sqrt(";
        for(int i=0; root_chain[i]!='\0'; i++)
            ans8 += root_chain[i];
    }

    else if(k==1 && trigono_track_root==false && ln_track_root==false && exp_track_root == false )
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
                cout<<cr<<" "<<"(";
            }

            else
                cout<<cr<<" "<<"(";

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

    else if(trigono_track_root==true || ln_track_root==true || exp_track_root == true )
    {
        string  match=str_match(root_chain);

        if(match=="ln")
            ans8 += if_ln(root_chain);
        else if(match=="e^")
            ans8+=if_exp(root_chain);

        else if(trigono_track_root)
            ans8 += if_trigonometry(root_chain);

        else if(root_track_root)
        ans8+=if_root(root_chain);

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
