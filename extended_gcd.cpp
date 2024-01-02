#include<bits/stdc++.h>
using namespace std;
int gcd_extended(int a,int b){
	int r1=a;
	int r2=b;
	int s1=1;
	int s2=0;
	int t1=0;
	int t2=1;
	int s=-1,t=-1;
	while(r2>0){
		int q=r1/r2;
		int r=r1-q*r2;
		r1=r2;
		r2=r;
		s=s1-q*s2;
		s1=s2;
		s2=s;
		t=t1-q*t2;
		t1=t2;
		t2=t;
	}
	s=s1;
	t=t1;
	if(t1<0){
		t1=t1+a;
	}
	return t1;
}
int main(){
	int a;
	cin>>a;
	int b;
	cin>>b;
	cout<<gcd_extended(a,b)<<endl;
	return 0;
}
