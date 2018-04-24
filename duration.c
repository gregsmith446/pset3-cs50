#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> //atoi - converts str to int
#include <string.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string test)
{
    int numerator = atoi(&test[0]);
    int denominator = atoi(&test[2]);

    // for the above data, the demoninator determines what to do with the numerator to return "number of eight notes"

    switch(denominator) {
        case 8 :
            return numerator;
        case 4 :
            return numerator * 2;
        case 2 :
            return numerator * 4;
    }

    printf("The number of eights is %i\n", numerator);

    return numerator;

}

int main(void)
{
    int numerator = duration("1/2");
    printf("%i\n", numerator);
}