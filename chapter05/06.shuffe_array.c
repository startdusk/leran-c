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

int main(void)
{
    int players[PLAYER_COUNT];
    for (int i = 0; i < PLAYER_COUNT; ++i)
    {
        players[i] = i;
    }

    shuffle_array(players, PLAYER_COUNT);
    for (int i = 0; i < PLAYER_COUNT; ++i)
    {
        printf("player[%d]: %d\t", i, players[i]);
    }
    return 0;
}