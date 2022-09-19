#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(int *array, int len)
{
    srand(time(NULL));

    for (int i = len - 1; i > 0; i--)
    {
        int random_num = rand() % i;
        swap_int(array + i, array + random_num);
    }
}

int *partition(int *low, int *high)
{
    int pivot = *(low + (high - low) / 2);
    int *p = low;
    int *q = high;
    while (1)
    {
        while (*p < pivot)
            p++;
        while (*q > pivot)
            q--;

        if (p >= q)
            break;
        swap_int(p, q);
    }
    return q;
}

void quick_sort(int *low, int *high)
{
    if (low >= high)
        return;
    int *part = partition(low, high);
    quick_sort(low, part - 1);
    quick_sort(part + 1, high);
}

int main(void)
{
    return 0;
}