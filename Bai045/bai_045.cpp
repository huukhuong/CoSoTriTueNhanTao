#include <bits/stdc++.h>
#include <fstream> 
using namespace std;

int main(){
	string s[10000];
	int n;
	cin>>n;
	int k =pow(2,n);
	s[1]="0";
	s[2]="1";
	if(n>1){
		int t =2;
		for(int i = 2; i<=n; i++){
			int l=pow(2,i);
			for(int j= 1; j<=t; j++){
				s[l-j+1] = "1" + s[j];
				s[j] = "0" + s[j];
			}
			t= l;
		}
	}
	ofstream f("GRAYCODE.OUT");
	for(int j = 1; j<=k; j++){
		cout<<s[j]<<" ";
		f<< s[j]<<" ";
	}
	f.close();
}
