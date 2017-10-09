#include <stdio.h>
#include <gmp.h>
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int main(int argc, char const *argv[])
{
	mpz_t a,b,c;
	mpz_init(a);
	mpz_init(b);
	mpz_init(c);
	mpz_init_set_str (b, "3141592653589793238462643383279502881", 10);
	mpz_init_set_str (c, "3141592653589793238462643383279502000", 10);
	mpz_add(a,b,c);
	gmp_printf ("addition of b and c = %Zd\n", a);	
	mpz_init(a);
	mpz_sub(a,b,c);
	gmp_printf ("substraction of b and c = %Zd\n", a);

	mpz_init(a);
	mpz_mul(a,b,c);
	gmp_printf ("Multiplication of b and c = %Zd\n", a);

	int x=mpz_cmp(b,c);
	printf("compare returns = %d\n",x);

	mpz_t rem;
	mpz_init(rem);
	mpz_mod(rem,b,c);
	gmp_printf ("Reminder of b mod c = %Zd\n", rem);	

	return 0;
}