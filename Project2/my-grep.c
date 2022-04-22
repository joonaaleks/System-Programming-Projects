#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *file;
    char *line;
    size_t bufsize = 254;

    //Check's if no command line arguments are passed
    if(argc == '\0'){
        printf("my-grep: searchterm [file ...]\n");
        exit(1);
    }
    // If a search term, but no file, is specified, sets the input to stdin
    if(argv[2] == NULL){
        file = stdin;
    }

    line = (char *)malloc(bufsize*sizeof(char));
    if(line == NULL){
	perror("Unable to allocate linebuffer");
	exit(1);
    }


    for(int i=2; i < argc; i++)
    {
        if((file = fopen(argv[i], "r")) == NULL)
        {
            printf("my-grep: cannot open file\n");
            exit(1);
        }
    }

    //Go through the file line by line and find the searched term
    while(getline(&line,&bufsize,file) != -1){
        if(strstr(line,argv[1]) != NULL){
            printf("%s", line);
        }
    }

    fclose(file);
    free(line);
    
    return 0;
}
