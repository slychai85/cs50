//                                    Задача от cs50: шифр Виженера

//      http://docs.cs50.net/problems/vigenere/vigenere.html

#include <stdio.h>
#include <cs50.h>      //get_string()
#include <string.h>   //strlen()
#include <ctype.h>   //isalpha(),  isupper () и islower() 

int main (int argc, string argv[]) 
{
//                              Проверяем кол-во введенных аргументов
    if(argc != 2 || argc > 2)
    {
        printf("Usage: /home/cs50/pset2/vigenere <keyword>\n");
        return 1;
    }
//_____________________________________________________________________________________________________
//                              Проверка шифра: если есть цифры, то предупреждаем пользователя

    string k = argv[1];
    for (int i = 0, n = strlen(k); i < n; i++)
    {
        if(isalpha(k[i])==0)                    // функция для определения символа в буквенном регистре
        {
            printf("Keyword must only contain letters A-Z and a-z\n");
            return 1;
        }
    }
//______________________________________________________________________________________________________
//                              Вывод на экран сообщения и ввод предложения, которое надо зашифровать    
    printf("plaintext: ");
    string s = get_string();
    printf("ciphertext: ");
//_______________________________________________________________________________________________________
//                              Проверка полученного предложения и его замена
    for(int i=0, j=0, ch = strlen(k), p =strlen(s); i<p; i++)
     {
//если в предложение заглавная буква
        if(isalpha(s[i]) && isupper(s[i]))
        {
// если в шифре заглавная буква
            if(isupper(k[j]))
            {
                s[i] = ((s[i]-65)+(k[j]-65))%26 + 65;
                j++;
                j = j%ch;
                printf("%c", s[i]);
            }
// если в шифре строчная буква
            else  
            {
                s[i] = ((s[i]-65)+(k[j]-97))%26 + 65;
                j++;
                j = j%ch;
                printf("%c", s[i]);
            }
        }
//если  в предложение строчная буква
        else if(isalpha(s[i]) && islower(s[i]))
        {
// если в шифре заглавная буква
            if(isupper(k[j]))
            {
                s[i] = ((s[i]-97)+(k[j]-65))%26 + 97;
                j++;
                j = j%ch;
                printf("%c", s[i]);
            }
// если в шифре строчная буква
            else
            {
                s[i] = ((s[i]-97)+(k[j]-97))%26 + 97;
                j++;
                j = j%ch;
                printf("%c", s[i]);
            }
        }
// печатаем все подряд, кроме букв
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}

// ~/workspace/pset2/vigenere/ $ check50 2016.vigenere vigenere.c
// :) vigenere.c exists
// :) vigenere.c compiles
// :) encrypts "a" as "a" using "a" as keyword
// :) encrypts "barfoo" as "caqgon" using "baz" as keyword
// :) encrypts "BaRFoo" as "CaQGon" using "BaZ" as keyword
// :) encrypts "BARFOO" as "CAQGON" using "BAZ" as keyword
// :) encrypts "world!$?" as "xoqmd!$?" using "baz" as keyword
// :) encrypts "world, say hello!" as "xoqmd, rby gflkp!" using "baz" as keyword
// :) handles lack of argv[1]
// :) handles argc > 2
// :) rejects "Hax0r2" as keyword
// https://sandbox.cs50.net/checks/e022d69d2c7c453480733456b8222211