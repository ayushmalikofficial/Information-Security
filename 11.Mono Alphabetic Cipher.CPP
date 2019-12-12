#include<iostream>
#include<conio.h>
using namespace std;
void encrypt(char *text,char *ctext,char M[26],int k[26],int n)
{

      int i,j;
      for(i=0;i<n;i++)
      {
      int temp=text[i]-97;

      ctext[i]=M[k[temp]];
      }

       ctext[i]='\0';
      cout<<"\n\nEncrypted Message : ";

      cout<<ctext<<endl;

}



void decrypt(char *text,char *ctext,char M[26],int k[26],int n)
{
   int i,j;
   int temp;
   for( i=0;i<n;i++)
   {
      temp=ctext[i]-97;
       for(j=0;j<26;j++)
	  {
	   if(k[j]==temp)
	     text[i]=M[j];
	  }

   }
  text[i]='\0';


  cout<<"\nDecrypted Message : ";
    cout<<text<<endl<<endl;


}


int main()
{
system("cls");

  int size,i,j;

  char M[26];
  //  cout<<"\nMapping Table \n";
  for(i=0;i<26;i++)
  {
    M[i]=97+i;
  }


  char *text;
  char *ctext;
  int k[26];
  k[0]=8;
  k[1]=20;
  k[2]=21;
  k[3]=22;
  k[4]=23;
  k[5]=24;
  k[6]=25;
  k[7]=0;
  k[8]=19;
  k[9]=1;
  k[10]=2;
  k[11]=11;
  k[12]=12;
  k[13]=18;
  k[14]=7;
  k[15]=17;
  k[16]=13;
  k[17]=14;
  k[18]=6;
  k[19]=16;
  k[20]=15;
  k[21]=4;
  k[22]=10;
  k[23]=3;
  k[24]=5;
  k[25]=9;



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
decrypt(text,ctext,M,k,size);




system("pause");
return 0;
}
