#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
void encrypt(char *a,int k)
{
  cout<<"\nEncrypted Message : \n";
  for(int i=0;a[i]!='\0';i++)
  {
  if(a[i]>=65&&a[i]<=90)
  {
   a[i]+=k;
    if(a[i]>90)
      a[i]=(a[i]%90)+64;

   }
  }
   cout<<a;

}


void decrypt(char *a,int k)
{
 cout<<"\n\nDecrypted Message :\n";

 for(int i=0;a[i]!='\0';i++)
  {
  if(a[i]>=65&&a[i]<=90)
  {
   a[i]-=k;
    if(a[i]<65)
     {
      int x=(int)a[i];
      x=65-x;
      x=(char)(91-x);
      a[i]=(int)x;
      }
   }
  }
  cout<<a;

}


int main()
{
  
  
  system("cls");
  char *a;
  int n;
  int k;
  int i=0;
  cout<<"Enter the size of the Message to be Encrypted :";
  cin>>n;
  a=new char[n+1];
  
  a[n]='\0';
  cout<<endl;
  
  cout<<"Enter the Message [Capital-Letters] :";
  
  
  for(i=0;i<n;i++)
  a[i]=getche();
  
  cout<<"\n\nEnter the Key :";
  cin>>k;

  encrypt(a,k);
  decrypt(a,k);

  //system("pause");
system("pause"); 
  return 0;
  }
