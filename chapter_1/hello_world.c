#include <stdio.h>
// Since C99, must declare main as int (implicit no longer supported)
int main() 
{
    printf("for 1.1, type 1. for 1.2, type 2.\n");
    int opt = 0;
    scanf("%d", &opt);

    if (opt == 1) {
        printf("hello, world\n");
    }
    else if (opt == 2) {
        printf("hello, world (imagine something like '\\j' was here\n");
    }
    else {
        printf("hi man that's not an option\n");
    }
}
