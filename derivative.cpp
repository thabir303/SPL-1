#include "header.h";
using namespace std;

int alg=0;
int remove_sign=0;
char total_sign='\0';
char universal_sign='\0';

void algebraic()
{
    alg++;
}
void algebraic_null()
{
    alg = 0;
}
void null_universe()
{
    universal_sign = '\0';
}
//variable,pow,coeffi,sign
string derivative(char variable,int pow,int coeffi,char sign)
{
    string ans3 ="";
    if(alg>0)
             algebraic();

    if(coeffi == 1323 )
    {
        if(alg>0)
                cout<<variable<<" *0 ) "<<sign<<" ( ";
        return ans3;
    }
    if(coeffi == 1322 )
    {
        if(alg>0)
               cout<<total_sign<<" ( "<<variable<<" *0";
        return ans3;
    }
    if(coeffi == 1321) return "";
    else if(coeffi == 1324)
    {
        ans3 += " 0 ";
        if(alg>0)
            cout<<variable<<" *0";
        return ans3;
    }
    int main_coeffi = coeffi*pow;
    int main_pow = (pow-1);

    if(total_sign == '+' || total_sign == '-')
    {
        if(main_coeffi>0)
        {
            ans3+= total_sign;
            if(alg>0)
                cout<<" "<<total_sign<<"  (";
        }
        else if( main_coeffi < 0 && main_pow != 0)
        {
            if(remove_sign== 0)
            {
                remove_sign++;
                if(total_sign=='+')
                {
                    ans3+="-";
                    if(alg>0)
                        cout<<" - (";
                }
            }
            else
            {
                if(total_sign == '+')
                {
                    ans3 += "-";
                    if(alg>0)
                        cout<<" + ( ";
                }
                else if(main_pow<0 && total_sign == '-')
                {
                    ans3+="+";
                    if(alg>0) cout<<" - (";
                }
                else
                {
                    ans3+="-";
                    if(alg>0)
                        cout<<" + ( " ;
                }
            }

        }
        else if(main_pow ==0 || main_pow ==1)
        {
            ans3 += total_sign ;
            if(alg>0)
                cout<<" "<<total_sign<<" ( ";
        }
        if(main_coeffi != 1 && main_coeffi != -1)
        {
            ans3+= n_to_s(abs(main_coeffi));
            if(alg>0)
                cout<<coeffi<<"*"<<pow;
        }
        if(main_coeffi == 1 && main_pow == 0)
        {
            ans3+="1";
            if(alg>0)
                cout<<"1";
        }
        if(main_coeffi== -1 && main_pow == 0)
        {
            ans3 += "1";
            if(alg>0)
                cout<<"1";
        }
    }
    else
    {
        if(main_coeffi != 1)
        {
            if(main_coeffi<0)
            {
                ans3 +="-";
                ans3 +=n_to_s(abs(main_coeffi));
                if(alg>0)
                    cout<<coeffi<<"*"<<pow;
            }
            else
            {
                ans3 += n_to_s(main_coeffi);
                if(alg>0)
                    cout<<coeffi<<"*"<<pow;
            }
        }
        if(main_coeffi == 1 && main_pow == 0)
        {
            ans3+= "1";
            if(alg>0)
                cout<<"1";
        }
    }
    if(main_pow != 0)
    {
        ans3+="*";
        if(alg>0)
            cout<<")*";
        ans3+= variable;
        if(alg>0)
            cout<<variable;
    }
    if(main_pow != 1 && main_pow != 0)
    {
        ans3+= "^";
        if(alg>0)
            cout<<"^";
        if(main_pow<0)
        {
            ans3 +="-";
            if(alg>0)
                cout<<"(";
            ans3+=n_to_s(abs(main_pow));
            if(alg>0)
                cout<<pow<<"-1";
        }
        else
        {
            ans3+=n_to_s(main_pow);
            if(alg>0)
                cout<<"("<<pow<<"-1";
        }

    }
    else
    {
        if(main_pow==1)
        {
            if(alg>0)
                cout<<"^";

            if(alg>0)
                cout<<"("<<pow<<"-1";
        }
        else
        {
            if(alg>0)
                cout<<")*";
            if(alg>0)
                cout<<variable;
            if(alg>0)
                cout<<"^";
            if(alg>0)
                cout<<"("<<pow<<"-1";
        }

    }
    total_sign=sign;
    remove_sign++;

    return ans3;
}
