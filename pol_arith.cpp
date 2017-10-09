#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define mx 283

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int parse(char str[], int degree)
{
	int i = 0, num = 0;
        str = strrev(str);                      
	for(i=0; i <= degree; ++i)
	{
		if(str[i] == '1')
			num = num | (1 << i);
	}
	return num;
}

char* get_string(int num, int degree)
{
	char res[32] = {'\0'};
	int i = 0;
	for(i=0; i < 32 && i < degree; ++i)
	{
		if(num & (1 << i))
			res[i] = '1';
	        else
	                res[i] = '0';
	}
	return strrev(res);
}

int get_degree(int num)
{
        int i;
        for(i = 31; i>=0; --i)
                if(num & (1 << i))
                        return i;
}

int multiply(int num1, int num2, int degree)
{
	int res = 0;
	int i = 0;
	for(i=0; i <= degree; ++i)
	{
		if(num2 & (1 << i))
			res = res ^ (num1 << i);
	}
	
	int deg = get_degree(res);
	while(deg >= degree)
	{
	        res = res ^ (mx << (deg-degree));
	        deg = get_degree(res);
	}
	return res;
}

int main()
{
	int degree = 8;
	char first[32] = {'\0'}, second[32] = {'\0'};
	//printf("\nPolynomial Arithmetic for GF(2^8) mod m(x) = x^8 + x^4 + x^3 + x + 1.\n");
	//printf("\nYou have to enter the coefficients of polynomials in bit string (x^2 + 1  -->  101)\n");
	printf(" first polynomial : ");
	scanf("%s", first);
	printf("\n second polynomial : ");
	scanf("%s", second);

	int p1=0, p2=0, add = 0;
	long mul = 0;

	p1 = parse(first, degree);
	p2 = parse(second, degree);

	add = p1 ^ p2;
	printf("\nThe addition result is : %s\n", get_string(add, degree));

	mul = multiply(p1, p2, degree);
	printf("\nThe multiplication result is : %s\n\n", get_string(mul, degree));

	return 0;
}