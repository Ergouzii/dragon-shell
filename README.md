## How to use?

```
>> make
>> ./dragonshell

    **the program will show here**

```

## Design choices

The main program is started with a `while(1)` loop. Inside the loop, there are some simple error handlings. The input is detected by using `tokenized`, then go to each different functions according to user's input command.

## System calls and example test cases for each feature implementation

`cd`: `chdir`

```
cd ..
cd DragonShell
cd non_existing_dir
cd a b c
cd ../..
```

`pwd`: `getcwd`

```
cd ..
pwd
```

`$PATH`: none

```
$PATH
```

`a2path`: none

```
a2path $PATH:/a/
a2path /a/
$PATH >> /a/
```

`exit`: `kill`, `_exit`

```
exit
```

run external program: `execve`, `fork`, `waitpid`, `dup2`, `close`, `open`

```
ls
ls dragonshell.c
touch test.txt
touch
/usr/bin/touch test.txt
```

output redirection: `close`, `write`, `open`

```
ls > a.txt
ls -l > a.txt
pwd > a.txt
aaa > a.txt
```

piping: `pipe`, `execve`, `fork`, `waitpid`, `dup2`, `waitpid`, `close`

```
find ./ | sort
ls -l | sort
ls | sort
```

run multiple cmds: none
```
ls ; ls -l ; ls -l | sort
ls > a.txt ; find ./ | sort
sleep & ; ls
```

signals: `kill`, `signal`

```
sleep
^C

sleep
^Z

ps
```

putting jobs in background: `waitpid`, `open`, `dup2`, `close`

```
sleep &
ps
```

## References

system calls: http://man7.org/linux/man-pages/man2/syscalls.2.html

detecting `^D`:
https://stackoverflow.com/questions/29191939/how-do-you-detect-ctrld-in-c?rq=1

signals: https://stackoverflow.com/questions/26747590/sigint-and-sigquit

http://ideone.com/4zs4u3

clear an array: https://stackoverflow.com/questions/1134103/clearing-a-small-integer-array-memset-vs-for-loop

run at background: https://stackoverflow.com/questions/14548367/using-waitpid-to-run-process-in-background

I/O syscalls: https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/

free: https://www.tutorialspoint.com/c_standard_library/c_function_free.htm

prevent zombie process: https://www.geeksforgeeks.org/zombie-processes-prevention/