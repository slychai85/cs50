/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>//

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int array[], int n)
{
    // TODO: implement a searching algorithm
    if(array[n-1]==value || array[0]==value )
	{
	    return true;
	}
	int a = 0, k = 0;
	while(n>0)
	{
		n = (n+1)/2 ;
		a = n + k;
		if(array[a] == value)
		{
		    return true;
		}
		if(array[a] <= value)
		{
			k = n;
		}
		else
		{
			k = a - n;
		}
		if(n==1)
		{
			n = 0;
		}
	}
	return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n) sorting algorithm
	for ( int i = 0; i < n; i++ )
	{
		int element = values[i];
		int j = i;
		while (j > 0 && values[j-1] >= element)
		{
			values[j] = values[j-1];
			j = j - 1;
			values[j] = element;
		}
	}
	return;
}
/*
_______________________________________________________________________
                          Сортировка вставками
void insertion_sort(int array[], int n)
{
	for ( int i = 0; i < n; i++ )
	{
		int element = array[i];
		int j = i;
		while (j > 0 && array[j-1] >= element)
		{
			array[j] = array[j-1];
			j = j - 1;
			array[j] = element;
		}
	}
	return;
}
________________________________________________________________________________
                      Сортировка выбором
void selection_sort(int array[], int n)
{
	for ( int i = 0; i < n-1; i++ )
	{
		int min = array[i];
		for ( int j = i+1; j < n; j++)
		{
			if(array[j] < min)
			{
				min = array[j];
			}
			if (min != array[i])
			{
				int swap = array[i];
				array[i] = min;
				array[j] = swap;
			}
		}
	}
	return;
}
__________________________________________________________________________
                             Линейный поиск
bool linear_search(int value, int array[], int n)
{
	int i;
	if (n < 0) 
    {
        return false;
    }
    for(int i = 0; i < n && array[i]!=value; i++)
        ;
    if (i<n)
    {
        return true;
    } 
    else
    {
        return false;
    }
}
________________________________________________________________________
                  Бинарный поиск
bool binary_search(int value, int array[], int n)
{
	int a = 0;
	while (n>0)
	{
		n = n/2;
		a = n + a;
		if(array[n] == value)
		{
			return true;
		}
		else if(array[n] >= array[n-1])
		{
			a = 0;
		}
		else
		{
			a = n;
		}
	}
	return false;
}
*/