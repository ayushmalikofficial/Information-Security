#include<iostream>
#include <cstdlib>
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



void key_generation(int p,int q,int &k_public,int &k_private,int &n)
{
    n=p*q;
    int  e,d=2;
    int phi_n=(p-1)*(q-1);
  //  cout<<endl<<endl<<phi_n;
    int flag=1;
	for(int i=2;i<phi_n;i++)
     {
     	if(gcd(phi_n,i)==1)
     	{
     		e=i;
     		break;
		 }
	 }
	 
    while(flag )
    {
    if(((e*d)%phi_n)==1)       	
		{
			flag=0;
			break;
		   }   
		
	    d++;	
	}
    
	k_public=e;
    k_private=d;
}


unsigned long encryption(int X,int n,int e)
{
    unsigned long Y=pow(X,e);
    Y=Y%n;  
//cout<<endl<<Y;
    return Y;
}

unsigned long decryption(int Y,int n,int d)
{
    unsigned long X=pow(Y,d);
    X=X%n;  
//cout<<endl<<X;
    return X;
}


int main() 
{

    int message,p,q,n;
    int k_public,k_private;
    unsigned long ctext,ptext;
    
	cout<<"IMPORTANT NOTE : Because of High exponentiation I want you to keep the size of message ,p and q as small as possible";
    
	cout<<"\n\n\nEnter two Prime Numbers (Preferably between 3 and 15): ";
    cin>>p>>q;
    cout<<"Euler Totient Function : ";
    cout<<(p-1)*(q-1);
    cout<<"\nn : "<<p*q;
    
	
	cout<<"\nEnter the Plain Text (Preferably less than 10) : ";
    cin>>message;

	key_generation(p,q,k_public,k_private,n);
    
	cout<<"\nPublic Key :("<<k_public<<","<<n<<")";
    
	cout<<"\nPrivate Key:("<<k_private<<","<<n<<")";
    
	ctext=encryption(message,n,k_public);
    cout<<"\nEncrypted Message :"<<ctext;
    ptext=decryption(ctext,n,k_private);
    cout<<"\nDecrypted Message :"<<ptext;
system("pause");   
    return 0;
}
