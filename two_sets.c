#include <stdio.h>
#include <stdlib.h>

#define NUM 10
#define LEN 100

int find(char*, char**);
void null(char*);

int main()
{
    char ch = 0;
    char* set1[NUM] = {0};
    char* set2[NUM] = {0};
    int i1 = 0;
    set1[0] = calloc(LEN, sizeof(char));
    int j = 0;

    printf("Enter elements of the 1 set\n");
    while('\n' != (ch = getchar()))
    {
        if(ch == ' ')
        {
            i1++;
            set1[i1] = calloc(LEN, sizeof(char));
            j = 0;
        }
        else
        {
            set1[i1][j] = ch;
            j++;
        }
        
    }
    int i2 = 0;
    set2[0] = calloc(LEN, sizeof(char));
    j = 0;
    printf("Enter elements of the 2 set\n");
    while('\n' != (ch = getchar()))
    {
        if(ch == ' ')
        {
            i2++;
            set2[i2] = calloc(LEN, sizeof(char));
            j = 0;
        }
        else
        {
            set2[i2][j] = ch;
            j++;
        }
        
    }
    printf("Enter new elements of 1 set\n");
    j = 0;
    i1++;
    set1[i1] = calloc(LEN, sizeof(char));
    while('\n' != (ch = getchar()))
    {
        if(ch == ' ')
        {
            i1++;
            set1[i1] = calloc(LEN, sizeof(char));
            j = 0;
        }
        else
        {
            set1[i1][j] = ch;
            j++;
        }
        
    }
    printf("Enter new elements of 2 set\n");
    j = 0;
    i2++;
    set2[i2] = calloc(LEN, sizeof(char));
    while('\n' != (ch = getchar()))
    {
        if((ch == '\n') || (ch == ' '))
        {
            i2++;
            set2[i2] = calloc(LEN, sizeof(char));
            j = 0;
        }
        else
        {
            set2[i2][j] = ch;
            j++;
        }
        
    }
    printf("Enter elements of 1 set to delet\n");
    int i11 = 0;
    j = 0;
    char* tmp = calloc(LEN, sizeof(char));
    null(tmp);
    while(ch = getchar())
    {
        if((ch == ' ') || (ch == '\n'))
        {
            i11 = find(tmp, set1);
            if(i11 == -1)
            printf("%s not found\n", tmp);
            else
            {
                free(set1[i11]);
                set1[i11] = set1[i1];
                set1[i1] = 0;
                i1--;
                null(tmp);
                j = 0;
            }
            if(ch == '\n')
            break;
        }
        else
        {
            tmp[j] = ch;
            j++;
        }
        
    }
    printf("Enter elements of 2 set to delet\n");
    int i22 = 0;
    j = 0;
    tmp = calloc(LEN, sizeof(char));
    null(tmp);
    while(ch = getchar())
    {
        if((ch == ' ') || (ch == '\n'))
        {
            i22 = find(tmp, set2);
            if(i22 == -1)
            printf("%s not found\n", tmp);
            else
            {
                free(set2[i22]);
                set2[i22] = set2[i2];
                set2[i2] = 0;
                i2--;
                null(tmp);
                j = 0;
            }
            if(ch == '\n')
            break;
        }
        else
        {
            tmp[j] = ch;
            j++;
        }
        
    }
    int k = 0;
    j = 0;
    for(j = 0; j <= i1; j++)
    {
        printf("%s, ", set1[j]);
    }
    printf("\n");
    for(j = 0; j <= i2; j++)
    {
        printf("%s, ", set2[j]);
    }
    printf("\n");
    return 0;
}

int find(char* tmp, char** set)
{
    int i = 0;
    int j = 0;
    while((set[i] != 0) && (j < NUM))
    {
        while(set[i][j] == tmp[j])
        {
            j++;
            if(set[j] == 0)
            return i;
        }
        j = 0;
        i++;
    }
    return -1;
}

void null(char* tmp)
{
    for(int i = 0; i < LEN; i++)
    tmp[i] = 0;
}