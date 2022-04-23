#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Initialize linked list
typedef struct node
{
    int val;
    char *name;
    struct node *next;
    struct node *prev;
} node;

//File reader function
node *fileReader(FILE *file)
{
    node *i = malloc(sizeof(node));
    char word[20];
    int fileRead = fscanf(file, "%s", word);
    if (fileRead != EOF)
    {
        i->name = strdup(word);
        i->next = fileReader(file);
    }
    if (fileRead == EOF)
    {
        return NULL;
    }
    return i;
}

//Reverse linked list function
//In this part geeksforgeeks was used as a source
static void reverse(struct node **i)
{
    struct node *next = NULL;
    struct node *prev = NULL;
    struct node *l = *i;

    while (l != NULL)
    {
        next = l->next;
        l->next = prev;

        prev = l;
        l = next;
    }
    *i = prev;
}

//Write the linked list into the output file
//In this part stackoverflow was used as a source
void writeToFile(node *i, FILE *file)
{
    if (i != NULL)
    {
        fprintf(file, "%s\n", i->name);
        writeToFile(i->next, file);
    }
}

//This is a function to print the linked list
void print(struct node *i)
{
    struct node *tmp = i;
    while (tmp != NULL)
    {
        printf("%s\n", tmp->name);
        tmp = tmp->next;
    }
}

int main(int argc, char *argv[])
{
    char c;
    // Check for correct number of arguments
    if (argc > 3)
    {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    //If only one argumnent was given, then print the input file
    } else if (argc == 2){
	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
 	{
		fprintf(stderr, "Error: cannot open file\n");
        	exit(1);
    	} else{
		c = fgetc(file);
		while(c != EOF){
			printf("%c", c);
			c = fgetc(file);
		}
	fclose(file);
	return 0;
	}
    //If no arguments were given, then write the standard input to standard output
    } else if(argc == 1) {
	char string[256];
	printf("Write to standard input: \n");
	if (fgets(string, 256, stdin)!=NULL){
		printf("Standard output: \n");
		puts(string);
	}
	return 0;
    }

    // Check if input and output files are the same file
    if (strcmp(argv[1], argv[2]) == 0)
    {
        fprintf(stderr, "Error: Input and output file must differ\n");
        exit(1);
    }

    // Open input file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: cannot open file\n");
        exit(1);
    }
    //Read the file into the linked list
    node *i = fileReader(file);

    // Close input file
    fclose(file);

    //Reverse the linked list
    reverse(&i);
    print(i);

    // Open output file
    file = fopen(argv[2], "w");
    if (file == NULL)
    {
        fprintf(stderr, "error: cannot open file\n");
        exit(1);
    }

    //Write the linked list into the output file
    writeToFile(i, file);

    // Close output file
    fclose(file);

    return 0;
}
