#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<math.h>
using namespace std;
int main()
{
system("cls");
cout<<"Sample Value of p and alpha 13,2 ";
int p,alpha;
cout<<"\n\nEnter p (must be prime) :" ;
cin>>p;
cout<<"Enter alpha (primitve root of p) :";
cin>>alpha;

//....................User A...................

long unsigned a_priv_key=0;
a_priv_key=2+(rand()%(p-3));
cout<<"\nA private key : "<<a_priv_key;

long unsigned a_pub_key;
a_pub_key=((int)pow(alpha,a_priv_key))%p;
cout<<"\nA public key : "<<a_pub_key;

//...................User B...................
long unsigned b_priv_key=0;
b_priv_key=2+(rand()%(p-3));
cout<<"\nB private key : "<<b_priv_key;

long unsigned b_pub_key;
b_pub_key=((int)pow(alpha,b_priv_key))%p;
cout<<"\nB public key : "<<b_pub_key;


//................................................



long unsigned a_session_key=0;
a_session_key=((int)pow(b_pub_key,a_priv_key))%p;
cout<<"\nA session key : "<<a_session_key;

long unsigned b_session_key=0;
b_session_key=((int)pow(a_pub_key,b_priv_key))%p;
cout<<"\nB session key : "<<b_session_key;


system("pause");
return 0;
}
