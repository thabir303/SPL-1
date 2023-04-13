#include "header.h"

using namespace std;

int ex_token = 0;
int all_ex = 0;

bool exp_function(string equ)
{
    //char* if_exp = strstr(equ,"e^");
    char* if_exp=strstr(equ.c_str(),"e^");

    if(if_exp)
        return true;
    else
        return false;
}

void all_exp()
{
    all_ex++;
}
void exp_null()
{
    all_ex = 0;
}

string if_exp(string equ)
{

    string ans50 = "";
    string ans51 = "";
    char exp_chain[1000];
    int j=0,k;
    char exp_var;

    for(int i=0; i<equ.size(); i++)
    {
        if(equ[i]=='(' && i==0)
                continue;
        if(equ[i]=='(') {
            if(equ[i+2]==')'){
                k=1;
                int i_type = char_type(equ[i+1]);
                if(i_type==1)
                    exp_var = equ[i+1];
                else if(i_type==2)
                    exp_var = '\0';
            }

            else {
                exp_chain[j] = equ[i];
                j++;
                exp_chain[j] = equ[i+1];
                j++;
            }
        }

        else if(j>0) {
            exp_chain[j] = equ[i+1];
            j++;
        }

        if(equ[i]==')' && equ[i-2]!='(')
        {
            exp_chain[j] = '\0';
        }
    }

    bool trigon_tracker_exp = trigonometry_function(exp_chain);

    if(k!=1 && trigon_tracker_exp==false)
        {
        if(all_ex>0)
        {
            int x50, y50=0;
            char c50 ='\0';

            cout<<"d/d";

            for(int i=0; i<equ.size(); i++)
            {
                if(equ[i]!='(' && y50==0)
                    continue;

                else{
                    y50++;
                    x50 = char_type(equ[i]);
                    if(x50==1){
                        c50 = equ[i];
                        break;
                    }
                }
             }

            if(c50=='\0')
            {
                c50 = 'x';
                cout<<c50;
            }

            else
                cout<<c50;

            cout<<exp_chain;

            }
        ans50 += "(";
        ans50 += for_partition(exp_chain);
        ans50 += "*e^";

        for(int i=0; exp_chain[i]!='\0'; i++)
            ans50 += exp_chain[i];
        if(all_ex>0){
            cout<<"*e^"<<exp_chain;
            cout<<"\n\n\t\t\t    = ";
        }
    }

    else if(k==1 && trigon_tracker_exp==false){
        if(exp_var=='\0'){
            ans50 = "0";
            return ans50;
        }
        else {
            exp_chain[0] = exp_var;
            exp_chain[1] = ')';
            exp_chain[2] = '\0';

            ans50 += "e^";
            ans50 += "(";
            for(int i=0; exp_chain[i]!='\0'; i++)
                ans50 += exp_chain[i];
        }
    }
    else if(trigon_tracker_exp==true) {

            if(all_ex>0){
                all_trigon();
                cout<<"First of all, we have to differentiate the part at the power of e.\n\n\t\t\tSo-\n\n\t\t\t    = ";
            }

            if(k==1)
            {
                for(int i=0; i<strlen(exp_chain); i++)
               {
                    if(exp_chain[i]=='(' && exp_chain[i+1]==')')
                    {
                        exp_chain[i+1] = exp_var;
                        exp_chain[i+2] = ')';
                        exp_chain[i+3] = '\0';
                    }
                }
            }
            ans51 += if_trigonometry(exp_chain);
            ans50 += ans51;
            if(all_ex>0)
            {
                cout<<ans51;
                cout<<"\n\n\n\t\t\tFinally-\n\n\t\t\t    = ";
            }
        ans50 += "*e^";
        for(int i=0; exp_chain[i]!='\0'; i++){
            if(exp_chain[i]=='(' && i==0)
                continue;
            if(exp_chain[i]=='(' && exp_chain[i+1]=='(')
                continue;
            ans50 += exp_chain[i];
        }
    }
    return ans50;
}
