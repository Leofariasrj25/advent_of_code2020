/*
	input: text separated by lines with passwords and the password policy
	output: how many of these passwords are valid.

	1 - como o c trabalha com strings
		strings are arrays of characters, the array terminates with a null byte. represented by \0
	2 - como ler arquivos do disco via c
		através de fopen("filename.txt", "mode"), fgets(buffer, limit, FILE *fp)
	3 - c possui um split()?
		sim strtok("string", delimiter)
*
Open the file containing the passwords and respective polices
read one line at a time
break the line into two sections: policy and password
analyze policy and setup the criteria to validate the password
if the password is valid add it to the counter with valid passwords
once the analysis is complete go to the next line
if there aren't new line to read, then print the total.
*/ 

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXCHAR 100
int main(int argc, char *argv[])
{
  FILE *fp;
  char password[MAXCHAR];
  char* filename = "./password_list.txt";
  int valid_passwords = 0;

  fp = fopen(filename, "r");
  
  while(fgets(password, MAXCHAR, fp)!= NULL){
    char separator[2] = " ";

    char *positions = strtok(password, separator); 
    // get the part of the string where the character resides and extract it 
    char pass_char = strtok(NULL, separator)[0];
    char *u_password = strtok(NULL, separator);
  
    // extracting the positions and converting to int
    char *pos_1 = strtok(positions, "-");
    int first_pos = atoi(pos_1);

    char *pos_2 = strtok(NULL, "-");
    int second_pos = atoi(pos_2);

    // the password policy's index is 1 based. that's why we convert it to 0 base
    // either the first position or the second position should contain the character
    if ((u_password[first_pos - 1] == pass_char) != (u_password[second_pos - 1] == pass_char)){
      valid_passwords++;
    }
  }
  
  printf("Total of valid passwords is: %d\n", valid_passwords);

  fclose(fp);
  return 0;
}

