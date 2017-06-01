#include <stdio.h>

int main (void)
{
	float 	a ;
	int b, x1, x2, x3, x4;

    
	printf("Введите сумму cдачи: ");
	scanf("%f", &a);
    while (a<0)
    {
        printf("Введите сумму сдачи: ");
        scanf("%f", &a);
    }
    
	b = a*100;
	x1 = b/25;
	b = b - x1*25;
	x2 = b/10;
	b = b - x2*10;
	x3 = b/5;
	x4 = b%5;

	printf("%d 25 коп\n%d 10 коп\n%d 5 коп\n%d 1 коп\n", x1, x2, x3, x4);
}