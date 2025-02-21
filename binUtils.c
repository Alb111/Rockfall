#include <math.h>
// These are function in which i store the state of the cell
// Each cell is going to be a 4 bit number where:
// bit 0 -> player
// bit 1 -> ground
// bit 2 -> rock
// bit 3 -> air

// the state of each of these bits will represent the state of
// the cell so if we had like

// 1100

// this cell would be player with ground
int setNthBitHigh(int index, int bits)
{
    return bits + (int)(pow(2, index) + 0.5);
}

int setNthBitLow(int index, int bits)
{
    return bits - (int)(pow(2, index) + 0.5);
}

int setGroundAirPlayer(int *cell)
{
    *cell = 13;
    return 0;
}

int setGroundAir(int *cell)
{
    *cell = 5;
    return 0;
}

int setAir(int *cell)
{
    *cell = 1;
    return 0;
}