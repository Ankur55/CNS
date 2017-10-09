#include <bits/stdc++.h>
using namespace std;

int multiplicative_inverse(int a, int m){
	int m0 = m, t, q;
	int x0 = 0, x1 = 1;
	if (m == 1)
	return 0;
	while (a > 1){
		q = a / m;
		t = m;
		m = a % m, a = t;
		t = x0;
		x0 = x1 - q * x0;
		x1 = t;
	}
	if (x1 < 0)
	x1 += m0;
	return x1;
}
int CRT(int number[], int remainder[], int k){
	int N = 1;
	for (int i = 0; i < k; i++)
		N *= number[i];
	int result = 0;
	for (int i = 0; i < k; i++){
		int pp = N / number[i];
		result += remainder[i] * multiplicative_inverse(pp, number[i]) * pp;
	}
	return result % N;
}
int main(void){
	int k;
	cout<<"value of k -> ";
	cin>>k;
	int number[k],remainder[k];
	cout<<"enter number array -> ";
	for (int i = 0; i < k; ++i)
	{
		cin>>number[i];
	}
	cout<<"enter remainder array -> ";
	for (int i = 0; i < k; ++i)
	{
		cin>>remainder[i];
	}
	// int number[] = {3, 4, 5};
	// int remainder[] = {2, 3, 1};
	cout << "x is " << CRT(number, remainder, k)<<endl;
	return 0;
}
