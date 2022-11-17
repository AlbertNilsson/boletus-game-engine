
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void copy_file_content(char *dest, char fileName[100]) {

  FILE *file = fopen ( fileName, "r" );
  const unsigned int lineSize = 1000; 


  if (file != NULL) {
    char line [lineSize];
    while(fgets(line,sizeof line,file)!= NULL) /* read a line from a file */ {
      //fprintf(stdout,"%s",line); //print the file contents on stdout.
    strncat(dest,line, lineSize-1);
      
    }

    fclose(file);
  }
  else {
    perror(fileName); //print the error message on stderr.
  }
}
