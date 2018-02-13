
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main( int argc, char **argv) 
{
	char buffer[1000];
	char archive[10000] = {0};
	int count = 0;
	long freqaz[26] = {0}; //One for each letter
	long sum = 0;
	//"Usage is \n decrypt < infile > output \n");
	

	//Parses through text. Counts each letter. Adds to the array. Adds to a big array.
	while(fgets( buffer, sizeof(buffer), stdin) != (char *) 0) { 
		int i; /* legal here and scoped to the end of the while loop */

		for( i=0; i< 1000; i++) {  /* the two possible conditions for end of line */
			archive[count] = buffer[i];
			count++;
			if( buffer[i] == '\n') break;
			if( buffer[i] == '\0') break;
			
			//t = tolower(buffer[i]); //Not necessary, but I'll leave it.
			sum++;
			switch (buffer[i]) { //Probably not the most efficient way of writing this. But it's readable.
			case 'a':			 //Also, obviously written by me. Other stuff before this, not so much.
				freqaz[0]++;
				break;
			case 'b':
				freqaz[1]++;
				break;
			case 'c':
				freqaz[2]++;
				break;
			case 'd':
				freqaz[3]++;
				break;
			case 'e':
				freqaz[4]++;
				break;
			case 'f':
				freqaz[5]++;
				break;
			case 'g':
				freqaz[6]++;
				break;
			case 'h':
				freqaz[7]++;
				break;
			case 'i':
				freqaz[8]++;
				break;
			case 'j':
				freqaz[9]++;
				break;
			case 'k':
				freqaz[10]++;
				break;
			case 'l':
				freqaz[11]++;
				break;
			case 'm':
				freqaz[12]++;
				break;
			case 'n':
				freqaz[13]++;
				break;
			case 'o':
				freqaz[14]++;
				break;
			case 'p':
				freqaz[15]++;
				break;
			case 'q':
				freqaz[16]++;
				break;
			case 'r':
				freqaz[17]++;
				break;
			case 's':
				freqaz[18]++;
				break;
			case 't':
				freqaz[19]++;
				break;
			case 'u':
				freqaz[20]++;
				break;
			case 'v':
				freqaz[21]++;
				break;
			case 'w':
				freqaz[22]++;
				break;
			case 'x':
				freqaz[23]++;
				break;
			case 'y':
				freqaz[24]++;
				break;
			case 'z':
				freqaz[25]++;
				break;
		}	
		}
	}

//key = 26 - key; Will use this in conjuction with the original ceaser.c program
//Analyze and make a guess on what the key is.
//Check if key makes words.

//Compare all values in frequency table and find max.
int max = 0;

int letternum = 0; //97 = 'a', 26 = invalid char.
int i;
    for(i = 0; i <= 25; i++) {
        if ( max < freqaz[i] ){
			max = freqaz[i]; //Highest value. Aka most likely letter to be 'e'.
			letternum = i; //The letter that corresponds to the minumum value.
		}
    }   
  
//The gud part.
		int unkey = 26 - ( (letternum - 4)); //Converts letter into the reverse caesar key. e is the 4th (starting from 0) letter.
		FILE *fp;
		fp = fopen("temp.one.decrypt", "w");
		for( i=0; i< count; i++) {
			putc(archive[i], fp);
		}
		fclose(fp);
		char string[50] = "./ceaser 26 <temp.one.decrypt >result.txt";
		sprintf(string, "./ceaser %d <temp.one.decrypt >result.txt", unkey);
		system(string);
return 0;
}
