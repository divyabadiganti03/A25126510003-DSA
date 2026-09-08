#include <stdio.h>
int main()
{
    int n, i, j, key;
    int shifts = 0;
    printf("Enter number of students: ");
    scanf("%d", &n);
    int marks[n];
    printf("Enter %d student marks:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &marks[i]);
    }
    for (i = 1; i < n; i++)
    {
        key = marks[i];
        j = i - 1;
        while (j >= 0 && marks[j] > key)
        {
            marks[j + 1] = marks[j];
            j--;
            shifts++;
        }
        marks[j + 1] = key;
        printf("\nAfter Pass %d: ", i);
        for (int k = 0; k < n; k++)
        {
            printf("%d ", marks[k]);
        }
    }
    printf("\n\nFinal Sorted Marks:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", marks[i]);
    }
    printf("\n\nTotal number of element shifts = %d\n", shifts);
    return 0;
}
