/*
	Задача от cs50 первый задачник 5-е задание
	http://docs.cs50.net/problems/credit/credit.html
*/
#include <stdio.h>
#include <cs50.h>
//___________________________________________________________________________________________
//											Счетчик кол-ва чисел в карте
int counter_ch (long long int a)
{
	int i;
	for( i = 0 ; a > 0 ; a /= 10, i++)
		;
	return i;
}
//___________________________________________________________________________________________
//										 Выявляем первые два числа карты
int two_n(long long int a)
{
	int c;
	for( ; a > 100 ; a /= 10)
		;
	c = a;
	return c;
}
//____________________________________________________________________________________________
//											Главная функция
/*
Переменные:
	a - номер карты
	x - сумма нечетных чисел
	y - сумма четных чисел
	n     - счетчик чисел == counter_ch
	xx    - первые два числа карты
*/
int main (void)
{
	long long int a;
	int x, y, n, b;
	printf("Number: ");
	a = get_long_long();
	b = two_n(a);
	n = counter_ch(a);
//_____________________________________________________________________________________________
//												Вычисления
	if(n%2 == 0)
	{
		for( x=y=0; n>=0 ; n = n-2)
			{
				x = a%10 + x;
				a = a/10;
				y = a%10*2 >= 10 ? ((a%10)*2)/10 + (((a%10)*2)%10) + y
								: ((a%10)*2) + y;
				a = a/10;
			}
	}
	else
	{
		for(x= a%10, y = 0, a=a/10; n>=0; n = n-2)
		{
			y = a%10*2 >= 10 ? ((a%10)*2)/10 + (((a%10)*2)%10) + y
						    : ((a%10)*2) + y;
			a = a/10;
			x = a%10 + x;
			a = a/10;
		}
	}
//_______________________________________________________________________________________
//											Вывод ответа на экран
	if (b >= 34 && b <=37 && (x+y)%10 == 0)
	{
		printf("AMEX\n");
	} 

	else if (b >= 51 && b <=55 && (x+y)%10 == 0)
	{
		printf("MASTERCARD\n");
	}
	else  if (b/10 == 4 && (x+y)%10 == 0)
	{
		printf("VISA\n");
	}
	else printf("INVALID\n");
}
/*______________________________________________________________________________________________________
~/workspace/pset1/ $ make credit
clang -fsanitize=integer -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wshadow    credit.c  -lcrypt -lcs50 -lm -o credit
~/workspace/pset1/ $ check50 2016.credit credit.c
:) credit.c exists
:) credit.c compiles
:) identifies 378282246310005 as AMEX
:) identifies 371449635398431 as AMEX
:) identifies 5555555555554444 as MASTERCARD
:) identifies 5105105105105100 as MASTERCARD
:) identifies 4111111111111111 as VISA
:) identifies 4012888888881881 as VISA
:) identifies 1234567890 as INVALID
:) rejects a non-numeric input of "foo"
:) rejects a non-numeric input of ""
https://sandbox.cs50.net/checks/7e1eb30ec5b2471da0f30c11934416fc
*/