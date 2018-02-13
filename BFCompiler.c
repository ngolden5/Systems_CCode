/*
 * BFCompiler.c
 * 
 * Copyright 2015 Nicholas Golden <nick@Nick>
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
int main(int argc, char **argv)
{
	FILE *fp;
	fp = fopen("temp.c", "w");
	
	char buffer[1000];
	int i = 0;
	fputs("#include <stdio.h> \n", fp);	
	fputs("unsigned char buffer[30000];", fp);
	fputs("unsigned char *cp = buffer;", fp);

	
	//Input BF code. Load into buffer. Check.
	//While/for loop with a switch/case statement until EOF trigger. Check.
	//Print C source code into a file.
	//Testing reveals that we might have to do it twice.
	fputs("main(int argc, char **argv) {", fp); //Starts the whole shebang.
	while(fgets( buffer, sizeof(buffer), stdin) != (char *) 0)	 
	{
		for( i=0; i< 1000; i++) {  /* the two possible conditions for end of line */
		
			if( buffer[i] == '\n') break;
			if( buffer[i] == '\0') break;
			switch(buffer[i]) {
				case '>':
					fputs("cp++;", fp);
					break;
				case '<':
					fputs("cp--;", fp);
					break;
				case '+':
					fputs("(*cp)++;", fp);
					break;
				case '-':
					fputs("(*cp)--;", fp);
					break;
				case '.':
					fputs("fputc(*cp, stdout);", fp);
					break;
				case ',':
					fputs("*cp = (unsigned char)fgetc(stdin);", fp);
					break;
				case '[':
					fputs("while(*cp){", fp);
					break;
				case ']':
					fputs("}", fp);
					break;
			}
		}
	}
	fputs("return 1;}", fp); //Closes the whole shebang.
	fclose(fp);
	system("gcc -o output temp.c");
	system("chmod 777 output");
	system("./output");
	system("echo It works. See?");
	return 0;

}

