

Source
```c
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
```

Test.txt after running
```
Loop: 1, elapsed: 108, e: 108
Loop: 100, elapsed: 8202, e: 82
Loop: 1000, elapsed: 81237, e: 81
Loop: 10000, elapsed: 797114, e: 79
Loop: 100000, elapsed: 8107779, e: 81
```

Each Execution
```
total 2272
lrwxrwxrwx   1 root root       7 Nov 23  2023 bin -> usr/bin
drwxr-xr-x   2 root root    4096 Apr 18  2022 boot
drwxr-xr-x  16 root root    3600 Oct 15 00:26 dev
drwxr-xr-x  85 root root    4096 Oct 15 14:14 etc
drwxr-xr-x   3 root root    4096 Sep 10 16:13 home
-rwxrwxrwx   1 root root 2260248 Sep 27 09:55 init
lrwxrwxrwx   1 root root       7 Nov 23  2023 lib -> usr/lib
lrwxrwxrwx   1 root root       9 Nov 23  2023 lib32 -> usr/lib32
lrwxrwxrwx   1 root root       9 Nov 23  2023 lib64 -> usr/lib64
lrwxrwxrwx   1 root root      10 Nov 23  2023 libx32 -> usr/libx32
drwx------   2 root root   16384 Sep 10 16:13 lost+found
drwxr-xr-x   2 root root    4096 Nov 23  2023 media
drwxr-xr-x   5 root root    4096 Sep 10 16:13 mnt
drwxr-xr-x   3 root root    4096 Sep 10 17:17 opt
dr-xr-xr-x 283 root root       0 Oct 15 00:25 proc
drwx------   4 root root    4096 Sep 10 16:13 root
drwxr-xr-x  20 root root     620 Oct 15 14:13 run
lrwxrwxrwx   1 root root       8 Nov 23  2023 sbin -> usr/sbin
drwxr-xr-x  10 root root    4096 Sep 10 18:43 snap
drwxr-xr-x   2 root root    4096 Nov 23  2023 srv
dr-xr-xr-x  11 root root       0 Oct 15 00:25 sys
drwxrwxrwt  10 root root    4096 Oct 15 14:17 tmp
drwxr-xr-x  14 root root    4096 Nov 23  2023 usr
drwxr-xr-x  13 root root    4096 Nov 23  2023 var
```