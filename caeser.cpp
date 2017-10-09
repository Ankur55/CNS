#include <bits/stdc++.h>
using namespace std;

string Encrypt(string &s,int x){
	int l=s.length();

	for (int i = 0; i < l; ++i)
	{
		if(s[i] >= 'A' && s[i] <= 'Z'){
			s[i]=char((int(s[i]-'A')+x)%26)+'A';
		}else{
			s[i]=char((int(s[i]-'a')+x)%26)+'a';
		}
	}
	return s;
}
string Decrypt(string &s,int x){
	int l=s.length();

	for (int i = 0; i < l; ++i)
	{
		if(s[i] >= 'A' && s[i] <= 'Z'){
			s[i]=char((26+int(s[i]-'A')-x)%26)+'A';
		}else{
			s[i]=char((26+int(s[i]-'a')-x)%26)+'a';
		}
	}
	return s;
}
int main(int argc, char const *argv[])
{
	cout<<"enter plain text -> ";
	string s;
	cin>>s;
	int x=3;
	cout<<"Enciphered text is -> "<<Encrypt(s,x)<<endl;
	cout<<"Deciphered text is -> "<<Decrypt(s,x)<<endl;
	return 0;
}