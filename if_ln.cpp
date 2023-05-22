#include "header.h"

using namespace std;

int ln_token=0;
int all_l=0;

void all_ln()
{
    all_l++;
}
bool ln_function(string equ)
{
    char* if_ln=strstr(equ.c_str(),"ln");

    if(if_ln!=nullptr)
        return true;
    else return false;
}
void ln_null()
{
    all_l = 0;
}

string if_ln(string equ)
{
    string ans4="";
    string ans5="";
    char ln_chain[1000];
    int k,j=0;
    char ln_var;

    for(int i=0;i<equ.size();i++)
    {
        if(equ[i]=='(' && i==0)
            continue;
        if(equ[i]=='(' )
        {
            if(equ[i+2]==')')
            {
                k=1;
                int n_type=char_type(equ[i+1]);
                if(n_type==1)
                    ln_var=equ[i+1];
                else if(n_type==2)
                    ln_var='\0' ;
            }
           else
           {
               ln_chain[j] = equ[i];
               j++;
               ln_chain[j]= equ[i+1];
               j++;
           }
        }
        else if(j>0)
        {
            ln_chain[j] = equ[i+1];
            j++;
        }

        if(equ[i]==')' && equ[i-2] != '(')
                ln_chain[j] = '\0' ;
    }
     bool trigono_track_ln=trigonometry_function(ln_chain);
     bool ln_track_ln=ln_function(ln_chain);

     if( k != 1 && trigono_track_ln == false && ln_track_ln == false)
     {
         if(all_l>0)
         {
             int xl=0,yl=0;
             char cl='\0';

             cout<<"d/d ";

             for(int i=0;i<equ.size();i++)
             {
                 if(equ[i] != '(' && yl==0)
                        continue ;
                 else {
                    yl++;
                    xl=char_type(equ[i]);
                    if(xl==1)
                    {
                        cl=equ[i];
                        break;
                    }
                 }
             }
             if(cl=='\0')
            {
                cl='x';
                cout<<cl;
             }
             else cout<<cl;

             cout<<ln_chain<<"/";
         }
         ans4 +="(";
         ans4 +=for_partition(ln_chain);

         ans4 +="/";
         for(int i=0; ln_chain[i] != '\0'; i++)
            ans4 +=ln_chain[i];
         if(all_l>0)
         {
             cout<<ln_chain;
             cout<<"\n\n\t\t\t    = ";
         }

     }
     else if(k==1 && trigono_track_ln == false && ln_track_ln == false)
     {
         if(ln_var == '\0')
         {
             ans4 = "0";
             return ans4;
         }
         else
        {
            ln_chain[0] = ln_var;
            ln_chain[1] = ')' ;
            ln_chain[2] = '\0';

            ans4 +="1/" ;
            ans4 +="(" ;
            for(int i=0; ln_chain[i]!='\0'; i++)
                ans4 += ln_chain[i];
         }
     }
     else if(trigono_track_ln == true || ln_track_ln == true)
     {
         if(trigono_track_ln ==true)
         {
             if(all_l>0)
             {
                 all_trigon();
                 cout<<" First of all, we have to differentiate the part inside ln().\n\n\t\t\tSo-\n\n\t\t\t    = ";
             }
             if(k==1)
             {
                 for(int i=0;i<strlen(ln_chain);i++)
                 {
                     if(ln_chain [i] == '(' && ln_chain[i+1]== ')' )
                     {
                         ln_chain[i+1] = ln_var;
                         ln_chain[i+2] =' )' ;
                        ln_chain[i+2]  = '\0' ;
                     }
                 }
              }
              ans5 +=if_trigonometry(ln_chain);
              ans4 +=ans5;
              if(all_l>0)
              {
                  cout<<ans5;
                  cout<<"\n\n\n\t\t\tFinally-\n\n\t\t\t    = ";
              }

         }
         else if(ln_track_ln == true)
            ans4 +=if_ln(ln_chain);

         ans4+=" / ";
         for(int i=0;ln_chain[i]!='\0';i++)
         {
             if(ln_chain[i]== '(' && i==0)
                    continue;
             if(ln_chain[i]=='(' && ln_chain[i+1]=='(' )
                    continue;
             ans4+= ln_chain[i];
         }
     }
     return ans4;
}

/*


                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************

#include <bits/stdc++.h>
using namespace std;


int main()
{
    string equ; cin>>equ;
    int n=equ.size(),j=0,i;
    /*cout<<n<<endl;
    for(int i=0;i<=n;i++)
    cout<<i<<"  "<<s[i]<<endl;

     char ln_chain[1000];

     for( i=0;i<equ.size();i++)
    {
        if(equ[i]=='(' && i==0)
            continue;
        if(equ[i]=='(' )
        {
            if(equ[i+2]==')')
            {
                // k=1;
                // int n_type=char_type(equ[i+1]);
                // if(n_type==1)
                //     ln_var=equ[i+1];
                // else if(n_type==2)
                //     ln_var='\0' ;
            }
           else
           {
               ln_chain[j] = equ[i];
               j++;
               //cout<<j<<" "<<ln_chain<<endl;
               ln_chain[j]= equ[i+1];
               j++;
               cout<<j<<" "<<ln_chain<<endl;
           }
        }
        if(j>0)
        {
            ln_chain[j] = equ[i+1];
            j++;
            cout<<j<<" "<<ln_chain<<endl;
        }
    }
    cout<<i<<" "<<j<<endl;
    for(int i=0;i<strlen(ln_chain);i++)
    cout<<i<<" "<<ln_chain[i]<<endl;





}
*/
