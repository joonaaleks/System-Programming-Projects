#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


int main(int argc, char *argv[])
{
    FILE *file;
    char buff;
    int i;
    //Run through all the given files
    for(int i=1; i < argc; i++)
    {   
        // If an error occurs when opening the file, prints error msg and the error number
        if((file = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "%s: %s : %s\n", argv[0],argv[i],strerror(errno));
            exit(0);
        }
        //Prints the contents of the file one character at a time
        while((buff = getc(file)) != EOF){
            printf("%c", buff);
        }
        fclose(file);
    }
    return 0;
}
