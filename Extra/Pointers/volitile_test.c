#include <stdio.h>
#include <stdint.h>


#define P_REG                   (*((volatile uint8_t*)0x1))
#define TWO                     0x2

#define GPIO_PORTF_LOCK_R       (*((volatile uint32_t *)0x40025520))
#define GPIO_LOCK_KEY           0x4C4F434B

#define MEMORY_ADDRESS          0x1000
#define P                       ((volatile uint16_t*)MEMORY_ADDRESS)
#define LIM                     *(int*)0x5


int main(int argc, char const *argv[])
{
    uint8_t *p_reg = NULL;

    // int one = ONE;
    int two = TWO;
    
    // p_reg = (uint8_t*)&one;
    // printf("%d\n", *p_reg);

    p_reg = (uint8_t*)&two;
    printf("%d\n", *p_reg);

    
    // uint8_t *p_reg = (uint8_t*)ONE;
    // TWO = ONE;
    // uint16_t *p = (uint16_t*)MEMORY_ADDRESS;
    // GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
    // int two = GPIO_PORTF_LOCK_R;
    // printf("%d\n", two);
    // uint8_t a = &P_REG;
    // printf("1. unchanged: %d\n", (*((volatile uint8_t*)&a)));

    // P_REG = TWO;
    // uint16_t *a = (uint16_t*)P;
    // printf("unchanged: %d\n", *((uint16_t*)&a));

    // P = TWO;
    // LIM = MEMORY_ADDRESS;
    // a = (uint16_t*)P;
    // printf("changed: %d\n", *((uint16_t*)&a));
    // puts("hi");




    return 0;
}

