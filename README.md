## Design choices

The main program is started with a `while(1)` loop. Inside the loop, there are some simple error handlings. The input is detected by using `tokenized`, then go to each different functions according to user's input command.

## System calls used in each feature implementation

`cd`: `chdir`

`pwd`: `getcwd`

`$PATH`: none

`a2path`: none

`exit`: `kill`, `_exit`

run external program: `execve`, `fork`, `wait`, `dup2`, `close`, `open`

output redirection: `close`, `write`, `open`

piping: `pipe`, `execve`, `fork`, `wait`, `dup2`, `waitpid`, `close`

run multiple cmds: none

## References

detecting `^D`:
https://stackoverflow.com/questions/29191939/how-do-you-detect-ctrld-in-c?rq=1

signals: https://stackoverflow.com/questions/26747590/sigint-and-sigquit

http://ideone.com/4zs4u3

clear an array: https://stackoverflow.com/questions/1134103/clearing-a-small-integer-array-memset-vs-for-loop

