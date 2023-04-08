#include "header.h"

using namespace std;

bool uv_function(string equ)
{

    for(int i=0; i<equ.size(); i++)
    {
        if(equ[i]=='*' && equ[i-1]==')' && (equ[i+1]=='(' || (equ[i+1] > 96 && equ[i+1] < 123)))
            return true;
        else
            continue;
    }
    return false;
}

string if_uv(string equ)
{
    string ans8 = "";
    string d_f = "", d_s = "";
    char first_uv[1000], second_uv[1000];
    int for_delimit=0, j=0, k=0, sign_comp1, sing_comp1;

    cout<<"\n\n\t\t"<<"This equation follows the UV method as it's a product of two functions."<<"\n\n\t\tWe know that -"
        <<"\n\n\t\t\t"<<"d/dx(u*v) = u*d/dx(v) + v*d/dx(u)"<<"\n\n\t\t"<<"Here-\n\n\t\t\t";

    for(int i=0; i<equ.size(); i++)
    {
       if (equ[i] == '*' && equ[i-1] == ')' && (equ[i+1] == '(' || (equ[i+1] >96 && equ[i+1] <123)))
        {
            for_delimit = 1;
            continue;
        }
        if(for_delimit==0)
        {
            first_uv[i] = equ[i];
            k++;
        }
        else if(for_delimit==1)
        {
            second_uv[j] = equ[i];
            j++;
        }
    }
    first_uv[k] = '\0';
    second_uv[j] = '\0';

    cout<<"u = "<<first_uv<<"\n\n\t\t\t";
    cout<<"v = "<<second_uv<<"\n\n\t\t\n\t\t";

    bool trigonometry_tracker2 = trigonometry_function(second_uv);
    bool ln_tracker2 = ln_function(second_uv);
    bool root_tracker2 = root_function(second_uv);
    bool exp_tracker2 = exp_function(second_uv);

    if(trigonometry_tracker2==true)
    {
        sing_comp1 = trigono_sign();

        if(sing_comp1==2 || sing_comp1==3 || sing_comp1==6)
        {
            if(if_trigonometry(second_uv)!="0")
                ans8 += "-";
        }
    }

    if(trigonometry_tracker2==true)
    {

        if(sing_comp1==2 || sing_comp1==3 || sing_comp1==6)
        {
            if(if_trigonometry(second_uv)!="0")
                d_s += "-";
        }

        string s = if_trigonometry(second_uv);
        if(s!="0")
        {
            ans8 += first_uv;
            ans8 += "*";
            ans8 += s;
        }
        d_s += s;
    }
    else if(ln_tracker2==true)
    {
        if(if_ln(second_uv)!="0")
        {
            ans8 += first_uv;
            ans8 += "*";
            ans8 += if_ln(second_uv);
        }
        d_s += if_ln(second_uv);
    }

    else if(root_tracker2==true)
    {
        if(if_root(second_uv)!="0")
        {
            ans8 += first_uv;
            ans8 += "*";
            ans8 += if_root(second_uv);
        }
        d_s += if_root(second_uv);
    }

    else if(exp_tracker2==true)
    {
        if(if_exp(second_uv)!="0")
        {
            ans8 += first_uv;
            ans8 += "*";
            ans8 += if_exp(second_uv);
        }
        d_s += if_exp(second_uv);
    }

    else
    {
        string s3 = "(";
        s3 += for_partition(second_uv);
        if(s3!="(0)")
        {
            ans8 += first_uv;
            ans8 += "*";
            ans8 += s3;
        }
        d_s += s3;
    }

    bool trigonometry_tracker3 = trigonometry_function(first_uv);
    bool ln_tracker3 = ln_function(first_uv);
    bool root_tracker3 = root_function(first_uv);
    bool exp_tracker3 = exp_function(first_uv);

    if(trigonometry_tracker3==true)
    {
        sign_comp1 = trigono_sign();

        if(sign_comp1==2 || sign_comp1==3 || sign_comp1==6)
            ans8 += "-";
        else
            ans8 += "+";
    }

    else
        ans8 += "+";

    if(trigonometry_tracker3==true)
    {

        if(sign_comp1==2 || sign_comp1==3 || sign_comp1==6)
        {
            if(if_trigonometry(first_uv)!="0")
                d_f += "-";
        }

        string s1 = if_trigonometry(first_uv);
        if(s1!="0")
        {
            ans8 += second_uv;
            ans8 += "*";
            ans8 += s1;
        }
        d_f += s1;
    }

    else if(ln_tracker3==true)
    {
        if(if_ln(first_uv)!="0")
        {
            ans8 += second_uv;
            ans8 += "*";
            ans8 += if_ln(first_uv);
        }
        d_f += if_ln(first_uv);
    }

    else if(root_tracker3==true)
    {
        if(if_root(first_uv)!="0")
        {
            ans8 += second_uv;
            ans8 += "*";
            ans8 += if_root(first_uv);
        }
        d_f += if_root(first_uv);
    }

    else if(exp_tracker3==true)
    {
        if(if_exp(first_uv)!="0")
        {
            ans8 += second_uv;
            ans8 += "*";
            ans8 += if_exp(first_uv);
        }
        d_f += if_exp(first_uv);
    }

    else
    {
        string s2 = "(";
        s2 += for_partition(first_uv);
        if(s2!="(0)")
        {
            ans8 += second_uv;
            ans8 += "*";
            ans8 += s2;
        }
        d_f += s2;
    }
    cout<<"d/dx(u) = d/dx "<<first_uv<<"\n\n\t\t\t= ";

    for(int i=0; i<d_f.size(); i++)
        cout<<d_f[i];

    cout<<"\n\n\t\t"<<"d/dx(v) = d/dx "<<second_uv<<"\n\n\t\t\t= ";

    for(int i=0; i<d_s.size(); i++)
        cout<<d_s[i];

    cout<<"\n\n\t\tSo-\n\n\t\t\td/dx(u*v) = u*d/dx(v)+v*d/dx(u)\n\n\t\t\t\t  = ";
    d_f = "";
    d_s = "";
    return ans8;
}
