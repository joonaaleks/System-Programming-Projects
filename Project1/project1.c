#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int val;
    char *name;
    struct node *next;
    struct node *prev;
} node;

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

void writeToFile(node *i, FILE *file)
{
    if (i != NULL)
    {
        fprintf(file, "%s\n", i->name);
        writeToFile(i->next, file);
    }
}

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
    // Check for correct number of arguments
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    // Check if input and output files are the same file
    if (strcmp(argv[1], argv[2]) == 0)
    {
        fprintf(stderr, "Error: Input and output file must differ\n");
        return 1;
    }

    // Open input file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "error: cannot open file %s\n", file);
        return 1;
    }

    node *i = fileReader(file);

    // Close file
    fclose(file);

    printf("\n");

    reverse(&i);
    print(i);

    // Open output file
    file = fopen(argv[2], "w");
    if (file == NULL)
    {
        fprintf(stderr, "error: cannot open file\n");
        return 1;
    }

    writeToFile(i, file);

    // Close file
    fclose(file);

    return 0;
}