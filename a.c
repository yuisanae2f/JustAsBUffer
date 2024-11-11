#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <wait.h>
#include <time.h>

/* Spawn a child process running a new program. PROGRAM is the name of the program to run; the path will be searched for this program. ARG_LIST is a NULL-terminated list of character strings to be passed as the program's argument list. Returns the process ID of the spawned process. */
int spawn(const char* program, char** const arg_list)
{ 
    pid_t child_pid;

    /* Duplicate this process. */ 
    child_pid = fork();
    if (child_pid != 0)
    /* This is the parent process. */
    return child_pid;

    else {
        /* Now execute PROGRAM, searching for it in the path. */
        execvp(program, arg_list);

        /* The execvp function returns only if an error occurs. */
        perror("an error occurred in execvp\n");
        abort();
    }
}

int main()
{
    // To separate the time measured code (for convenient)
    FILE* _ = fopen("_a", "w");

    clock_t 
        global_time = clock(),
        global_time_end,
        loc_time = clock(),
        loc_time_end,
        loc_time_sum = 0;

    /* The argument list to pass to the "Is" command. */ 
    char* arg_list[] = {
        "ls", /* argv[0], the name of the program. */
        "-l",
        "/",
        NULL /* The argument list must end with a NULL. */
    };

    for(int i = 0; i < 5; i++) {
        loc_time = clock();
        /* Spawn a child process running the "Is" command. Ignore the
        returned child process ID. */ 
        spawn("ls", arg_list);

        wait(0); // wait until child process die

        loc_time_end = clock();
        printf("loc time %d, %d\n", i, loc_time_end - loc_time);
        fprintf(_, "loc time %d, %d\n", i, loc_time_end - loc_time);
        loc_time_sum += loc_time_end - loc_time;
    }

    global_time_end = clock();
    printf("done with main program, elapsed global: %d\n", global_time_end - global_time);
    fprintf(_, "done with main program, elapsed global: %d\n", global_time_end - global_time);

    printf("local time sum: %d\n", loc_time_sum);
    fprintf(_, "local time sum: %d\n", loc_time_sum);
    
    fclose(_); // close it
    return 0;
}