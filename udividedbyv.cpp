#include "header.h"

using namespace std;

bool udivbyv_function(string equ)
{

    for(int i=0; i<equ.size(); i++)
    {
        if(equ[i]=='/' && equ[i-1]==')' && (equ[i+1]=='(' || (equ[i+1] >96 && equ[i+1] <123)))
            return true;
        else
            continue;
    }
    return false;
}

string if_udivbyv(string equ)
{

    string ans9 = "";
    string ddx_f1 = "", ddx_s1 = "";
    char first_uv1[1000], second_uv1[1000];
    int for_delimit1=0, j1=0, k1=0, sign_comp, sing_comp;

    cout<<"\n\n\t\t"<<"This expression follows the U/V method as it's a division among two functions."<<"\n\n\t\tWe know that - "
    <<"\n\n\t\t\t"<<"d/dx(u/v) = [v*d/dx(u) - u*d/dx(v)]/v^2"<<"\n\n\t\t"<<"Here-\n\n\t\t\t";

    for(int i=0; i<equ.size(); i++)
    {

        if(equ[i]=='/' && equ[i-1]==')' && (equ[i+1]=='(' || (equ[i+1] >96 && equ[i+1] <123)))
        {
            for_delimit1 = 1;
            continue;
        }
        if(for_delimit1==0)
        {
            first_uv1[i] = equ[i];
            k1++;
        }
        else if(for_delimit1==1)
        {
            second_uv1[j1] = equ[i];
            j1++;
        }
    }

    first_uv1[k1] = '\0';
    second_uv1[j1] = '\0';

    cout<<"u = "<<first_uv1<<"\n\n\t\t\t";
    cout<<"v = "<<second_uv1<<"\n\n\t\t\n\t\t";

    ans9 += "[";

    bool trigonometry_tracker5 = trigonometry_function(first_uv1);
    bool ln_tracker5 = ln_function(first_uv1);
    bool root_tracker5 = root_function(first_uv1);
    bool exp_tracker5 = exp_function(first_uv1);

    if(trigonometry_tracker5==true)
    {
        sing_comp = trigono_sign();

        if(sing_comp==2 || sing_comp==3 || sing_comp==6)
        {
            if(if_trigonometry(first_uv1)!="0")
                ans9 += "-";
        }
    }

    if(trigonometry_tracker5==true)
    {

        if(sing_comp==2 || sing_comp==3 || sing_comp==6)
        {
            if(if_trigonometry(first_uv1)!="0")
                ddx_f1 += "-";
        }

        string s7 = if_trigonometry(first_uv1);
        if(s7!="0")
        {
            ans9 += second_uv1;
            ans9 += "*";
            ans9 += s7;
        }
        ddx_f1 += s7;
    }

    else if(ln_tracker5==true)
    {
        if(if_ln(first_uv1)!="0")
      {
            ans9 += second_uv1;
            ans9 += "*";
            ans9 += if_ln(first_uv1);
        }
        ddx_f1 += if_ln(first_uv1);
    }

    else if(root_tracker5==true)
        {
        if(if_root(first_uv1)!="0")
        {
            ans9 += second_uv1;
            ans9 += "*";
            ans9 += if_root(first_uv1);
        }
        ddx_f1 += if_root(first_uv1);
    }

    else if(exp_tracker5==true)
        {
        if(if_exp(first_uv1)!="0")
        {
            ans9 += second_uv1;
            ans9 += "*";
            ans9 += if_exp(first_uv1);
        }
        ddx_f1 += if_exp(first_uv1);
    }

    else {
        string s8 = "(";
        s8 += for_partition(first_uv1);
        if(s8!="(0)")
        {
            ans9 += second_uv1;
            ans9 += "*";
            ans9 += s8;
        }
        ddx_f1 += s8;
    }

    bool trigonometry_tracker4 = trigonometry_function(second_uv1);
    bool ln_tracker4 = ln_function(second_uv1);
    bool root_tracker4 = root_function(second_uv1);
    bool exp_tracker4 = exp_function(second_uv1);

    if(trigonometry_tracker4==true)
    {
        sign_comp = trigono_sign();

        if(sign_comp==2 || sign_comp==3 || sign_comp==6)
            ans9 += "+";
        else
            ans9 += "-";
    }

    else
        ans9 += "-";

    if(trigonometry_tracker4==true)
    {

        if(sign_comp==2 || sign_comp==3 || sign_comp==6)
        {
            if(if_trigonometry(second_uv1)!="0")
                ddx_s1 += "-";
        }

        string s5 = if_trigonometry(second_uv1);

        if(s5!="0")
        {
            ans9 += first_uv1;
            ans9 += "*";
            ans9 += s5;
        }
        ddx_s1 += s5;
    }

    else if(ln_tracker4==true)
    {
        if(if_ln(second_uv1)!="0")
      {
            ans9 += first_uv1;
            ans9 += "*";
            ans9 += if_ln(second_uv1);
        }
        ddx_s1 += if_ln(second_uv1);
    }

    else if(root_tracker4==true)
    {
        if(if_root(second_uv1)!="0")
      {
            ans9 += first_uv1;
            ans9 += "*";
            ans9 += if_root(second_uv1);
        }
        ddx_s1 += if_root(second_uv1);
    }

    else if(exp_tracker4==true)
    {
        if(if_exp(second_uv1)!="0")
        {
            ans9 += first_uv1;
            ans9 += "*";
            ans9 += if_exp(second_uv1);
        }
        ddx_s1 += if_exp(second_uv1);
    }

    else {

        string s6 = "(";
        s6 += for_partition(second_uv1);
        if(s6!="(0)")
        {
            ans9 += first_uv1;
            ans9 += "*";
            ans9 += s6;
        }
        ddx_s1 += s6;
    }

    cout<<"d/dx(u) = d/dx "<<first_uv1<<"\n\n\t\t\t= ";

    for(int i=0; i<ddx_f1.size(); i++)
        cout<<ddx_f1[i];

    cout<<"\n\n\t\t"<<"d/dx(v) = d/dx "<<second_uv1<<"\n\n\t\t\t= ";

    for(int i=0; i<ddx_s1.size(); i++)
        cout<<ddx_s1[i];

    cout<<"\n\n\t\tSo-\n\n\t\t\td/d/dx(u/v) = [v*d/dx(u)-u*d/dx(v)]/v^2\n\n\t\t\t\t    = ";

    ans9 += "]/";

    if(trigonometry_tracker4==true || ln_tracker4==true || root_tracker4==true)
        ans9 += "[";

    ans9 += second_uv1;

    if(trigonometry_tracker4==true || ln_tracker4==true || root_tracker4==true)
        ans9 += "]";

    ans9 += "^2";
    ddx_f1 = "";
    ddx_s1 = "";

    return ans9;
}
