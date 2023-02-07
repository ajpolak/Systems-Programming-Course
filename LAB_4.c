/*
Name: Austin Polak, ajpolak@purdue.edu
TA: Zahra Ghorrati
Lab time: Thursday at 7:30am

Description: 
This program is designed to find the best path to complete the maze.
The program prints a maze matrix that the user will only be able to access the 
portions of the maze that are not blocked by obstacles. Representation of 
postions: Start 'S' blocked spot '#'  open spot is '.'  Finish/goal  'G' 
*/

#include <stdio.h>
#include <stdlib.h>

void MazeGo(char simple_maze[6][6], int a, int b);

int main()
{
#define ROW 6
#define COLUMN 6

    int a = 0;
    int b = 0;
    int i;
    int ii;

    char simple_maze[ROW][COLUMN] = {          //define the maze
        'S', '#', '#', '#', '#', '#',
        '.', '.', '.', '.', '.', '#',
        '#', '.', '#', '#', '#', '#',
        '#', '.', '#', '#', '#', '#',
        '.', '.', '.', '#', '.', 'G',
        '#', '#', '.', '.', '.', '#'
        };

    printf("\nThe original maze is : ");       //print maze
    
    for (i = 0; i < ROW; i++)
        {
            printf("\n");
            for (ii = 0; ii < COLUMN; ii++)
            {
                printf("%c", simple_maze[i][ii]);
            }
        }

    MazeGo(simple_maze, a, b);	               //path analyzing by calling function
	printf("\nThe solution path is :");

	for (i = 0; i < ROW; i++)
	    {
		    printf("\n");
		    for (ii = 0; ii < COLUMN; ii++)
		    {
			printf("%c", simple_maze[i][ii]);
		    }
	    }

        printf("\n");
    }

    void MazeGo(char simple_maze[6][6], int a, int b) //find the ideal route
    {
        if (simple_maze[a][b] == 'G')                 //loop through the directions you can head through the maze
            exit(0);
        else{
                simple_maze[a][b] = '+';

            if (simple_maze[a + 1][b] == '.' )        //head south one step
            {
                a++;
                MazeGo(simple_maze, a, b);
            }
            else if (simple_maze[a - 1][b] == '.')    //head north one step
            {
                a--;
                MazeGo(simple_maze, a, b);
            }
            else if (simple_maze[a][b + 1] == '.' )   //head east one step
            {
                b++;
                MazeGo(simple_maze, a, b);
            }
            else if (simple_maze[a][b - 1] == '.' )   //head west one step
            {
                b--;
                MazeGo(simple_maze, a, b);
        }
    }

    simple_maze[a][b] = '+';
}