# My-copy-command-on-Linux
This is a simulation to "cp" command on Linux just for discovering the magic of C programming language.

After compile the .c source code and name the executable, you can use the name as "cp" command on your Linux computer with the shell.

The program has a function as to copy a file to another file with a new name, or files into another folder. Note that if you  want to copy files into another folder, you need to specify the folder with full relative pathname which contains at least one '/' sign, as pathname "../" instead of just "..".

Surely you can use the "stat" function (function as: int stat(const char *pathname, struct stat *statbuf);) to tell whether the last pathname passed from command line is a folder  by a member variable in a structure pointed to by the variable "statbuf". In that case, you may have to add the '/' sign to a proper position of the destination filename. All the complement and update and fun is on your own.
