#include "header.h"

void display()
{

   cout<<"\n\n\n\t\t Welcome to DERIVATIVE CALCULATOR\n\n";
   cout<<"\t\t What kind of equation do you want to differentiate?\n";
   cout<<"\t\t 1.Algebra functions\n";
   cout<<"\t\t 2.Trigonometry functions\n";
   cout<<"\t\t 3.ln functions\n";
   cout<<"\t\t 4.Exponential functions\n";
   cout<<"\t\t 5.Composite functions\n";
   cout<<"\t\t 6.Exit\n";

   int t ; cin>> t;
   if(t==1)
   algebra();
   else if(t==2)
   trigonometry();
   else if(t==3)
   ln();
   else if(t==4)
   exponential();
   else if(t==5)
   composite();
   else if(t==6)
   break;
   else
   cout<<"\t\t Please , Choice a valid option\n";
}
