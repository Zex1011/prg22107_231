#include <iostream>

#include "dice.h"

dice::dice() {}

int dice::roll(int numDice, int sides, int bonus)
{
    int total = bonus;
    for (int i = 0; i < numDice; i++)
    {
        total += (std::rand() % sides) + 1;
    }
    return total;
}
// Dice::roll(); para chamar
