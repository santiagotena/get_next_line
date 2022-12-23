# get_next_line
 
<p align="center">
<img src="https://github.com/santiagotena/assets/blob/master/logos/42%20logo.jpeg?raw=true" alt="42 Wolfsburg Logo" width="150" height="150">
</p>
 
For this project of 42 Wolfsburg, we are meant to create a function that is capable of reading from a text file. Said file will be pointed to by a file descriptor within the function and will internally read from the text one line a time.
 
Important concepts to understand for this project were file descriptor and static variables.
 
# Usage
 
Compilation:
 
`` 
gcc main.c get_next_line.c get_next_line_utils.c
``
 
Execution:
 
``
./a.out [file]
``

The expected output with this instructions is the entire contents of the given file.
