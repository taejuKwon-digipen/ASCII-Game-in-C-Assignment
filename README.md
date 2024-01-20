# **ASCII Game in C Assignment**

## 1. Name, Project Name, Course Name, Term

- Name: Taeju Kwon, Geonhwi Sim
- Project Name: ASCII Game in C
- Course Name: CS170
- Term: 2021 Spring

## 2. How to build with make
-bash-> make -> run
## 3. How to build with CMake

## 4. Game Introduction
-It is a game in which players adjust the position of the bomb as they move and enter the home.	
## 5. How to interact with the game
 -Players can move bombs as they move. The number of moves the player makes is saved and updated in real time.
## 6. The thing We're proud of about the project
 -We did it!
## 7. The thing incomplete about the project
 -Make many levels.
## 8. File name / Line numbers for all code related requirements
 -Have custom command line arguments: int main(main.c)
 -Make good use of arrays: void setting(main.c) ->line.123
 -Use Bitwise operations to create a some kind of configuration variable where you extract values. (Combine bit flags of varying powers of 2): bitwise.c, bitwise.h
 -When applicable, use bitwise operations to replace Arithmetic Operations (You may not use your ALU code from CS100): bitwise.c, bitwise.h
 -Make good use of struct: sturct.h
 -Make good use of malloc()/free() (Only use for things that are truly dynamic in nature): void reset(main.c), int main(main.c)
 -Make good use of typedef to simplify your types (Make complex declarations easier, use with enum, struct): struct.h
 -Make good use of #define for number literals (No Magic Numbers): struct.h
 -Make good use of C File IO (Could create player save game file(s) or game configuration file(s)): int main()(main.c)
 -Make good use of Function Pointers (Write a function that takes in a function pointer, like qsort()): int main()(main.c)
