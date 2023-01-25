 #include "header.h"

int token[1000];

bool an_alphabte(char  s)
{
     if((s>=97 && s<=122) or (s>=65 && s<=90))
           return true;
    else
    return false;

}
bool a_digit(char  s)
{
     if(s>=48 && s<=57)
           return true;
    else
    return false;
}
bool an_operator(char  s)
{
     if(s==' + ' || s== ' - ' || s== ' * ' || s==' / ' )
           return true;
    else
    return false;
}
bool a_power(char  s)
{
     if(s== ' ^ ' )
           return true;
    else
    return false;
}
bool a_bracket(char  s)
{
     if(s == ' ( ' || s == ' )' || s == ' [ ' || s == ' ] ' || s == ' { ' || s ==' }')
           return true;
    else
    return false;
}
string Partition(string equ,int size)
{
      char variable; int pow=1,coeffi=1;
      char sign='\0';
      string ans2="";

       for(int i=0;i<size;i++)
    {
        if(token[i]==1)
        {
            variable = equ[i];
            if(token[i+1] != 4)
                pow=1;  /// (5*x)
            if(equ[i-1] == ' + ')
                 coeffi=1;   /// (3+x)
            else if(equ[i-1] == ' - ')
                 coeffi=-1; /// (3+x)
        }
        else if(token[i]==2)
        {
            if(equ[i+1] == ' * ' )  /// (5*x+10)
                coeffi = atoi(&equ[i]); ///pass the address of the variable ch
            if(equ[i-1]=='-' && equ[i-2]=='(')
            {
                    coeffi=coeffi*(-1);  /// (-5*x+10)
            }
            if( (equ[i-2] != ' ^ ' ) && (equ[i-1]=='+' || equ[i-1]=='-' ) && (equ[i+1]=='+' || equ[i+1]=='-' ) )
                    coeffi=1321;  /// (5*x^2+3+x)
            else if( (equ [i-2] !=' ^ ' ) && (equ[i-1]=='+' || equ[i-1]==' - ' ) && ( equ[i+1]==' ( ' || equ[i+1] ==')' ))
            {
                coeffi = 1322; ///(x+3)
                ///variable = equ[i];
            }
            else if((equ[i-1]=='(' || equ[i-1]==')' ) && ( equ [i+1]=='+' || equ[i+1]== '-' ) )
            {
                coeffi = 1323; /// (5+3x)
                ///variable = equ[i];
            }
            else if((equ[i-1]=='(' || equ[i-1]==')') && (equ[i+1]=='(' || equ[i+1]==')')){
                coeffi = 1324; /// (5)
                ///variable = equ[i];
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
                pow = atoi(&equ[i+1]);
            else if(equ[i+1]== '-' )
            {
                pow = atoi(&equ[i+2]);
                pow = pow * (-1);
            }
        }
        else if(token[i]==5)
        {
            if(equ[i]== '(' )
                continue;
        }
        /*if(equ[i] == ' ) ' ||  sign== '+' || sign == '-' )
        {
             //ans2=derivative(variable,pow,coeffi,sign);

            if(p>0 && coeffi != 1323)
                  cout<<")";
            sign='\0';
            coeffi = 1;
            pow = 1;
        } */

    }
    return ans2;
}

string for_partition(string equ)
{
      int size=0;
      for (int i = 0; equ[i] ; i++)
             size++;

     for(int i=0;i<size;i++)
     {

         if(an_alphabte(equ[i]))
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
     string ans = "";
     return ans += Partition(equ,size);
}
