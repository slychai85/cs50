//                                  Задача от cs50: Crack - brute force attacks

//      http://docs.cs50.net/problems/vigenere/vigenere.html
//  для компиляции надо подключисть библиотеку libcrypt.a,
//  для это надо набрать команду gcc crack.c -o crack -lcrypt

#define _XOPEN_SOURCE 
#include <cs50.h>  
#include <stdio.h>
#include <string.h>  // strlen(s)    strcmp(s,ss)
#include <stdlib.h> // exit(0);
#include <crypt.h> // crypt(s, a)
#include <time.h> // clock_t clock(void)        clock_t / CLOCKS_PER_SEC - 

// CLOCKS_PER_SEC - макрос подсчета времени работы процессора
// Пересчет этого времени в секунды clock_t/CLOCKS_PER_SEC

int main (int argc, string argv[])
{
    string hash = argv[1];
    char s[] = "AAAA";
    char a[] = "50";
    char aa[]= " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ";
//_____________________________________________________________________________________________________
//                            Проверяем кол-во введенных аргументов
    if(argc != 2 || argc > 2)
    {
        printf("Usage: /home/cs50/pset2/vigenere <keyword>\n");
        return 1;
    }
//_____________________________________________________________________________________________________
//                      Перебор || brute force attacks
    for( int i = 0, j = 0, k =0, m = 0 , n = strlen(aa); m < n; i++)
    {
        if( i == n ) {
            i = 0;
            j++;
        } else if (j == n) {
            j = 0;
            k++;
        } else if ( k == n) {
            k = 0;
            m++;
        }
        s[3] = aa[i];
        s[2] = aa[j];
        s[1] = aa[k];
        s[0] = aa[m];
        if(strcmp(crypt(s, a), hash) == 0) {
            printf("%s\n", s);
            printf("Time = %.3f sec\n", clock()/(CLOCKS_PER_SEC*1.));
            exit(0);
        }
    }
}
/*
    ~/workspace/pset2/crack/ $ ./crack 50.jPgLzVirkc //
    hi                                              //      andi:50.jPgLzVirkc
    Time = 17.200 sec                              //
    _____________________________________________________________________________________________________
    ~/workspace/pset2/crack/ $ ./crack 50YHuxoCN9Jkc
    JH                                                  jason:50YHuxoCN9Jkc
    Time = 4.390 sec
    _____________________________________________________________________________________________________
    ~/workspace/pset2/crack/ $ ./crack 50QvlJWn2qJGE
    NOPE                                                malan:50QvlJWn2qJGE
    Time = 6.269 sec
    _____________________________________________________________________________________________________
    ~/workspace/pset2/crack/ $ ./crack 50CPlMDLT06yY
    ha                                              mzlatkova:50CPlMDLT06yY
    Time = 16.138 sec
    _____________________________________________________________________________________________________
    ~/workspace/pset2/crack/ $ ./crack 50WUNAFdX/yjA
    Yale                                            patrick:50WUNAFdX/yjA
    Time = 13.505 sec
    _____________________________________________________________________________________________________
    ~/workspace/pset2/crack/ $ ./crack 50fkUxYHbnXGw
    rofl                                            rbowden:50fkUxYHbnXGw
    Time = 25.834 s
    _____________________________________________________________________________________________________
    summer:50C6B0oz0HWzo      =(
    _____________________________________________________________________________________________________
    stelios:50nq4RV/NVU0I      =(
    _____________________________________________________________________________________________________
    ~/workspace/pset2/crack/ $ ./crack 50vtwu4ujL.Dk
    haha                                            wmartin:50vtwu4ujL.Dk
    Time = 15.724 sec
    _____________________________________________________________________________________________________
    zamyla:50i2t3sOSAZtk     =(

                                Дополнительная информация


    Инфа от сюда:               http://www.firststeps.ru/linux/r.php?15
    Используются для шифрования пароля алгоритмом DES
    #include <stdlib.h>
    #include <crypt.h>
    #include <stdio.h>

    int main()
    {
        printf("crypt(\"password\",\"ab\") = \"%s\"\n", crypt ("password","ab"));
        printf("crypt(\"password\",\"1a.\") = \"%s\"\n",crypt("password","1a."));
        return 0;
    }
    ab - является salt, т.е. дополнительными ключами и основную роль играют только 2
            первых символа и входят в хеш как его начальная часть.
    Ответ:
    crypt("password","ab") = "abJnggxhB/yWI"
    crypt("password","1a.") = "1abtv8E0hkEd6"

    За генерацию паролей отвечает функция crypt(). Подключить ее к программе можно так:

    #define _XOPEN_SOURCE     для linux можно не использовать 
    #include <unistd.h>     для подключения функций шифрования можно использовать - crypt.h.

    Для работы функции требуется два параметра:

        key - это секретный пароль пользователя, который требуется зашифровать
        salt - это так называемый "открытый ключ", или же в понятиях алгоритмов 
            шифрования инициализационные данные. Данный параметр должен состоять из 
            символов a-zA-Z0-9./, т.е. из любых латинских букв, цифр или некоторых символов.

     Просто так откомпилировать программу нельзя, надо обязательно подключить
     библиотеку libcrypt.a, делается это такой командой:

    slychai85@mif:~$         gcc test.c -o test -lcrypt
    slychai85@mif:~$        ./test 
    Ответ:
    crypt("password","ab") = "abJnggxhB/yWI"
    crypt("password","1a.") = "1abtv8E0hkEd6"


    Используйте функцию strcmp() для сравнения строк #include <string.h>

    if (strcmp(a, b) == 0)
       puts("строки равны");
*/