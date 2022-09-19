#include <stdio.h>

union Operand
{
    int int_perand;        // 4
    double double_operand; // 8
    char *string_operand;  // 8
};

typedef union NewOperand
{
    int int_perand;        // 4
    double double_operand; // 8
    char *string_operand;  // 8
} NewOperand;

typedef struct Instruction
{
    int operator;
    NewOperand operand;
} Instruction;

void process(Instruction *instruction)
{
    switch (instruction->operator)
    {
    case 1:

        break;

    default:
        break;
    }
}

int main(void)
{
    NewOperand operand = {.int_perand = 5,
                          .double_operand = 8.0};
    // 联合体是互斥，后赋值的会覆盖前面的，所以这里会打印出 0， 8.0
    printf("%d\n", operand.int_perand);     // 0
    printf("%f\n", operand.double_operand); // 8.0
    return 0;
}