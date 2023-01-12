#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

int Comparing(const void *a, const void *b);

int main()
{
    int WORKS[100000][2];
    int N, i, max_late = 0, Count_Days = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++) scanf("%d %d", &WORKS[i][0], &WORKS[i][1]);

    qsort(WORKS, N, sizeof(int) * 2, Comparing);

    for (i = 0; i < N; i++)
    {
        Count_Days = Count_Days + WORKS[i][1];
        if (Count_Days > WORKS[i][0] + 10)
        {
            if (Count_Days - (WORKS[i][0] + 10) > max_late) max_late = Count_Days - (WORKS[i][0] + 10);
        }
    }

    printf("%d", max_late * 1000);
    return 0;
}

int Comparing(const void *a, const void *b)
{
    return (*((int *)a) - *((int *)b));
}