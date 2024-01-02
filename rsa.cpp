#include<iostream>
#include<bits/stdc++.h>
//#include<maths.h>
using namespace std;

int extended_euclidian_method(int a,int b)
{
    int r1 = a, r2 = b;
    int s1=1,s2 =0;
    int t1=0,t2 =1;
    int r = r1/r2;

    while(r2 > 0)
    {
        int q = r1/r2;
        r = r1 - q *r2;

        // updattion 
        r1 = r2;
        r2 = r;
        
        // calculating s 
        int s = s1 - q *s2;
        int t = t1 - q* t2;

        s1 = s2;
        s2 = s;

        t1 = t2;
        t2 = t;

    }
    return t1;

}

int gcd(int a, int b){
	int t;
	while(1){
		t = a%b;
		if(t==0){
			return b;
		}
		a = b;
		b = t;
	}
}

double encrypt(int m, int e, int n){
	double temp = pow(m,e);
	double cip = fmod(temp,n);
	return cip;
}

int decrypt(int cipher, int d, int n){
	int temp = cipher,mul=1;
	
	for(int i =1 ; i<=d;i++){
		mul  = (mul*cipher)%n;
	}
	//cout<<"plain-text"<<mul;
	return mul;
}

int main(){
	int p, q;
	cout<<"Enter p and q: \n"<<endl;
	cin>>p>>q;
	double n = p*q;
	cout<<"n:"<<n<<endl;
	double phi = (p-1)*(q-1);
	cout<<"phi:"<<phi<<endl;
	int e = 2;
	double temp;
	while(e<phi){
		temp = gcd(phi,e);
		if(temp==1){
			break;
		}
		else{
			e++;
		}
	}
	cout<<"e:"<<e<<endl;
	
	double d1= extended_euclidian_method(phi,e) ;
	double d = d1>0 ? d1: d1 + phi;
	cout<<"d: \n"<<d;
	//public-key: e,n
	// private-key : d
	int m;
	cout<<"Enter message: \n"<<endl;
	cin>>m;
	double cipher = encrypt(m,e,n);
	cout<<"cipher:"<<cipher<<endl;
	
	int plaintext = decrypt(cipher,d,n);
	cout<<"plaintext:"<<plaintext<<endl;
	 
	
	
}
