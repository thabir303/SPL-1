#include "header.h"

using namespace std;

int token[1000];
int p=0;

bool an_alphabet(char s)
{
    if((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
        return true;
    else
        return false;
}

bool a_digit(char s)
{
    if(s >= '0' && s <= '9')
        return true;
    else
        return false;
}

bool an_operator(char  s)
{
    if(s=='+' || s== '-' || s== '*' || s=='/' )
        return true;
    else
        return false;
}
bool a_power(char  s)
{
    if(s== '^' )
        return true;
    else
        return false;
}
bool a_bracket(char  s)
{
    if(s == '(' || s == ')' || s == '[' || s == ']' || s == '{' || s =='}')
        return true;
    else
        return false;
}

void all_partition()
{
    p++;
}
void partition_null()
{
    p=0;
}

int for_know_type(string equ)
{
    int xk=0,as_we_k=0;
    char sk='\0';
    for(int i=0;i<equ.size();i++)
    {
        xk=char_type(equ[i]);
        if(xk==3)
        {
            if(equ[i-1]=='(')
                continue;
            else if(equ[i]=='*')
                continue;
            else if(equ[i-1]!='^')
                sk = equ[i];
            else
                continue;
        }
        if(sk=='+' || sk == '-' || equ[i]==')')
        {
                as_we_k++;
        }
        sk='\0';
    }
    return as_we_k;
}
void uplusv(string equ, char caa)
{
    int x13=0;
    char s13='\0';
    string temp_equ = "";
    for(int i=0; i<equ.size(); i++)
    {
        x13 = char_type(equ[i]);
        if(x13==3)
        {
            if(equ[i-1]=='(')
                continue;
            else if(equ[i]=='*')
            {
                temp_equ += equ[i];
                continue;
            }
            else if(equ[i-1]!='^')
                s13 = equ[i];
            else {
                temp_equ += equ[i];
                continue;
            }
        }
        if(equ[i]=='(')
            continue;
        if(s13=='\0')
            temp_equ += equ[i];

        if(s13=='+' || s13=='-' || equ[i]==')')
        {
            cout<<"d/d"<<caa<<"(";
            if(equ[i]==')')
                cout<<temp_equ;
            else
                cout<<temp_equ<<") "<<s13<<" ";
            temp_equ = "";
        }
         s13 = '\0';
    }
    cout<<"\n\n\t\t\t    =  ";
}
string Partition(string equ,int size)
{
    char variable;
    int pow=1,coeffi=1;
    char sign='\0';
    string ans2="";

    for(int i=0; i<size; i++)
    {
        if(token[i]==1)
        {
            variable = equ[i];
            if(token[i+1] != 4)
                pow=1;  /// (5*x)
            if(equ[i-1] == '+')
                coeffi=1;   /// (3+x)
            else if(equ[i-1] == '-')
                coeffi=-1; /// (3-x)
        }
        else if(token[i]==2)
        {
            if(equ[i+1] == '*' )
                coeffi = (int)(equ[i])-48;
            if(equ[i-1]=='-' && equ[i-2]=='(')
            {
                coeffi=coeffi*(-1);
            }
            if( (equ[i-2] != '^' ) && (equ[i-1]=='+' || equ[i-1]=='-' ) && (equ[i+1]=='+' || equ[i+1]=='-' ) )
                coeffi=1321;
            else if( (equ [i-2] !='^' ) && (equ[i-1]=='+' || equ[i-1]=='-' ) && ( equ[i+1]=='(' || equ[i+1] ==')' ))
            {
                coeffi = 1322;
                variable = equ[i];
            }
            else if((equ[i-1]=='(' || equ[i-1]==')' ) && ( equ [i+1]=='+' || equ[i+1]== '-' ) )
            {
                coeffi = 1323;
                variable = equ[i];
            }
            else if((equ[i-1]=='(' || equ[i-1]==')') && (equ[i+1]=='(' || equ[i+1]==')'))
            {
                coeffi = 1324;
                variable = equ[i];
            }
        }
        else if(token[i]==3)
        {
            if(equ[i] == '*')
                continue;
            else if(equ[i-1] == '(')
                continue;
            else if(equ[i-1] != '^')
                sign = equ[i];
            else
                continue;
        }
        else if(token[i]==4)
        {
            if(token [i+1] ==2)
                pow = (int)(equ[i+1])-48;
            else if(equ[i+1]== '-' )
            {
                pow = (int)(equ[i+2])-48;
                pow = -pow ;
            }
        }
             if(sign=='+' || sign=='-' || equ[i]==')')
             {
                 ans2 +=derivative(variable,pow,coeffi,sign);
                 if(p>0 && coeffi != 1323)
                      cout<<")";

                sign='\0';
                coeffi = 1;
                pow = 1;

             }
        }
        coeffi=0;
        pow=0;
        variable='\0';
        sign='\0';
        null_universe();
        ans2+=")";
        if(p>0)
            cout<<"\n\n\t\t\t    =  ";
    return ans2;
}

string for_partition(string equ)
{
    int size=0;
    for (int i = 0; equ[i] ; i++)
        size++;

    for(int i=0; i<size; i++)
    {

        if(an_alphabet(equ[i]))
            token[i] = 1;
        else if(a_digit(equ[i]))
            token[i] = 2;
        else if(an_operator(equ[i]))
            token[i] = 3;
        else if(a_power(equ[i]))
            token[i] = 4;
        else if(a_bracket(equ[i]))
            token[i] = 5;
    }
    string ans1 = "";
    ans1 += Partition(equ,size);
    return ans1;
}
