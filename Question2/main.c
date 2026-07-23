#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (pid == 0)
    {
        printf("Child process started. PID: %d\n", getpid());
        fflush(stdout);

        /* Simulating a child that takes too long */
        while (1)
        {
            sleep(1);
        }
    }
    else
    {
        printf("Parent is monitoring child PID: %d\n", pid);

        sleep(3);

        printf("Child is not responding. Sending SIGTERM...\n");
        kill(pid, SIGTERM);

        /* Wait for child so that it does not become a zombie */
        waitpid(pid, &status, 0);

        if (WIFSIGNALED(status))
        {
            printf("Child terminated by signal: %d\n",
                   WTERMSIG(status));
        }
        else if (WIFEXITED(status))
        {
            printf("Child exited normally.\n");
        }

        printf("Child process collected successfully. No zombie process.\n");
    }

    return 0;
}
