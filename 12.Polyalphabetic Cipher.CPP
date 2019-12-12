#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
void encrypt(char *p,char *c,int n)
{
  int i,j;
  for(i=0;i<2*n;i+=2)
  {

  c[i]='a';

  }

  for(i=1,j=0;i<2*n;i+=2,j++)
  {

  c[i]=p[j];
  }
    c[2*n]='\0';

}
void decrypt(char *p,char *c,int n)
{

    for(int i=1,j=0;i<2*n;i+=2,j++)
    {
     p[j]=c[i];
    }

}
int main()
{

  system("cls");
   int n;
   char *p;

   cout<<"\n\nEnter the no of Characters in the plain text : ";
   cin>>n;
   p=new char[n+1];
   cout<<"\nEnter the plain text : ";
   for(int i=0;i<n;i++)
   {
    p[i]=getche();
   }
   p[n]='\0';
   cout<<"\n\nPlain Text : "<<p;
   char *c;
     c=new char[2*n+1];

   encrypt(p,c,n);
   char *p2;
   p2=new char[n+1];
   p2[n]='\0';
   cout<<"\n\nEncrypted Message :"<<c;
   decrypt(p2,c,n);
   cout<<"\n\nDecrypted Message :"<<p2;
  getch();
system("pause");
return 0;
}
