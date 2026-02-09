#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef unsigned int uint;

#define SET_BIT(REG, POS) (REG|=(1U<<POS))
#define CLEAR_BIT(REG, POS) (REG&=~(1U<<POS))
#define TOGGLE_BIT(REG, POS) (REG^=(1U<<POS))
#define IS_SET_BIT(REG, POS) (REG & (1U << POS))
#define IS_ODD(REG) (REG & 1U != 0)

/* Problem: Count the set bits in a number using Bit Manipulation */
int count_set_bits(uint num)
{
    int count = 0;
    while(num != 0) {
        num = num & (num - 1);
        count++;
    }
    return count;
}

/* Problem: Given an array of size N-1 containing numbers from 1 to N with one number missing, find the missing number without using extra space. */
int find_missing(int arr[], int n)
{
    int xor1 = 0, xor2 = 0;
    for(int i = 1; i<=n; i++)
        xor1 ^= i;
    for(int i = 0; i < n-1; i++)
        xor2 ^= arr[i];

    return xor1 ^ xor2;
}

uint set_bit(uint reg, int pos) {
    return reg | (1u << pos);
}

uint clear_bit(uint reg, int pos) {
    return reg & ~(1u << pos);
}

uint toggle_bit(uint reg, int pos) {
    return reg ^ (1u << pos);
}

bool is_set_bit(uint reg, int pos) {
    return (reg & (1u << pos)) != 0;
}

bool is_prime(uint num) {
    if(num < 2) return false;
    if(num == 2) return true;
    if(num % 2 == 0) return false;

    for(uint i = 3; i <= num / i ; i+= 2) {
        if( num % i == 0)
            return false;
    }
    return true;
}

bool is_power_of_two(uint num) {
    return num != 0 && (num & (num - 1) == 0);
}

uint32_t swap_nibble(uint32_t num) {
    uint32_t high = (num & 0xF0) >> 4;
    uint32_t low = (num & 0x0F);
    return (low << 4) | high;
}

void swap(uint32_t *a, uint32_t *b) {
    if (a == b) return;
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void endian_check(uint num) {
    unsigned char* c = (unsigned char*) &num;
    if(c[0] == 1) {
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }
}

