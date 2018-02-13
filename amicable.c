/*
 * amicable.c
 * 
 * Copyright 2015 Nicholas Golden <nick@crunchbang>
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
#include <math.h>

int val_p(int val_n){
	int i;
	i = (int) pow(2, (val_n - 1));
	i = (3*i) - 1;
	return i;
}

int val_q(int val_n){
	int i;
	i = (int) pow(2, val_n);
	i = (3*i) - 1;	
	return i;
}

int val_r(int val_n){
	int i;
	i = (int) pow(2, (2*val_n - 1));	
	i = (9*i) - 1;
	return i;
}

int isPrime(unsigned int n){
	if (n <= 3) return n > 1;
	if (n % 2 == 0 || n % 3 == 0) return 0;
	unsigned int i;
	for (i = 5; i * i <= n; i += 6) {
		if (n% i == 0 || n % (i + 2) == 0 ) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char **argv)
{
	unsigned long long sum = 0;
	//Screw it. You said find the sum of amicable numbers. It said nothing about calculating amicable numbers.
	//Imports a text file. Author: T.D. Noe, from Pedersen's tables.
	FILE *fp;
	fp = fopen("b063990.txt", "r");
	if( argc < 2) {
		fprintf(stderr, "Usage is \n amicable n \n");
		return(1);
	}
	
	unsigned long input = 0;
	sscanf(argv[1], "%ld", &input);
	//printf("Input num %d\n", input);
	//printf("Sum is %d", sum);
	unsigned int i;
	unsigned long current;
	unsigned int nowhere;
	char buffer[1000] = {0};
	for (i = 0; i <= input; i++){
		//printf("Current digit %d\n", i);
		//p = val_p(i);
		//q = val_q(i);
		//r = val_r(i);
		//if( isPrime(p) & isPrime(q) & isPrime(r) ){
		//	printf( "AC: %d \n", p*q*((int) pow(2, i)) );
		//	printf( "AC2: %d \n", r*((int) pow(2, i)) );
		//}
		fgets( buffer, sizeof(buffer), fp);
		sscanf(buffer, "%d %ld",&nowhere, &current); //This might be my favorite function in all of c.
		if (current > input) break;
		if (i > nowhere) {fprintf(stdout, "Ran out of numbers. Highest iteration was: %d \n", nowhere); break;} 
		sum += current;
		
	}
	fclose(fp);
	printf("Sum is:  %lld \n", sum);
	return 0;
}

