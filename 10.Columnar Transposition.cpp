#include<iostream>
#include<conio.h>
using namespace std;

void encrypt(char **a,char **a2,int m,int n)
{
      int i,j;

   for (i=0;i<m;i++)
   {
      for(j=0;j<n;j++)
      {
      a2[j][i]=a[i][j];
      }

   }
   cout<<"\nEncrypted Message :\n\n";
   for (i=0;i<n;i++)
   {
      for(j=0;j<m;j++)
      {
      cout<<a2[i][j];
      }

   }


}
void decrypt(char **a,char **a2,int m,int n)
{
   cout<<"\n\n\nDecrypted Message :\n\n";
   int i,j;
   for (i=0;i<m;i++)
   {
      for(j=0;j<n;j++)
      {
      cout<<a[i][j];
      }

   }

}
int main()
{

system("cls");

  int size,i,j,n,m;
  int flag=0;
  char *text;


    cout<<"\n\nEnter the no of characters for the message to be encrypted : ";
    cin>>size;
    size++;
    text=new char[size];


    cout<<"\n\nEnter the text :\n";
    for(i=0;i<size-1;i++)
    {
     text[i]=getche();
    }
    text[i]='\0';
    cout<<endl<<text;


    cout<<"\n\nEnter the no of columns for the encryption :";
    cin>>n;
    size--;


   if(size%n>0)
   {
    flag=1;
    m=(size/n)+1;
   }
   else
    m=size/n;


   char **a;
   a=new char*[m];
   for(i =0;i<m;i++)
   a[i]=new char[n];

   char **a2;
   a2=new char*[n];
   for(i =0;i<n;i++)
   a2[i]=new char[m];



   int k=0;
   for (i=0;i<m;i++)
   {
      for(j=0;j<n;j++,k++)
      {
	if(text[k]!='\0')
	a[i][j]=text[k];
	else
	{
	  while(j<n)
	  {
	  a[i][j]='-';
	  j++;
	  }
	}
       }
      cout<<endl;
   }

   encrypt(a,a2,m,n);
   decrypt(a,a2,m,n);
system("pause");
return 0;
}
