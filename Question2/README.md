# Question 2 - Process Monitoring and Zombie Prevention

## Objective

The aim of this task is to create a parent and child process using `fork()`, monitor the child process, terminate it if it becomes unresponsive, and make sure that no zombie process is left behind.

## Approach

I used a C program where the parent creates a child process using `fork()`.

- The child process is made to run continuously to simulate an unresponsive process.
- The parent waits for a few seconds while monitoring the child.
- If the child does not finish, the parent sends `SIGTERM` using `kill()`.
- `waitpid()` is used to collect the terminated child process.
- This makes sure that the child does not remain as a zombie process.

## Result

The program was tested successfully. The child process was started and monitored by the parent.

The program showed that:

- The unresponsive child was terminated using `SIGTERM`.
- The child terminated with signal 15.
- The parent collected the child process using `waitpid()`.
- No zombie process was left after execution.

The process monitoring and cleanup worked as expected.
