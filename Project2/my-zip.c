#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


int main(int argc, char *argv[]){

    FILE *file;
    char str[MAX];
    char current[MAX];
    int count=1;
    
    
    if(argc == '\0'){
        printf("my-zip: file1 [file2 ...]\n");
        exit(1);
    }

    

    for(int i=1; i < argc; i++)
    {
        // If an error occurs when opening the file, prints error msg
        if((file = fopen(argv[i], "r")) == NULL)
        {
            printf("my-zip: cannot open file\n");
            exit(1);
        }
        //Goes through all the characters in the file
        while(fread(str, 1, 1,file)){


            //Checks if the next is the same as the current character, if so, increases count by 1
            //Used https://www.youtube.com/watch?v=jAsGAQbdV-Y as reference for the comparing of current and previous characters
            if(strcmp(current,str) == 0){
                count++;
            }
            //Writes the previous characters and count to the stdout if the previous character is not the same as the current
            //Used https://www.youtube.com/watch?v=jAsGAQbdV-Y here as reference for resetting the current char and its counter
            else{
                fwrite(&count,sizeof(count),1,stdout);  
                fwrite(str, 1, 1, stdout);
                //Reset the current char and the count
                strcpy(current,str);
                count=1;
            }
        }
        fclose(file);
    }
    
    return 0;
}