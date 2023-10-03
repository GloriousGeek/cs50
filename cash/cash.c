#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // Prompt user for number of cents (positive) and return the same number
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 1);

    return cents;
}

int calculate_quarters(int cents)
{
    // Calculate and return the number of quarters based on the cents owed
    for (int q = 0; cents >= 25; q++);
    {
        q = (cents/25);
        
    }
}

int calculate_dimes(int cents)
{
    // Calculate and return the number of dimes based on cents owed
    int d;
    do
    {
        d = (cents/10);
    }
    while (cents < 10);
    return d;
}

int calculate_nickels(int cents)
{
    // Calculate and return the number of nikels based on cents owed
    int n;
    do
    {
        n = (cents/5);
    }
    while (cents < 5);
    return n;
}

int calculate_pennies(int cents)
{
    // Calculate and return the number of pennies based on the cents owed
    int p;
    do
    {
        p = (cents/1);
    }
    while (cents < 1);
    return p;
}
