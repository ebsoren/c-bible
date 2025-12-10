#include <stdio.h>

int main() 
{
    int lower = 0;
    int upper = 300;
    int step = 20;
    float fahr;
    float celsius = lower;

    printf("celsius\tfahrenheit\n");
    while (celsius <= upper) {
        fahr = (celsius) * 9.0 / 5.0 + 32.0;
        printf("%3.0f\t   %6.1f\n", celsius, fahr);
        celsius += step;
    }
}
