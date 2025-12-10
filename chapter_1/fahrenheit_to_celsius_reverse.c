#include <stdio.h>

int main() 
{
    int lower = 0;
    int upper = 300;
    int step = 20;
    float fahr = upper;
    float celsius;

    printf("fahrenheit\tcelsius\n");
    while (fahr >= lower) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f\t\t   %6.1f\n", fahr, celsius);
        fahr -= step;
    }
}
