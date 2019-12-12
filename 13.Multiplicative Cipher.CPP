#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

int calc_inverse(int a)
{     int x;
   for(x=1;x<26;x++)
   {
	if((a*x)%26==1)
	return x;
   }
 return 0;
}
void encrypt(char *text,char *ctext,char M[26],int k,int n)
{

      int i,j;
      for(i=0;i<n;i++)
      {
      int temp=text[i]-96;

      ctext[i]=M[(temp*k)%26];
      }

       ctext[i]='\0';
      cout<<"\n\nEncrypted Message : ";

      cout<<ctext<<endl;

}



void decrypt(char *text,char *ctext,char M[26],int mk,int n)
{
   int i,j;
   int temp;
   for( i=0;i<n;i++)
   {
      temp=ctext[i]-96;

     text[i]=M[(temp*mk)%26];
   }
  text[i]='\0';


  cout<<"\nDecrypted Message : ";
    cout<<text<<endl<<endl;


}


int main()
{
system("cls");

  int size,i,j;

  char M[27];
  M[0]='0';
//  cout<<"\nMapping Table \n";
  for(i=1;i<27;i++)
  {
    M[i]=96+i;
  }
 

  char *text;
  char *ctext;
  int k,mk;

    cout<<"Enter the Key (should be modulo 26 invertible): ";
    cin>>k;
    mk=calc_inverse(k);
    cout<<"\nMultiplicative Inverse :"<<mk;


    cout<<"\n\nEnter the No of characters for the Message to be Encrypted : ";
    cin>>size;

    text=new char[size+1];
    ctext=new char[size+1];




    cout<<"\n\nEnter the Text :\n";
    for(i=0;i<size;i++)
    {
     text[i]=getche();
    }
    text[i]='\0';
    cout<<endl;
    cout<<"\nPlain Text        : ";
    cout<<text;



encrypt(text,ctext,M,k,size);
decrypt(text,ctext,M,mk,size);



system("pause");
}
