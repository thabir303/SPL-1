#include "header.h"

string n_to_s(int n)
{
    string num_string="";
    if(n>9)
    {
        int new_num1=n/10;
        num_string+=(48 + new_num1);

        int new_num2 = n -(new_num1) * 10;
        num_string += (48 + new_num2);
    }
    else {
        num_string += (48 + n);
    }

    return num_string;
}
int char_type(char c)
{

    if(an_alphabet(c))
        return 1;
    else if(a_digit(c))
        return 2;
    else if(an_operator(c))
        return 3;
    else if(a_power(c))
        return 4;
    else if(a_bracket(c))
        return 5;
    else
        return 0;
}
char* c_str(string s)
{
    char c[100];

    for(int i=0; i<100; i++)
    {
        c[i] = s[i];
    }
    c[s.size()] = '\0';
    for(int i=0; i<strlen(c); i++)
        cout<<c[i];
    cout<<"\n";
    return c;
}
