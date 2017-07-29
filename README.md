************ Shell made by Nikhil Gogate************/
                Features of Shell:
-> It can run any command which can be run on Bash.
-> It takes directory where executable is located as its home directory.
-> echo,pwd,cd are inbuilt command they are not as complex as they are in Bash.
-> It can take multiple command separated by ";" (neglect double inverted comma).
->redirection and piping is allowed.
->ctrl+d closes terminal.
->new inbuilt command like jobs,kjob,etc are added.
                    Parts:
main.c ----> It is main file containing main loop of Shell.It also contains tokenization function.
in_built.c ---> It contain functions for inbuilt commands(echo,pwd and cd).
relhome.c ---> It contains function for converting absolute path to relative path(considering location of executable as home directory).
makefile ---> Standard makefile

Compile:
make

Run:
./Shell

