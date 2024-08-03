#include "cli_utils.h"
#include <stdio.h>
#include <string.h>

/*
 * Get input from the user.
 * If the user enters an empty string, the default value is returned.
 * Make sure to provide a buffer with enough space to store the input.
 */
char *get_input(char *default_value, char *buf) {
    scanf("%s", buf);

    if (strcmp(buf, "")) {
        return default_value;
    }

    return buf;
}

char *format_color(char *color, char *text) {
    
}

