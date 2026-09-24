#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <megabytes>\n", argv[0]);
        return 1;
    }

    int mb = atoi(argv[1]);

    long bytes = (long) mb * 1024 * 1024;

    char *array = malloc(bytes);

    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("PID: %d\n", getpid());
    printf("Using %d MB of memory\n", mb);

    while (1) {
        for (long i = 0; i < bytes; i++) {
            array[i] = 1;
        }
    }

    free(array);

    return 0;
}
