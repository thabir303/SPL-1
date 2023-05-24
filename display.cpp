#include "header.h"
#include <algorithm>
using namespace std;

string ans ="";
vector<string>vec;

void if_algebric(string equ)
{

    int xaa,yaa;
    char caa='\0';
    yaa=for_know_type(equ);
    if(yaa==1)
    {
        cout<<"\n\n\t\t"<<"We know that -"<<"\n\n\t\t\t";
        cout<<"d/dx(x^n) = n*x^(n-1) [ Power Rule ] " ;
    }
    else if(yaa>1)
    {
        cout<<"\n\n\t\tWe know that - \n\n\t\t\t";
        cout<<"d/dx(u+v) = d/dx(u) + d/dx(v) ; Thus we have to find the derivatives of each parts separately\n\n\t\t\t";
        cout<<"d/dx(x^n) = n*x^(n-1) [Power Rule ]";
    }
    cout<<"\n\n\t\t"<<"Given-"<<"\n\t\t\t";
    cout<<"  f  = "<<equ<<"\n\n\t\t    d/d";

    for(int i=0; i<equ.size(); i++)
    {
        xaa = char_type(equ[i]);
        if(xaa==1)
        {
            caa = equ[i];
            break;
        }
    }
    if(caa=='\0')
    {
        caa='x';
        cout<<caa;
    }
    else cout<<caa;
    cout<<"(f) = d/d"<<caa<<equ<<"\n\n\t\t\t    = ";
    if(yaa>1)
    {
        uplusv(equ,caa);
    }
    cout<<"(";
    ans+="(";
    algebraic();
    all_partition();
    ans+=for_partition(equ);
    vec.push_back(ans);
}
void display2()
{
    cout<<"\n\n\n\t\t\t Welcome to DERIVATIVE CALCULATOR\n\n";
    cout<<"\t\t\t Enter an Equation (Press '1' ) \n";
    cout<<"\t\t\t Exit (Press '2') \n\n";
    cout<<"\n\t\t\t Enter your choice : \n\n\t\t\t";

}
//ln(tan(x^3+3*x))
//tan(ln(x^2+4*x))
//(x^2+3*x+8*x^3+6*x^3+x^4+x^5+x^6+x^7+x^8 + x ^ 9    )
//tan(x^2+3*x+8*x^3+5)
//(x^3+ 4* x +7)*(3*x^2)
//tan(x)*ln(x)
//(3*x^2)*tan(x)
//(2*x)/ln(3*x^2)
//sqrt(3*x^5)
//(x^2+3*x)*ln(x^2+3*x)
//tan(x)/(x^3)
//(x^5)*sin(x)
//sqrt(tan(ln(x^3+3*x)
//sqrt(ln(tan(x^3+3*x)
//e^(tan(ln(x^3+3*x)
//e^(ln(tan(x^3+3*x)
///ln(e^(tan(x^3+3*x)
//ln(tan(e^(x^3+3*x)
//sqrt(sqrt(x^3+3*x)
//ln(ln(tan(x^3+3*x)
string removeSpaces(string equ)
{
    string rs;
    for(char c : equ)
    {
        if(!isspace(c)){
            rs+=c;
        }
    }
    return rs;
}
void display()
{
    while(true)
    {
    display2();

    int choice ; cin >> choice;
    cin.ignore();

    if(choice == 1)
    {
        string equ;
        cout<<"Input Equation : ";

        getline(cin,equ);

        equ=removeSpaces(equ);

        cout<<"\n\n\t\tAnswer :  ";

        partition_null();
        algebraic_null();

        bool uv_tracker = uv_function(equ);
        bool udivbyv_tracker=udivbyv_function(equ);

        if(uv_tracker==true)
        {
            ans += if_uv(equ);
            vec.push_back(ans);
            ans = "";
        }
        else if(udivbyv_tracker==true)
        {
            ans +=if_udivbyv(equ);
            vec.push_back(ans);
            ans="";
        }
        else
        {
            bool trigonometry_track = trigonometry_function(equ);
            bool ln_track = ln_function(equ);
            bool root_track = root_function(equ);
            bool exp_tracker = exp_function(equ);

     queue<string> stc;

    string temp="";

    for(int i=0;i<equ.size();i++){

        if(equ[i]==')'){
            stc.push(temp);
            break;
        }

        if(equ[i]=='('){
            stc.push(temp);
            temp="";
        }
        else{
            temp+=equ[i];
        }
    }

        string match=stc.front();

        if(match=="tan" || match=="sin" || match=="cos" || match=="cosec" || match=="cot"|| match=="sec")
        {
                all_trigon();
                int xtt,ytt=0;
                char ctt='\0';

                cout<<"\n\n\t\t" <<"Given Equation - ";
                cout<<"\n\t\t\t " <<"  f = "<<equ<<"\n\n\t\t    d/d";

                for(int i=0; i<equ.size(); i++)
                {
                    if(equ[i] != '(' && ytt==0)
                        continue;
                    else
                    {
                        ytt++;
                        xtt=char_type(equ[i]);
                        if(xtt==1 && xtt=='x')
                        {
                            ctt = equ[i];
                            break;
                        }
                    }
                }
                if(ctt=='\0')
                {
                    ctt  = 'x';
                    cout<<ctt;
                }
                else
                    cout<<ctt;

                cout<<"(f)  = d/d"<<ctt<<" "<<equ<<"\n\n\t\t\t   = ";

                ans +=if_trigonometry(equ);
                vec.push_back(ans);
                ans = "";
                trigo_null();
         }
        else if(match=="ln" )
            {
                all_ln();
                int xll,yll=0;
                char cll = '\0';

                cout<<"\n\n\t\t" <<"Given Equation - ";
                cout<<"\n\t\t\t " <<"   f = "<<equ<<"\n\n\t\t    d/d";

                for(int i=0; i<equ.size(); i++)
                {
                    if(equ[i] != '(' && yll==0)
                        continue;
                    else
                    {
                        if(char_type(equ[i+1])==1 && char_type(equ[i+2])==1)
                            continue;
                        yll++;
                        xll = char_type(equ[i]);
                        if(xll==1 && xll=='x')
                        {
                            cll=equ[i];
                            break;
                        }
                    }
                }
                if(cll=='\0')
                {
                    cll='x';
                    cout<<cll;
                }
                else
                    cout<<cll;

                cout<<"(f) = d/d"<<cll<<" "<<equ<<"\n\n\t\t\t    = ";

                ans += if_ln(equ);
                vec.push_back(ans);
                ans="";
                ln_null();
            }
            else if(match=="sqrt")
            {
                all_root();
                int xrr,yrr=0;
                char crr='\0';

                cout<<"\n\n\t\t"<<"Given-"<<"\n\t\t\t";
                cout<<"  f = "<<equ<<"\n\n\t\t    d/d";

                for(int i=0; i<equ.size(); i++)
                {
                    if(equ[i]!='(' && yrr==0)
                        continue;

                    else
                    {
                        yrr++;
                        xrr = char_type(equ[i]);
                        if(xrr==1 && xrr=='x')
                        {
                            crr = equ[i];
                            break;
                        }
                    }
                }
                if(crr=='\0')
                {
                    crr = 'x';
                    cout<<crr;
                }

                else
                    cout<<crr;

                cout<<"(f) = d/d"<<crr<<" "<<equ<<"\n\n\t\t\t    = ";

                ans += if_root(equ);
                vec.push_back(ans);
                ans="";
                root_null();
            }
            else if(match=="e^")
            {
                all_exp();
                int xee, yee=0;
                char cee ='\0';

                cout<<"\n\n\t\t"<<"Given-"<<"\n\t\t\t";
                cout<<"  f = "<<equ<<"\n\n\t\t    d/d";

                for(int i=0; i<equ.size(); i++)
                {
                    if(equ[i]!='(' && yee==0)
                        continue;
                    else
                    {
                        if(char_type(equ[i+1])==1 && char_type(equ[i+2])==1)
                        {
                            continue;
                        }
                        yee++;
                        xee = char_type(equ[i]);
                        if(xee==1 && xee=='x')
                        {
                            cee = equ[i];
                            break;
                        }
                    }
                }

                if(cee=='\0')
                {
                    cee = 'x';
                    cout<<cee;
                }

                else
                    cout<<cee;

                cout<<"(f) = d/d"<<cee<<" "<<equ<<"\n\n\t\t\t    = ";

                ans += if_exp(equ);
                vec.push_back(ans);
                ans = "";
                exp_null();
            }
            else
            {
                if_algebric(equ);
            }
        }

        for(int i=0; i<vec.size(); i++)
            cout<<vec[i];
        cout<<"\t"<<"[Answer]"<<endl;

        ans="";
        vec.clear();
}
    else if( choice == 2)
    {
        //cout<<"\n\t\t Thanks for using this .\n";
        exit(1);
    }
    else
        cout<<"\t\t Please choice a valid option .\n";
}
}

















/*************************************************************













#include "header.h"
#include <algorithm>
using namespace std;

string ans ="";
vector<string>vec;

void if_algebric(string equ)
{

    int xaa,yaa;
    char caa='\0';
    yaa=for_know_type(equ);
    if(yaa==1)
    {
        cout<<"\n\n\t\t"<<"We know that -"<<"\n\n\t\t\t";
        cout<<"d/dx(x^n) = n*x^(n-1) [ Power Rule ] " ;
    }
    else if(yaa>1)
    {
        cout<<"\n\n\t\tWe know that - \n\n\t\t\t";
        cout<<"d/dx(u+v) = d/dx(u) + d/dx(v) ; Thus we have to find the derivatives of each parts separately\n\n\t\t\t";
        cout<<"d/dx(x^n) = n*x^(n-1) [Power Rule ]";
    }
    cout<<"\n\n\t\t"<<"Given-"<<"\n\t\t\t";
    cout<<"  f  = "<<equ<<"\n\n\t\t    d/d";

    for(int i=0; i<equ.size(); i++)
    {
        xaa = char_type(equ[i]);
        if(xaa==1)
        {
            caa = equ[i];
            break;
        }
    }
    if(caa=='\0')
    {
        caa='x';
        cout<<caa;
    }
    else cout<<caa;
    cout<<"(f) = d/d"<<caa<<equ<<"\n\n\t\t\t    = ";
    if(yaa>1)
    {
        uplusv(equ,caa);
    }
    cout<<"(";
    ans+="(";
    algebraic();
    all_partition();
    ans+=for_partition(equ);
    vec.push_back(ans);
}
void display2()
{
    cout<<"\n\n\n\t\t\t Welcome to DERIVATIVE CALCULATOR\n\n";
    cout<<"\t\t\t Enter an Equation (Press '1' ) \n";
    cout<<"\t\t\t Exit (Press '2') \n\n";
    cout<<"\n\t\t\t Enter your choice : \n\n\t\t\t";

}
//ln(tan(x^3+3*x)
//tan(ln(x^2+4*x)
//(x^2+3*x+8*x^3+6*x^3+x^4+x^5+x^6+x^7+x^8 + x ^ 9    )
//tan(x^2+3*x+8*x^3+5)
//(x^3+ 4* x +7)*(3*x^2)
//tan(x)*ln(x)
//(3*x^2)*tan(x)
//(2*x)/ln(3*x^2)
//sqrt(3*x^5)
//(x^2+3*x)*ln(x^2+3*x)
//tan(x)/(x^3)
//(x^5)*sin(x)
string removeSpaces(string equ)
{
    string rs;
    for(char c : equ)
    {
        if(!isspace(c))
        {
            rs+=c;
        }
    }
    return rs;
}
void display()
{
    while(true)
    {
        display2();

        int choice ;
        cin >> choice;
        cin.ignore();

        if(choice == 1)
        {
            string equ;
            cout<<"Input Equation : ";
            //cin >> noskipws >> equ;
            getline(cin,equ);
            //cin>>equ;
            equ=removeSpaces(equ);

            cout<<"\n\n\t\tAnswer :  ";

            partition_null();
            algebraic_null();

            bool uv_tracker = uv_function(equ);
            bool udivbyv_tracker=udivbyv_function(equ);

            if(uv_tracker==true)
            {
                ans += if_uv(equ);
                vec.push_back(ans);
                ans = "";
            }
            else if(udivbyv_tracker==true)
            {
                ans +=if_udivbyv(equ);
                vec.push_back(ans);
                ans="";
            }
            else
            {
                    bool trigonometry_track = trigonometry_function(equ);
                    bool ln_track = ln_function(equ);
                    bool root_track = root_function(equ);
                    bool exp_tracker = exp_function(equ);

                /*****************************************************
                         stack<string>st;
                         string value;
                         string word="";
                         for(int i=0;i<equ.size();i++)
                         {
                             if(equ[i]=='(')
                             {
                                 vector<string>keywords={"e^","sqrt","tan"};
                                 for(string ele : keywords)
                                 {
                                     if(word==ele)
                                     {
                                         st.push(word);

                                     }

                                 }
                                 word="";

                             }
                             else if(equ[i]==')')
                             {
                                 value=st.top();
                                 st.pop();
                                 break;
                             }
                          else word+=equ[i];
                         }
                         while(!st.empty())
                         {
                             string temp;
                             temp=st.top();
                             st.pop();

                             s.

                         }



                 ***********************************************************************/

                /***************************************************/

               /* stack<string>stc;
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
                string tempstc="";
                tempstc+="("+stc.top()+")";
                //stc.first
                while(!stc.empty())
                {
                    bool trigonometry_track = trigonometry_function(tempstc);
                    bool ln_track = ln_function(tempstc);
                    bool root_track = root_function(tempstc);
                    bool exp_tracker = exp_function(tempstc);

                if(trigonometry_track )
                {
                    all_trigon();
                    int xtt,ytt=0;
                    char ctt='\0';

                    cout<<"\n\n\t\t" <<"Given Equation - ";
                    cout<<"\n\t\t\t " <<"  f = "<<equ<<"\n\n\t\t    d/d";

                    for(int i=0; i<tempstc.size(); i++)
                    {
                        if(tempstc[i] != '(' && ytt==0)
                            continue;
                        else
                        {
                            ytt++;
                            xtt=char_type(equ[i]);
                            if(xtt==1)
                            {
                                ctt = equ[i];
                                break;
                            }
                        }
                    }
                    if(ctt=='\0')
                    {
                        ctt  = 'x';
                        cout<<ctt;
                    }
                    else
                        cout<<ctt;

                    cout<<"(f)  = d/d"<<ctt<<" "<<equ<<"\n\n\t\t\t   = ";

                    ans +=if_trigonometry(tempstc);
                    vec.push_back(ans);
                    ans = "";
                    trigo_null();
                }
                else if(ln_track)
                {
                    all_ln();
                    int xll,yll=0;
                    char cll = '\0';

                    cout<<"\n\n\t\t" <<"Given Equation - ";
                    cout<<"\n\t\t\t " <<"   f = "<<equ<<"\n\n\t\t    d/d";

                    for(int i=0; i<tempstc.size(); i++)
                    {
                        if(tempstc[i] != '(' && yll==0)
                            continue;
                        else
                        {
                            if(char_type(tempstc[i+1])==1 && char_type(tempstc[i+2])==1)
                                continue;
                            yll++;
                            xll = char_type(tempstc[i]);
                            if(xll==1)
                            {
                                cll=tempstc[i];
                                break;
                            }
                        }
                    }
                    if(cll=='\0')
                    {
                        cll='x';
                        cout<<cll;
                    }
                    else
                        cout<<cll;

                    cout<<"(f) = d/d"<<cll<<" "<<equ<<"\n\n\t\t\t    = ";

                    ans += if_ln(tempstc);
                    vec.push_back(ans);
                    ans="";
                    ln_null();
                }
                else if(root_track)
                {
                    all_root();
                    int xrr,yrr=0;
                    char crr='\0';

                    cout<<"\n\n\t\t"<<"Given-"<<"\n\t\t\t";
                    cout<<"  f = "<<equ<<"\n\n\t\t    d/d";

                    for(int i=0; i<tempstc.size(); i++)
                    {
                        if(tempstc[i]!='(' && yrr==0)
                            continue;

                        else
                        {
                            yrr++;
                            xrr = char_type(tempstc[i]);
                            if(xrr==1)
                            {
                                crr = tempstc[i];
                                break;
                            }
                        }
                    }
                    if(crr=='\0')
                    {
                        crr = 'x';
                        cout<<crr;
                    }

                    else
                        cout<<crr;

                    cout<<"(f) = d/d"<<crr<<" "<<equ<<"\n\n\t\t\t    = ";

                    ans += if_root(tempstc);
                    vec.push_back(ans);
                    ans="";
                    root_null();
                }
                else if(exp_tracker)
                {
                    all_exp();
                    int xee, yee=0;
                    char cee ='\0';

                    cout<<"\n\n\t\t"<<"Given-"<<"\n\t\t\t";
                    cout<<"  f = "<<equ<<"\n\n\t\t    d/d";

                    for(int i=0; i<tempstc.size(); i++)
                    {
                        if(tempstc[i]!='(' && yee==0)
                            continue;
                        else
                        {
                            if(char_type(tempstc[i+1])==1 && char_type(tempstc[i+2])==1)
                            {
                                continue;
                            }
                            yee++;
                            xee = char_type(tempstc[i]);
                            if(xee==1)
                            {
                                cee = tempstc[i];
                                break;
                            }
                        }
                    }

                    if(cee=='\0')
                    {
                        cee = 'x';
                        cout<<cee;
                    }

                    else
                        cout<<cee;

                    cout<<"(f) = d/d"<<cee<<" "<<equ<<"\n\n\t\t\t    = ";

                    ans += if_exp(tempstc);
                    vec.push_back(ans);
                    ans = "";
                    exp_null();
                }
                else
                {
                    if_algebric(tempstc);
                    //break;
                }
                stc.pop();
                    //cout<<"Temp"<<tempstc<<endl;
                tempstc=stc.top();

                //stc.pop();
            }
*/
///e^(ln(tan(x^3+3*x)

                /******************************************************
                if(trigonometry_track  )
                {
                    all_trigon();
                    int xtt,ytt=0;
                    char ctt='\0';

                    cout<<"\n\n\t\t" <<"Given Equation - ";
                    cout<<"\n\t\t\t " <<"  f = "<<equ<<"\n\n\t\t    d/d";

                    for(int i=0; i<equ.size(); i++)
                    {
                        if(equ[i] != '(' && ytt==0)
                            continue;
                        else
                        {
                            ytt++;
                            xtt=char_type(equ[i]);
                            if(xtt==1)
                            {
                                ctt = equ[i];
                                break;
                            }
                        }
                    }
                    if(ctt=='\0')
                    {
                        ctt  = 'x';
                        cout<<ctt;
                    }
                    else
                        cout<<ctt;

                    cout<<"(f)  = d/d"<<ctt<<" "<<equ<<"\n\n\t\t\t   = ";

                    ans +=if_trigonometry(equ);
                    vec.push_back(ans);
                    ans = "";
                    trigo_null();
                }
                else if(ln_track)
                {
                    all_ln();
                    int xll,yll=0;
                    char cll = '\0';

                    cout<<"\n\n\t\t" <<"Given Equation - ";
                    cout<<"\n\t\t\t " <<"   f = "<<equ<<"\n\n\t\t    d/d";

                    for(int i=0; i<equ.size(); i++)
                    {
                        if(equ[i] != '(' && yll==0)
                            continue;
                        else
                        {
                            if(char_type(equ[i+1])==1 && char_type(equ[i+2])==1)
                                continue;
                            yll++;
                            xll = char_type(equ[i]);
                            if(xll==1)
                            {
                                cll=equ[i];
                                break;
                            }
                        }
                    }
                    if(cll=='\0')
                    {
                        cll='x';
                        cout<<cll;
                    }
                    else
                        cout<<cll;

                    cout<<"(f) = d/d"<<cll<<" "<<equ<<"\n\n\t\t\t    = ";

                    ans += if_ln(equ);
                    vec.push_back(ans);
                    ans="";
                    ln_null();
                }
                else if(root_track)
                {
                    all_root();
                    int xrr,yrr=0;
                    char crr='\0';

                    cout<<"\n\n\t\t"<<"Given-"<<"\n\t\t\t";
                    cout<<"  f = "<<equ<<"\n\n\t\t    d/d";

                    for(int i=0; i<equ.size(); i++)
                    {
                        if(equ[i]!='(' && yrr==0)
                            continue;

                        else
                        {
                            yrr++;
                            xrr = char_type(equ[i]);
                            if(xrr==1)
                            {
                                crr = equ[i];
                                break;
                            }
                        }
                    }
                    if(crr=='\0')
                    {
                        crr = 'x';
                        cout<<crr;
                    }

                    else
                        cout<<crr;

                    cout<<"(f) = d/d"<<crr<<" "<<equ<<"\n\n\t\t\t    = ";

                    ans += if_root(equ);
                    vec.push_back(ans);
                    ans="";
                    root_null();
                }
                else if(exp_tracker)
                {
                    all_exp();
                    int xee, yee=0;
                    char cee ='\0';

                    cout<<"\n\n\t\t"<<"Given-"<<"\n\t\t\t";
                    cout<<"  f = "<<equ<<"\n\n\t\t    d/d";

                    for(int i=0; i<equ.size(); i++)
                    {
                        if(equ[i]!='(' && yee==0)
                            continue;
                        else
                        {
                            if(char_type(equ[i+1])==1 && char_type(equ[i+2])==1)
                            {
                                continue;
                            }
                            yee++;
                            xee = char_type(equ[i]);
                            if(xee==1)
                            {
                                cee = equ[i];
                                break;
                            }
                        }
                    }

                    if(cee=='\0')
                    {
                        cee = 'x';
                        cout<<cee;
                    }

                    else
                        cout<<cee;

                    cout<<"(f) = d/d"<<cee<<" "<<equ<<"\n\n\t\t\t    = ";

                    ans += if_exp(equ);
                    vec.push_back(ans);
                    ans = "";
                    exp_null();
                }
                else
                {
                    if_algebric(equ);
                }
            }


            for(int i=0; i<vec.size(); i++)
                cout<<vec[i];
            cout<<"\t"<<"[Answer]"<<endl;

            ans="";
            vec.clear();
        }

        else if( choice == 2)
        {
            //cout<<"\n\t\t Thanks for using this .\n";
            exit(1);
        }
        else
            cout<<"\t\t Please choice a valid option .\n";
    }
}
**********************************/
