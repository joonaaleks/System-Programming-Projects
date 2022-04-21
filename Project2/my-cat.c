#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


int main(int argc, char **argv)
{
    FILE *file;
    char buff;
    int i;

    for(int i=1; i < argc; i++)
    {
        if((file = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "%s: %s : %s\n", argv[0],argv[i],strerror(errno));
            exit(0);
        }

        while((buff = getc(file)) != EOF){
            printf("%c", buff);
        }
        fclose(file);
    }
    return 0;
}
