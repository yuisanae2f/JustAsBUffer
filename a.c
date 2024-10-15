#include <time.h>
#include <stdio.h>
#include <stdlib.h>

FILE* file;

#define __printf(...) fprintf(file, __VA_ARGS__)
#define __test(n) time = loop(n); __printf("Loop: %d, elapsed: %d, e: %d\n", n, time, time / n);

clock_t loop(int a) {
    clock_t start = clock(), end;

    for(int i = 0; i < a; i++) {
        system("ls -l /");
    }

    end = clock();

    return end - start;
}

int main() {
    file = fopen("Test.txt", "w");
    clock_t start, end;
    
    int time;

    __test(1);
    __test(100);
    __test(1000);
    __test(10000);
    __test(100000);

    fclose(file);
    return 0;
}