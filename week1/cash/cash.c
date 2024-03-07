#include <cs50.h>
#include <stdio.h>
int calculate_quarters(int change);
int calculate_dimes(int change);
int calculate_nickels(int change);
int calculate_pennies(int change);

int main(void)
{

    // promt tthe user for change owed, in cents
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);

    // calculate how many quarters you should give customer
    // subtract the value of those quarters from cents
    int quarters = calculate_quarters(change);
    change = change - quarters * 25;

    // Calculate how many dimes you should give customer
    // Subtract the value of those dimes from remaining cents
    int dimes = calculate_dimes(change);
    change = change - dimes * 10;

    // Calculate how many nickels you should give customer
    // Subtract the value of those nickels from remaining cents
    int nickels = calculate_nickels(change);
    change = change - nickels * 5;

    // Calculate how many pennies you should give customer
    // Subtract the value of those pennies from remaining cents
    int pennies = calculate_pennies(change);
    change = change - pennies * 1;

    // Sum the number of quarters, dimes, nickels, and pennies used
    int coins = quarters + dimes + nickels + pennies;

    // Print that sum
    printf("%i\n", coins);
}

int calculate_quarters(int change)
{
    return change / 25;
}

int calculate_dimes(int change)
{
    return change / 10;
}

int calculate_nickels(int change)
{
    return change / 5;
}

int calculate_pennies(int change)
{
    return change;
}
