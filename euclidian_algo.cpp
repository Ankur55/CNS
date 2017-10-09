#include <stdio.h>
#include <gmp.h>
#include <iostream>
using namespace std;

void gcd1(mpz_t res,mpz_t a, mpz_t b)
{
    if (mpz_sgn(a)==0)
       {
       	 mpz_init_set(res,b);
       	 return;
       }
    
    	mpz_mod(b,b,a);
     gcd1(res,b, a);
}
int main(int argc, char const *argv[])
{

  mpz_t a,b,c;
      mpz_init(a);
      mpz_init(b);
      mpz_init(c);

    gmp_randstate_t r_state;
    gmp_randinit_default (r_state);
    int x;
    for (int i = 0; i < 10; ++i)
    {
    	cout<<"value of n -> ";
    	cin>>x;
    	mpz_urandomb(b,r_state,x);
	    mpz_urandomb(c,r_state,x);

	    gmp_printf("%Zd  ", b);
	    gmp_printf("%Zd  ", c);

	    gcd1(a,b,c);
	    gmp_printf("%Zd  ", a);
    	mpz_gcd(a,b,c);
	    gmp_printf(" %Zd\n", a);

    }
	return 0;
}