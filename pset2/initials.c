//  Задача от cs50 про ввод имен и их вывод ФИО (уровень 2)
//  http://docs.cs50.net/problems/initials/more/initials.html

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    string s = get_string();
    
    for(int i = 0, n = strlen(s) ; i < n; i++)
    {
        if(i == 0 && s[0]!=' ')
        {
            printf("%c", toupper(s[0]));
        }
        
        else if(s[i]==' ' && s[i+1] != ' ')
        {
            printf("%c", toupper(s[i+1]));
        }
    }
    printf("\n");
}
// ~/workspace/pset2/initials/ $ check50 2016.initials.more initials.c
// :) initials.c exists
// :) initials.c compiles
// :) outputs "MB" for "Milo Banana"
// :) outputs "MB" for "milo banana"
// :( outputs "MB" for " milo  banana "
//   \ expected output, but not "MB\u0000\n"
// :( outputs "MB" for "  milo banana  "
//   \ expected output, but not "MB\u0000\n"
// :) outputs "RTB" for "   robert   thomas bowden"
// :) outputs "RTB" for "Robert Thomas Bowden"
// :) outputs "R" for "ROB"
// :) outputs "RTB" for "Robert thomas Bowden"
// https://sandbox.cs50.net/checks/2a434670229d4772bdbbd5b11543ea4e




//  strlen(s)       - определение длины строки из библиотеки     <string.h>
//  toupper(s[0])   - смена регистра из библиотеки               <ctype.h>
//  s[0]+= 'A'-'a'  - смена регистра, с нижнего на верхний

//  это for(int i=0, n=strlen(s); i<n; i++) лучше,
//  чем for(int i=0; i<strlen(s); i++)
