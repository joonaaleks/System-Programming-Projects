#include <stdio.h>
#include <string.h>
#define MAX 1024




int main(int argc, char **argv)
{
    FILE *file;
    char line[MAX];

    //Check's if no command line arguments are passed
    if(argc == NULL){
        printf("my-grep: searchterm [file ...]\n");
        exit(1);
    }
    // If a search term, but no file, is specified, sets the input to stdin
    if(argv[2] == NULL){
        file = stdin;
    }


    for(int i=1; i < argc; i++)
    {
        if((file = fopen(argv[i], "r")) == NULL)
        {
            printf("my-grep: cannot open file\n");
            exit(1);
        }

        fclose(file);
    }

    //Go through the file line by line and find the searched term
    while(get_line(line,MAX)){
        if(strstr(line,argv[1]) != NULL){
            printf("%s", line);
        }
    }

    fclose(file);
    free(line);
    
    return 0;
}