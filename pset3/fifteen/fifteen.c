/*                     
                    Задание от cs50 "Пятнашки" 
                http://cdn.cs50.net/2016/x/psets/3/hacker3/hacker3.html
(не реализован уровень Бога не реализована раздачи фишек, т.е. есть случаи неразрешенных комбинаций)
*/


/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = 0;
        scanf("%d", &tile);
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}
//________________________________________________________________________________________
//                            Самостоятельная работа
/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
// Можно было реализовать и через одномерный массив
void init(void)
{
    int a[d*d];
    srand(time(NULL)); 
// заранее определяем 0
    a[d*d - 1] = 0;
// заполнение одномерного массива
    for( int i = (d*d) - 2; i >= 0; i--)
    {
        int ran = rand() % ((d*d) - 1) + 1;

        for(int j = (d*d) - 2; j > i; j--)
        {
            if(a[j] == ran)
            {
                ran = rand() % ((d*d) - 1) + 1;
                j = (d*d) - 1;
            }
        }
        a[i] = ran;
    }
// заполнение двумерного массива
    int k = 0;
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            board[i][j] = a[k];
            k++;
        }
    }
}
//________________________________________________________________________________________
/**
 * Prints the board in its current state.
 */
void draw(void)
{
    int z = d*5+1;    //длинна рамки
    int k = 1;       //счетчик для того, чтобы рисовать цифру зеленным

// принтуем верхнюю рамку 
    for(int i = 0; i < z; i++)
        printf("\033[34;47m%c\033[0m", '=');
    printf("\n");
// запускаем инициализацию         
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            printf("\033[34;47m%c\033[0m", '|'); //левая граница
//замена 0 на _
            if(board[i][j] == 0)
            {
                printf("\033[34;47m  %c \033[0m", '_');
            }
//если число больше 10 
            if(board[i][j]/10 >= 1)
            {
                if(board[i][j] == k)
                {
//принтуем зеленым, если фигура стоит на своем месте                    
                    printf("\033[32;47m %d \033[0m", board[i][j]);
                }
                else
                {
                    printf("\033[47m %d \033[0m", board[i][j]);
                }
            }
//если число меньше 10 печатаем дополнительный пробел
            if(board[i][j]/10 == 0 && board[i][j] != 0)
            {
                if(board[i][j] == k)
                {
//принтуем зеленым, если фигура стоит на своем месте                         
                    printf("\033[32;47m  %d \033[0m", board[i][j]);
                }
                else
                {
                    printf("\033[47m  %d \033[0m", board[i][j]);
                }
            }
//увеличиваем счетчик
            k++;
        }
//закрываем поле справа        
        printf("\033[34;47m|\033[0m\n");
//печатаем границу поля
        for(int i = 0; i < z; i++)
            printf("\033[34;47m%c\033[0m", '=');
        printf("\n");
    }
}
//___________________________________________________________________________________
/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            if(board[i][j] == tile)
            {
                for(int ii = 0; ii < d; ii++)
                {
                    for(int jj = 0; jj < d; jj++)
                    {
                        if(board[ii][jj] == 0 &&  ( board[ii-1][jj] == tile ||
                                                    board[ii][jj-1] == tile ||
                                                    board[ii][jj+1] == tile ||
                                                    board[ii+1][jj] == tile ))
                        {
                            board[ii][jj] = tile;
                            board[i][j]   = 0;
                            return true;
                        }
                    }
                }      
            }
        }
    }
    return false;
}
//__________________________________________________________________________________
/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int k = 0;
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            if (++k != (d * d) && board[i][j] != k)
            {
                return false;
            }
        }
    }
    return true;
}

/*
~/workspace/pset3/fifteen/ $ check50 2016.fifteen fifteen.c                                                                       
:) fifteen.c exists
:) fifteen.c compiles
:) init initializes 3x3 board correctly
:) init initializes 4x4 board correctly
:) 3x3 board, move blank up twice
:) 3x3 board, move blank left twice
:) 3x3 board, move blank left then right
:) 3x3 board, move blank up then down
:) 3x3 board, move up-up-left-down-down-left-up-up-right-down-down-right
:) 3x3 board, from start try to move tile 2, 4, 5, 6, 7, 8
:) 3x3 board, move blank left (tile 1) then up (tile 4), then try to move tiles 1, 2, 6, 8
:) 3x3 board, move blank up (tile 3), then try tile 2
:) 3x3.txt wins the 3x3 board
:) 4x4.txt wins the 4x4 board
https://sandbox.cs50.net/checks/e708119177134703869524e6110eb447

=====================
| 11 |  5 | 13 | 15 |
=====================
| 10 |  8 |  3 |  4 |
=====================
| 14 |  1 |  6 |  7 |
=====================
|  9 |  2 | 12 |  _ |
=====================
*/