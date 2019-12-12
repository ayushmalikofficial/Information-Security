#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;

int Xor(int x,int y)
{
 if(x==y)
 return 0;
 return 1;

}
void encrypt(int *p,int n,int checksum[32])
{
   int *t,i,j;
  int z=n%32;
  int q=n/32;
   if(z>0)
   q++;
   t=new int[32*q];
   for( i=0;i<n;i++)
   {
      t[i]=p[i];

   }
   for(j=0;j<=32-z;j++,i++)
    {
       t[i]=0;

    }
  cout<<"\n\nZ :"<<z;
  cout<<"\n\nQuotient : "<<q;
/*   cout<<"\n\nValues of Temp :\n";
   for(i=0;i<q*32;i++)
   {

    if(i%4==0&&i>0)
    cout<<" ";
    cout<<t[i];
   }

  */
   if(q<=1)
  {
   for(i=0;i<32;i++)
   checksum[i]=t[i];
  }
  else
  {
   for(i=0;i<32;i++)
   {
    checksum[i]=Xor(t[i],t[i+32]);
   }

   for(i=2;i<q;i++)
    {

     for(j=0;j<32;j++)
     {
      checksum[j]=Xor(checksum[j],t[i*32+j]);
     }
    }

  }


}


int main()
{

  system("cls");
  int *p;
  int n,i;
   
  cout<<"\n\nEnter the No of bits in the message (Preferably more then 200 ):";
  cin>>n;
  p=new int[n];

  for( i=0;i<n;i++)
   p[i]=(rand()%2);

   cout<<"\nPlain Text :\n";
   for(i=0;i<n;i++)
   {

    if(i%4==0)
    cout<<" ";
    if(i%32==0)
    cout<<endl;
    cout<<p[i];
   }
  int checksum[32];
  encrypt(p,n,checksum);
  cout<<"\n\nChecksum :";
   for(i=0;i<32;i++)
   {

    if(i%4==0)
    cout<<" ";
    if(i%32==0)
    cout<<endl;
    cout<<checksum[i];
   }


system("pause");
}
