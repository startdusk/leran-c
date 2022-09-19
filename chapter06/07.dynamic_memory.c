#include <stdio.h>
#include <stdlib.h>

#define PLAYER_COUNT 10

// 由于是数组，所以ptr必须是二级指针(一级指针会被拷贝传入, 必须使用二级指针保存原来指向的地址)
void init_pointer_players(int **ptr, int len, int default_val)
{
    *ptr = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
        (*ptr)[i] = default_val;
}

int main(void)
{
    // 动态内存分配
    int *players;
    // init_pointer_players(&players, PLAYER_COUNT, 0);
    // init_pointer_players 等价于 players = calloc(PLAYER_COUNT, sizeof(int)) 初始化数组所有元素为0
    players = calloc(PLAYER_COUNT, sizeof(int));
    for (int i = 0; i < PLAYER_COUNT; i++)
    {
        printf("players[%d]=%d\t", i, players[i]);
        players[i] = i;
    }
    printf("\n");

    for (int i = 0; i < PLAYER_COUNT; i++)
    {
        printf("players[%d]=%d\t", i, players[i]);
    }

    // 重新分配内存 realloc(注意，realloc会给原来的player扩容并搬运原来的数据，但扩容的内存不会被初始化成0)
    players = realloc(players, PLAYER_COUNT * 2 * sizeof(int));

    // 释放内存
    free(players);

    return 0;
}

// 常见的指针使用错误
// 1.忘记在使用完毕之后释放内存
// 2.使用了已经释放的内存
// 3.使用了超出边界的内存
// 4.改变内存的指针，导致无法正常释放

// 动态内存使用建议
// 1.避免修改指向已分配的内存的指针
// 2.对于free之后的指针主动置为NULL
// 3.避免将过多的指针指向动态分配的内存
// 4.动态内存遵循谁分配谁释放的原则
