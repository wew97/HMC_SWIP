#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    int age;
} Student;

void deepcopyStudent(Student *src, Student *dest)
{
    dest->age = src->age;
    char *temp = malloc(sizeof(char) * strlen(src->name));
    if (temp != NULL)
    {
        strcpy(temp, src->name);
        dest->name = temp;
        
        free(temp);
    }
}

int main(int argc, char *argv[])
{
    Student *X = (Student *)malloc(sizeof(Student));
    Student *Y = (Student *)malloc(sizeof(Student));

    if (X != NULL && Y != NULL)
    {
        X->name = "Tom";
        X->age = 27;
        Y->name = "Jack";
        Y->age = 33;

        printf("Before Deep Copy\n");
        printf("X: %s(%d) ", X->name, X->age);
        printf("Y: %s(%d)\n\n", Y->name, Y->age);

        deepcopyStudent(Y, X);

        printf("After Deep Copy\n");
        printf("X: %s(%d) ", X->name, X->age);
        printf("Y: %s(%d)\n", Y->name, Y->age);

        free(X);
        free(Y);
    }
}