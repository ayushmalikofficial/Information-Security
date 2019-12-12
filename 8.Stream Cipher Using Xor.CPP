#include<conio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

int Xor(int x,int y)
{

 if(x==y)
 return 0;
 return 1;

}

void encrypt(int *t,int *k,int n)
{
    for(int i=0;i<n;i++)
    t[i]=Xor(t[i],k[i]);

}

int main()
{
	system("cls");
   int *p,i, n, *k, *c;
    
    
    cout<<"Enter the no. of bits in the plane text : ";
    cin>>n;
    p=new int[n];
    k=new int[n];
    cout<<"Enter the plain text in (0-1 string) : ";
    for(i=0;i<n;i++)
     {
     char ch;
     ch=getche();
     p[i]=(int)ch-48;

     }


     cout<<"\nPlain text : ";
     for(i=0;i<n;i++)
     cout<<p[i];

     for(i=0;i<n;i++)
     k[i]=(rand()%2);


     cout<<"\nKey        : ";
     for(i=0;i<n;i++)
     cout<<k[i];

     encrypt(p,k,n);
     cout<<"\nCipher text: ";
     for(i=0;i<n;i++)
     cout<<p[i];

     encrypt(p,k,n);

     cout<<"\nPlain text : ";
     for(i=0;i<n;i++)
     cout<<p[i];

system("pause");
    return 0;

}
