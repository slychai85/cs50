//      http://docs.cs50.net/problems/caesar/caesar.html
//  Задача от cs50: шифр Цезаря
#include <stdio.h>
#include <cs50.h>       //get_string()
#include <stdlib.h>    //atoi()
#include <string.h>   //strlen()
#include <ctype.h>   //isalpha(),  isupper () и islower() 

int main (int argc, string argv[])
{
//  проверяем введеный аргумент от пользователя (шифр) и если не верный ввод, отправляем его 
    if(argc !=2)
    {
        printf("print the key\n");
        return 1;
    }
    
    int key = atoi(argv[1]);// преобразование первого аргумента(числа) в int с помощью функции atoi() из библиотеки stdlib.h
    printf("plaintext: ");
    string s = get_string();
// перебираем строку и заменяем буквы
    printf("ciphertext: ");
    for(int i=0, n=strlen(s); i<n; i++)
    {
//если заглавная буква
        if(isalpha(s[i]) && isupper(s[i]))
        {
            s[i] = (s[i]-65+key)%26 + 65;
            printf("%c", s[i]);
        }
//если строчная буква
        else if(isalpha(s[i]) && islower(s[i]))
        {
            s[i] = (s[i]-97+key)%26 + 97;
            printf("%c", s[i]);
        }
// все подряд
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    return 0;
}
// ~/workspace/pset2/caeser/ $ check50 2016.caesar caesar.c
// :) caesar.c exists
// :) caesar.c compiles
// :) encrypts "a" as "b" using 1 as key
// :) encrypts "barfoo" as "yxocll" using 23 as key
// :) encrypts "BARFOO" as "EDUIRR" using 3 as key
// :) encrypts "BaRFoo" as "FeVJss" using 4 as key
// :) encrypts "barfoo" as "onesbb" using 65 as key
// :) encrypts "world, say hello!" as "iadxp, emk tqxxa!" using 12 as key
// :) handles lack of argv[1]
// https://sandbox.cs50.net/checks/537343c0118444b29b3c8088a301ff33