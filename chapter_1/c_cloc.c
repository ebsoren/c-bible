/*

Bare bones CLOC written in C
Counts code lines, blank lines, and comments

*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* Assume user isn't insane enough to have a line longer than 1000 characters */
#define MAX_LENGTH 1000

/* handle invalid usage of program */
int invalid_usage() {
    printf("usage: ./a.out <filename>\n");
    return 1;
}

/* handle failed fopen */
int invalid_file() {
    perror("error");
    return 1;

}

int main(int argc, char** argv) {
    if (argc != 2) return invalid_usage();

    char line_buf[MAX_LENGTH];

    FILE *fptr;
    const char* filename = argv[1];

    fptr = fopen(filename, "r");
    if (!fptr) return invalid_file();

    bool in_block_comment = false;
    int NUM_LINES = 0;
    int NUM_COMMENTS = 0;
    int NUM_BLANK = 0;

    /* Grab each line from file */
    while(fgets(line_buf, MAX_LENGTH, fptr)) {
        char *it = line_buf;

        /* Skip leading space */
        while (*it == ' ' || *it == '\t') it++;
    
        /* Nothing in line */
        if (*it == '\n') {
            NUM_BLANK++;
            continue;
        }

        /* Looking for a block comment terminator*/
        if (in_block_comment) {
            NUM_COMMENTS++;
            char* end_comment = strstr(it, "*/");
            if (end_comment) in_block_comment = false;
            continue;
        }

        /* Simple comment */
        if (it[0] == '/' && it[1] == '/') {
            NUM_COMMENTS++;
            continue;
        }

        /* Start of block comment */
        if (it[0] == '/' && it[1] == '*') {
            NUM_COMMENTS++;
            char* end_comment = strstr(it, "*/");
            /* If block comment is multi-line, set flag*/
            if (!end_comment) in_block_comment = true;
            continue;
        }

        /* General case is a line of code */
        NUM_LINES++;
    }

    printf("Code: %d\nComments: %d\nBlank: %d\nTotal: %d\n", NUM_LINES, NUM_COMMENTS, NUM_BLANK, NUM_BLANK+NUM_COMMENTS+NUM_LINES);
    return 0;
}
