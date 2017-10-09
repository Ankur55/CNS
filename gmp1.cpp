#include <stdio.h>
#include <gmp.h>
using namespace std;

int main(int argc, char const *argv[])
{
	mpz_t a,b,c;
	mpz_init(a);
	mpz_init(b);
	mpz_init(c);
	mpz_init_set_str (b, "3141592653589793238462643383279502884", 10);
	mpz_init_set_str (c, "3141592653589793238462643383279502883", 10);
	mpz_add(a,b,c);
	gmp_printf ("%Zd\n", a);	
	return 0;
}