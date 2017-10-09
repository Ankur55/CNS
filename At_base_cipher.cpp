#include <bits/stdc++.h>
using namespace std;

string Encrypt(string &s){
	int l=s.length();

	for (int i = 0; i < l; ++i)
	{
		if(s[i] >= 'A' && s[i] <= 'Z'){
			s[i]=char(25-int(s[i]-'A'))+'A';
		}else{
			s[i]=char(25-int(s[i]-'a'))+'a';
		}
	}
	return s;
}
int main(int argc, char const *argv[])
{
	cout<<"enter plain text -> ";
	string s;
	cin>>s;
	cout<<"Enciphered text is -> "<<Encrypt(s)<<endl;
	cout<<"Deciphered text is -> "<<Encrypt(s)<<endl;
	return 0;
}