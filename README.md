# Roman

A pair of programs that convert decimal to roman and roman to decimal.

## Build

Simply run `make` to build the programs. You may test the programs by running
`make test`. If the test succeeds nothing will be printed to the terminal and
the exit code will be 0.

## Run

To convert numbers to roman, run `bin/to_roman` from the top level directory of
the project.

The program will then proceed to read input from the terminal. You can quit by
hitting `Ctrl-D` or `Ctrl-C`.

In the examples presented next the `>` character denotes input.

`to_roman` example session

```
> 10
X
> 26
XXVI
> 2521
MMDXXI
```

`from_roman` example session

```
> X
10
> XXVI
26
> MMDXXI
2521
``` 

## Author
André Couto Gimael
