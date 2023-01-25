#include "header.h"

void display()
{

   cout<<"\n\n\n\t\t Welcome to DERIVATIVE CALCULATOR\n\n";
   cout<<"\t\t Enter an Equation (Press '1' ) \n";
   cout<<"\t\t Exit (Press '2') \n\n";
   int choice ; cin >> choice;
   if(choice == 1)
   {
       string equ;
       cout<<"Input Equation : ";
       cin >> equ;
       for_partition(equ);
   }
   else if( choice == 2)
   {
       cout<<"\n\t\t Thanks for using this .\n";
       exit(1);
   }
   else
         cout<<"\t\t Please choice a valid option .\n";
}
