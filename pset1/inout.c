#include <stdio.h>
//Функция возведения в квадрат числа а
int sqr(int a)
{
    int b;
    b = a*a;
    return a*a;
}
//главная функция
int main(void)
{
    int a;
    printf("введите целое число = ");
    scanf("%d", &a);
    printf("%d\n", sqr(a));
}