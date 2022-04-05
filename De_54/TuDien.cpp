#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string xoaTrung(string s)
{
	int i=0,j;
	while(i<s.size()-1)
	{
		if(s[i]==' ')
		    s.erase(i,1);
		    else
		    {
		    	for(j=i+1;j<s.size();j++)
		    	    if(s[i]==s[j])
		    	        break;
		    	if(j<s.size()) 
				s.erase(j,1); 
				else i++;  
			}    
	}
	if(s[s.size()-1]==' ')
	    s.erase(s.size()-1,1);
	return s;
}
int main()
{
	string s="",t;
	ifstream f1("NOTE.INP");
	fflush(stdin);
	getline(f1,t);
	while(not(f1.eof()))
	{
		fflush(stdin);
		getline(f1,t);
		s+=t;
		s=xoaTrung(s);
	}
	f1.close();
	ofstream f2("NOTE.OUT");
	f2<<s;
	f2.close();
	return 0;
}
