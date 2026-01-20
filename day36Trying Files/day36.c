#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fptr;
    char line[100];

    fptr = fopen("./file.txt", "r");  // relative path

    if (fptr == NULL) {
        printf("The file is not opened.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fptr) != NULL) {
        printf("%s", line);
    }

    fclose(fptr);
    return 0;
}
