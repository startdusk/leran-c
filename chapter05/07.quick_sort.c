#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER_COUNT 50

void swap_elements(int array[], int first, int second)
{
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}

// 打乱数组顺序
void shuffle_array(int array[], int length)
{
    srand(time(NULL));
    // rand() => [0, RAND_MAX]
    for (int i = length - 1; i > 0; --i)
    {
        int random_number = rand() % length;
        swap_elements(array, i, random_number);
    }
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int partition = low;
    for (int i = low; i < high; ++i)
    {
        if (array[i] < pivot)
        {
            swap_elements(array, i, partition++);
        }
    }

    swap_elements(array, partition, high);
    return partition;
}

void quick_sort(int array[], int low, int high)
{
    if (low >= high)
        return;

    int part = partition(array, low, high);
    quick_sort(array, low, part - 1);
    quick_sort(array, part + 1, high);
}


int main(void)
{
    int players[PLAYER_COUNT];
    for (int i = 0; i < PLAYER_COUNT; ++i)
    {
        players[i] = i;
    }

    shuffle_array(players, PLAYER_COUNT);
    printf("shffle===========\n");
    for (int i = 0; i < PLAYER_COUNT; ++i)
    {
        printf("player[%d]: %d\t", i, players[i]);
    }
    printf("\n");
    printf("quick===========\n");
    quick_sort(players, 0, PLAYER_COUNT - 1);
    for (int i = 0; i < PLAYER_COUNT; ++i)
    {
        printf("player[%d]: %d\t", i, players[i]);
    }
    return 0;
}