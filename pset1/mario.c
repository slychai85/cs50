#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int a=0;
    do
    {
        printf("Введите число от 0 до 23: ");
        a = get_float();
        if (a==0 || a==1 || a==2)
        {
            switch (a)
           {
                case 0:
                     break;
                case 1:
                    printf("#  #\n");
                    break;
                case 2:
                    printf(" #  #\n##  ##\n");
                    break;
           }
        } 
        else 
        {
         	 for(int i=1; i<=a; i++)
            {
                for(int x=0; x<a-i ; x++)
                    printf("%s", " ");
                for (int j=0; j<i; j++)
                    printf("#");
                printf("  ");
                for (int j=0; j<i; j++)
                    printf("#");
                printf("\n");
            }
        }
        
    } while (a>23 || a<0);
}


