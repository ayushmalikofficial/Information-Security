#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;

void encrypt(char *text,char *ctext,int T[26][26],char M[26],int *pad,int n)
{

      int i,j;
      for(i=0;i<n;i++)
      {
      ctext[i]=M[T[text[i]-97][pad[i]]];
      }

       ctext[i]='\0';
      cout<<"\n\nEncrypted Message : ";

      cout<<ctext<<endl;

}



void decrypt(char *text,char *ctext,int T[26][26],char M[26],int *pad,int n)
{
   int i,j;
   int temp;
   for( i=0;i<n;i++)
   {
     temp=int((ctext[i]-97)-pad[i]);
     if(temp<0)
     temp=26+temp;

     text[i]=M[temp];
   }
  text[i]='\0';


  cout<<"\n\nDecrypted Message : ";
    cout<<text<<endl;


}


int main()
{
system("cls");

  int size,i,j;
  int T[26][26];
  char M[26];
//  cout<<"\nMapping Table \n";
  
  for(i=0;i<26;i++)
  {
    M[i]=97+i;
  }
/*  for(i=0;i<26;i++)
  {
    cout<<i<<" "<<M[i]<<"\n";
  }
  */
  
  cout<<"\nVigenere Cipher \n\n";
  
  for(i=0;i<26;i++)
  {
  for(j=0;j<26;j++)
  {
    T[i][j]= ((j+i)%26);
  }
   }
  for(i=0;i<26;i++)
  {
  for(j=0;j<26;j++)
  {
    cout<<char(T[i][j] + 97)<<" ";//M[T[i][j]]<<" ";
  }
   cout<<endl;
   }



  char *text;
  char *ctext;
  char *ptext;
  int *pad;

    
    cout<<"\n\nEnter the No of characters for the Message to be Encrypted : ";
    cin>>size;

    text=new char[size+1];
    ctext=new char[size+1];
    ptext=new char[size+1];

    pad=new int[size];




    cout<<"\n\nEnter the Text :\n";
    for(i=0;i<size;i++)
    {
     text[i]=getche();
    }
    text[i]='\0';
    cout<<endl;
    for(i=0;i<size;i++)
    {
     pad[i]=(rand()%26);
    }
    cout<<"\nPlain Text        : ";
    cout<<text;
    cout<<"\n\nRandom pad        : ";
    for(i=0;i<size;i++)
    {
     cout<<pad[i]<<"("<<M[pad[i]]<<")"<<" ";
    }



encrypt(text,ctext,T,M,pad,size);
decrypt(text,ctext,T,M,pad,size);




system("pause");
return 0;
}
