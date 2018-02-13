/*
 * SeeOErato.c
 * 
 * Copyright 2015 Nicholas Golden <nick@Crunchbang>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	long count_i = 0;
	long count_j = 0;
	long value = 2000000;
	long max = (long) sqrt(value);
	long sum = 0;
	long *array = (long*)malloc(value * sizeof(long));
	
	for (count_i = 2; count_i <= max; count_i++)
		{
		 	if (array[count_i] == 0)
			{
				for (count_j = count_i*count_i; count_j < value; count_j = count_j+ count_i)
				{
					array[count_j] = 1;
				}
			
			}
		}
	
	
	if (array==NULL)
		{
			printf("Error allocating requested memory.");
			exit (1);
		}
	
	for (count_i = 2; count_i < value; count_i++)
		{
			if (array[count_i] == 0)
			{
				sum += count_i;
			}
		}
	

	free(array);
	printf("The sum is %ld \n", sum);
	return 0;
}



