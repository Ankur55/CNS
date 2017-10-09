#include <bits/stdc++.h>
#include <gmp.h>
using namespace std;

void extended_gcd(mpz_t res,mpz_t a, mpz_t b,mpz_t x,mpz_t y)
{
    if (mpz_sgn(a)==0)
       {
   		mpz_set_si (x,0); 
   		mpz_set_si (y,1); 
   		 // mpz_init_set(y,1);
       	 mpz_set(res,b);
       	 return;
       }
    
   	mpz_t hold_res,hold_b,hold_a,x1,y1,t;
   	mpz_init_set(hold_b,b);
   	mpz_init_set(hold_a,a);
   	mpz_init(x1);
   	mpz_init(y1);
   	mpz_init(t);
	mpz_mod(b,b,a);
	    // gmp_printf("%Zd\n", b);

   	extended_gcd(res,b,a,x1,y1);
   	mpz_fdiv_q (t,hold_b,hold_a);
    // gmp_printf("%Zd / %Zd = %Zd\n",hold_b,hold_a,t);
	mpz_mul(t,t,x1);
    // gmp_printf("(b/a)*x1 %Zd\n", t);
	mpz_sub(x,y1,t);
    // gmp_printf("y1-(b/a)*x1 %Zd\n", x);
	mpz_set(y,x1);
   	// gmp_printf("y %Zd\n", y);
	// mpz_set(res,)
   	mpz_clear(t);
   	// mpz_clear(x1);
   	// mpz_clear(y1);
   	mpz_clear(hold_b);
   	// mpz_clear(s1);
   	return;
}

int main(int argc, char const *argv[])
{
	mpz_t a,b,c,x,y;
	mpz_init(a);
	mpz_init(b);
	mpz_init(c);
	mpz_init(x);
	mpz_init(y);

    gmp_randstate_t r_state;
    gmp_randinit_default (r_state);
    int x1;
    cout<<"value of n -> ";
    	cin>>x1;
    for (int i = 0; i < 10; ++i)
    {
    	
    	mpz_urandomb(b,r_state,x1);
	    gmp_printf("(a,b) = (%Zd", b);
	    mpz_urandomb(c,r_state,x1);
	    gmp_printf(",%Zd) ", c);

	    // gmp_printf("%Zd  ", b);
	    // gmp_printf("%Zd  ", c);
	    	mpz_t hold_b,hold_c;
	   	mpz_init_set(hold_b,b);
	   	mpz_init_set(hold_c,c);
	    extended_gcd(a,hold_b,hold_c,x,y);
	    gmp_printf("gcd=%Zd x=%Zd y=%Zd ", a,x,y);
	    mpz_mul(a,b,x);
	    mpz_mul(b,c,y);
	    mpz_add(a,a,b);
	    gmp_printf("a*x+b*y = %Zd\n",a);
    	//mpz_gcd(a,b,c);
	    //gmp_printf(" %Zd\n", a);

    }
	return 0;
}