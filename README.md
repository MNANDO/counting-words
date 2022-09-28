# Word Counter Program

## Rules and Definitions
A word is defined as one or more non whitespace characters separated by whitespace characters. 
A name is defined as a word that starts with either a letter or an "_" character and is followed by 0 or more letters, "_" characters, "@" characters, or digits.
A integer is defined as aword that starts with a ditgit or a "+" or "-" character and is followed by 0 or more digits. 
The program prints a count of names or integers, or both.

## Algorithm
This program utilizes a char pointer to iterate through a string of characters. The value of this pointer is dereferenced and used to categorize the type of word that is being parsed. 

## Usage

Compile the program using a C++ compiler.
The program takes two command line arguments
* The first argument is the name of the file
* The second argument is a flag (optional)
  * -all: prints the number of names and integers
  * -ints: prints the number of integers
  * -names: prints the number of names

## License
[MIT](https://choosealicense.com/licenses/mit/)
