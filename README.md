# ConwaysGameOfLife

## Introduction

Welcome to my personal project. I coded Conway's Game Of Life. This "game" is incredible if we compare its complexity and the outcome we are able to create. Indeed, the rules are so simple you may wonder what is the goal of such an app. However, Nicolas Loizeau created a whole computer with all logic gates. For more information I suggest to visit <a href="https://www.nicolasloizeau.com/gol-computer">this website</a>.

Conway's game of life is just a grid, composed of cells. A cells can be alive or dead and in this project, alive cells are represented with a 'O' and dead ones with a '.'. Once we have our grid with our cells, the next generation must be calculated. The whole game is based on how the cells evolve through generations. 

## Rules

To calculate the next generation from a grid, a few simples rules must be known : 
- a dead cell with exactly 3 alive neighboors becomes alive a the next generation : life in good proportions gives life (reproduction).
- an alive cell stays alive if 2 or 3 neighboors are alive. Having less than 2 (underpopulation) or more than 3 (overpopulation)
That's all, we have our grid, our cells and we know how to create the next generation. All we have to do is to observe ! 
For more information, you can visite the <a href="https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life">wiki</a>.

## Compilation and execution

As I chose to use the C language for my app, you can compile with gcc 
````bash
gcc ConwaysGameOfLife.c -o ConwaysGameOfLife
````

### Random generation

You can launch the program and observe what happens in a grid where random alive cells have been placed, this is called "a soup". This mode is useful to understand how the game works but you are not likely to observe interesting phenomenon as they are very rare. You can execute it with this command :
````bash
./ConwaysGameOfLife
````

### Generation from file

You can also launch the program with an input file where alive cells have been place to observe structures. Some of these structures are stored in patterns fodler. To execute it, use the command : 
````bash
./ConwaysGameOfLife path/file.txt rate
````
I recommand some rate for the give files : 
- this first structure is called "oscilator". It comes back to the first pattern periodically, for this one the period is three but numerous structures have periods going beyong hundreds of generation :
````bash
./ConwaysGameOfLife patterns/oscilator.txt 10
````

- this basic structure is one of the most important ones in this game. The group of cells flies accross the grid and doesn't stop. This pattern if used is all generators in order to create huge spaceships :
![image](https://github.com/Maubin76/ConwaysGameOfLife/assets/113935961/fa24e4db-1094-4233-a83d-86436ba49c79)
````bash
./ConwaysGameOfLife patterns/glider.txt 1
````

- in order to exploit the glider, we can generate it. A generator is called "gun" and many types exist in order to have a different generation rate :
![image](https://github.com/Maubin76/ConwaysGameOfLife/assets/113935961/c19dacac-e77a-4c6a-bbee-bd8ba04b9abe)
````bash
./ConwaysGameOfLife patterns/gliderGun.txt 1
````

- this structure is another oscilator and in the middle, a glider goes back and forth : 
````bash
./ConwaysGameOfLife patterns/gliderShuttle.txt 1
````

You can visit the <a href="https://conwaylife.com/wiki/Category:Patterns">wiki</a> to discover and copy new structures. You can even try to discover new one, the game has been created in the 1970s but new patterns are still discovered nowadays ! 
