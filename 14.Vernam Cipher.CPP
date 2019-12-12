#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;

void encrypt(char *text,char *ctext,int *pad,int n)
{
cout<<"\n\n\nEncrypted Message :\n\n";

      int i,j;
      for(i=0;i<n;i++)
      {
      int z=text[i]+pad[i];


      if(z>122)
      {
	 z=(z%123 )+97;
      }
	 ctext[i]=(char)z;
	  }
      ctext[i]='\0';
       cout<<ctext;
}
void decrypt(char *text,char *ctext,int *pad,int n)
{
   cout<<"\n\n\nDecrypted Message :\n\n";
   int i,j,z;
   for( i=0;i<n;i++)
  {
   text[i]=ctext[i]-pad[i];
    if(text[i]<97)
     {
      int x=(int)text[i];
      x=97-x;
      x=(char)(123-x);
      text[i]=(int)x;
      }

  }
  text[i]='\0';
  cout<<text;


}
int main()
{
system("cls");

  int size,i,j;
  char *text;
  char *ctext;
  char *ptext;
  int *pad;

//  randomize();
    cout<<"\n\nEnter the No of characters for the Message to be Encrypted : ";
    cin>>size;

    text=new char[size+1];
    ctext=new char[size+1];
    ptext=new char[size+1];

    pad=new int[size];




    cout<<"\n\nEnter the Text :\n";
    for(i=0;i<size;i++)
    {
    text[i]=getch();
     cout<<"*";
    }
    text[i]='\0';
  cout<<endl;
    for(i=0;i<size;i++)
    {
     pad[i]=(rand()%26);
    }

    cout<<"\nRandom pad : ";
    for(i=0;i<size;i++)
    {
     cout<<pad[i]<<"("<<(char)pad[i]+97<<")"<<" ";
    }



   encrypt(text,ctext,pad,size);
  getch();
  decrypt(ptext,ctext,pad,size);
system("pause");
}
