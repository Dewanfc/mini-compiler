#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int temp_count = 1;
static int label_count = 1;

char* new_temp() {
    char* temp = (char*)malloc(16);
    sprintf(temp, "t%d", temp_count++);
    return temp;
}
