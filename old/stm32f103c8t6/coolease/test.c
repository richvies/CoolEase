#include <stdio.h>
#include <stdint.h>

int main()
{
    uint16_t uval = 0xF070;
    int16_t sval = uval;
    sval = sval >> 4;

    printf("unsigned: %04x Signed: %04x\n", uval, sval);
}