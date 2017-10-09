#include <stdio.h>
#include <gmp.h>

int main (void) {
    mpz_t rand_Num;
    unsigned long int i, seed;
    gmp_randstate_t r_state;
     gmp_randinit_default (r_state);
    mpz_init(rand_Num);
    for(i = 0; i < 10; ++i) {
       mpz_urandomb(rand_Num,r_state,30);
       gmp_printf("%Zd\n", rand_Num);
    }
    gmp_randclear(r_state);
    mpz_clear(rand_Num);
    
    // mp_size_t s;
    // mpz_init(b);
    // mpz_init_set_str (b, "100", 10);
    // s=mpz_size(b);
    // mpz_urandom(rand_Num,s);
    // gmp_printf("%Zd\n", rand_Num);
    return 0;
}