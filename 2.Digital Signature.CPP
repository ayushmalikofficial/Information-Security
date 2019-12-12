#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<math.h>

using namespace std;

int gcd(int x,int y)
{
    if(x>=y)
    {
      if((x%y)==0)
        return y;
      else
        return gcd(x%y,y);
    }
    else
        return gcd(y,x);
}


int main()
{
system("cls");
int i,j;
cout<<"\n\nIMPORTANT NOTE : in case of high values of exponentiation the result displayed may be incorrect";

cout<<"\n\nSample Value of p and alpha : 7,3 ";
int p,alpha;
cout<<"\n\nEnter p (must be prime preferably less than 15) :" ;
cin>>p;
cout<<"Enter alpha (primitve root of p) :";
cin>>alpha;

//....................User A...................

long unsigned a_priv_key=0;
a_priv_key=2+(rand()%(p-3));
cout<<"\nA private key : "<<a_priv_key;

long unsigned a_pub_key;
a_pub_key=((int)pow(alpha,a_priv_key))%p;
a_pub_key=a_pub_key%p;
cout<<"\nA public key : "<<a_pub_key;

//...................User B...................
long unsigned b_priv_key=0;
b_priv_key=2+(rand()%(p-3));
cout<<"\nB private key : "<<b_priv_key;

long unsigned b_pub_key;
b_pub_key=((int)pow(alpha,b_priv_key))%p;
b_pub_key=b_pub_key%p;
cout<<"\nB public key : "<<b_pub_key;


//................................................



long unsigned a_session_key=0;
a_session_key=((int)pow(b_pub_key,a_priv_key))%p;
a_session_key=a_session_key%p;
cout<<"\nA session key : "<<a_session_key;

long unsigned b_session_key=0;
b_session_key=((int)pow(a_pub_key,b_priv_key))%p;
b_session_key=b_session_key%p;
cout<<"\nB session key : "<<b_session_key;


//.............Sending the Message.................

int x,y,dec_x,inv_key;
cout<<"\n\nEnter the Message A wishes to send to B. ( between 1 to "<<p-1<<" ): ";
cin>>x;
y=(x*a_session_key)%p;
     
cout<<"\nEncrypted Message : "<<y;

for(i=2;i<=p;i++)
{
	if((a_session_key*i)%p==1)
     {
	 inv_key=i;
	 break;
	 }
}    

cout<<"\n Inverted Key "<<inv_key; 
cout<<"\n Decrypted Message : "<<(y*inv_key)%p;

//...................Signature Generation....................
long  r=0,s=0;
int ke,inv_ke=2;

int flag=1;
	for(int i=2;i<p-1;i++)
     {
     	if(gcd(p-1,i)==1)
     	{
     		ke=i;
     		break;
		 }
	 }
	 
    while(flag )
    {
    if(((ke*inv_ke)%(p-1))==1)       	
		{
			flag=0;
			break;
		   }   
		
	    inv_ke++;	
	}
    
cout<<"\n\nKe :"<<ke;
cout<<"\nKe_Inverse :"<<inv_ke;
r=(long)pow(alpha,ke)%p;
long t=x-(b_priv_key*r);
//cout<<endl<<t;
s=(t*inv_ke)%(p-1);
if(s<0)
s=s+p-1;
cout<<"\n\nSignature Generated at A's End : [r,s] ";

cout<<"\n r : "<<r;
cout<<"\n s : "<<s;

cout<<"\n\nSignature Verification at B's End : [r,s] ";
//.................Signature Verification..................

long s1=(long)(pow(b_pub_key,r)*pow(r,s))%p;
long s2=(long)pow(alpha,x)%p;
if(s1<0)
s1+=p;

if(s2<0)
s2+=p;


cout<<"\n\nAs "<<s1<<" = ";
cout<<s2;

cout<<"\n\nSignature Is VALID (Comparison of the 2 values can be seen in the source code)";


system("pause");
return 0;
}
