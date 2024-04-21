# ConwaysGameOfLife

## Introduction

Welcome to my personal project. I coded Conway's Game Of Life. This "game" is incredible if we compare its complexity and the outcome we are able to create. Indeed, the rules are so simple you may wonder what is the goal of such an app. However, Nicolas Loizeau created a whole computer all logic gates. For more information I suggest to visit <a href="https://www.nicolasloizeau.com/gol-computer">this website</a>.

## Rules

This file's goal is not to explain the whole game. If you don't know it, you should visit the <a href="https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life">wiki</a>.

## Compilation and execution

As I chose to use the C language for my app, you can compile with gcc 
````bash
gcc ConwaysGameOfLife.c -o ConwaysGameOfLife
````

### Random generation

You can launch the program and observe what happens in a grid where random alive cells have been placed. This mode is useful to understand how the game works but you are not likely to observe interesting phenomenon as they are wery rare. You can execute it with this command :
````bash
./ConwaysGameOfLife
````

### Generation from file

You can also launch the program with an input file where alive cells have been place to observe structures. Some of these structures are stored in patterns fodler. To execute it, use the command : 
````bash
./ConwaysGameOfLife path/file.txt rate
````
I recommand some rate for the give files : 
````bash
./ConwaysGameOfLife patterns/oscilator.txt 10
````
````bash
./ConwaysGameOfLife patterns/glider.txt 1
````
````bash
./ConwaysGameOfLife patterns/gliderGun.txt 1
````
````bash
./ConwaysGameOfLife patterns/gliderShuttle.txt 1
````
