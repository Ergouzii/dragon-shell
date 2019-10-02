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



