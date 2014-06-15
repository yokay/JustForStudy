#include <stdio.h>

void exchange(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
void print_graph(int *A, int A_lengt, char graph[][8])
{
    int i, j, temp;
    for(i = 0; i < 8; i++)
    {
        temp = A[i];
        if(temp == 0)
            continue;
        for(j = 0; j < 8; j++)
        {
            graph[j][i] = (temp--) ? ('|') : (' ');
            if (temp == 0)
                break;
        }
    }   
   /* 
    for(i = 7; i >= 0; i--)   
    {
        for(j = 0; j < 8; j++)
            printf("%c ", graph[i][j]);
        printf("\n");
    }
    */
}
void print_graph_exchange(int *A, int A_length, int he, int she, char graph[][8])
{
    int i, j;
    char temp[8] = {' '};
    for (i = 0; i < A_length; i++)
    {
        temp[i] = graph[i][he];
        graph[i][he] = graph[i][she];
        graph[i][she] = temp[i];
    }
    for(i = 7; i >= 0; i--)   
    {
        for(j = 0; j < he; j++)
            printf("  ");
        printf("%c ", graph[i][he]);
        for(j = he+1; j < she; j++)
            printf("  ");
        printf("%c ", graph[i][she]);
        for(j = she + 1; j < 8; j ++)
            printf("  ");
        printf("\n");
    }
}

void print_array(int *A, int A_length)
{
    int i;
    for(i = 0; i < A_length; i++)
        printf("%d ", A[i]);
    printf("\n");
    printf("---------------\n");
}
void selectoin_sort(int *A, int A_length)
{
    int i, j, min;
    char graph[8][8] = {' '};
    print_graph(A, A_length, graph);
    for(i = 0; i < (A_length-1); i++)
    {
        min = i;
        for(j = i+1; j < A_length; j++)
        {
            if(A[j] < A[min])
                min = j;
        }
        print_graph_exchange(A, A_length, i, min, graph);
        print_array(A, A_length);
        exchange(A+i, A+min);
    }
}

int main(void)
{
    int i, j;
    int temp;
    int num[] = {2, 3, 6, 1, 7, 3, 0, 1};
    selectoin_sort(num, 8);
}
