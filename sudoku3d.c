#include <stdio.h>
#include <stdlib.h>

// Declare printSudoku function
void printSudoku(int ***);
// Declare solveSudoku function
int solveSudoku(int ***);

//Helper functions. You can define any functions that can help your solve the problem

/*
The main program reads a text file containing the block values of the Sudoku grid.
It then saves each 3x3 block into a 2D array. The Sudoku grid is composed of 9 3x3 blocks.
DO NOT MODIFY THE MAIN FUNTION!!!
*/
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr;
    int ***blocks = (int ***)malloc(9 * sizeof(int **));

    // Open file for reading
    fptr = fopen(argv[1], "r");
    if (fptr == NULL)
    {
        printf("Cannot Open File!\n");
        return 0;
    }

    // Read 9x9 blocks into 2D arrays

    //i here iterates through all the blocks
    for (i = 0; i < 9; i++)
    {
        *(blocks + i) = (int **)malloc(3 * sizeof(int *));
        printf("Reading numbers in block %d... \n", i + 1);
        for (j = 0; j < 3; j++)
        {
            *(*(blocks + i) + j) = (int *)malloc(3 * sizeof(int));
            fscanf(fptr, "%d %d %d", *(*(blocks + i) + j), *(*(blocks + i) + j) + 1, *(*(blocks + i) + j) + 2);
            //print column:               1,                   2,                  and 3 of the ith block
            printf("%d %d %d\n", *(*(*(blocks + i) + j)), *(*(*(blocks + i) + j) + 1), *(*(*(blocks + i) + j) + 2));

            // printf("%d %d \n", *(*(*(blocks + i) + j)), *(*(*(blocks + i) + j) + 1));
        }
    }

    // Print out original Sudoku grid
    printf("Printing Sudoku before being solved:\n");
    printSudoku(blocks);

    // Call solveSudoku and print out result
    printf("\nSolving Sudoku...\n\n");
    solveSudoku(blocks);
    // if (solveSudoku(blocks))
    // {
    //     printf("Sudoku solved!\n");
    //     printSudoku(blocks);
    // }
    // else
    //     printf("This Sudoku cannot be solved!\n");

    // return 0;
}

void printSudoku(int ***arr)
{
    // This function will print out the complete Sudoku grid (arr). It must produce the output in the SAME format as the samples in the instructions.

    // Your implementation here

    int i, j;

    for (i = 0; i < 9; i++)
    {
        printf(" | ");
        for (j = 0; j < 3; j++)
        {
            if (j != 2)
            {
                printf("%d %d %d | ", *(*(*(arr + i) + j)), *(*(*(arr + i) + j) + 1), *(*(*(arr + i) + j) + 2));
            }
            else
            {
                printf("%d %d %d ", *(*(*(arr + i) + j)), *(*(*(arr + i) + j) + 1), *(*(*(arr + i) + j) + 2));
            };
        }
        printf("|\n");
        if (i == 2 || i == 5)
        {
            printf(" - - - -  - - -  - - - - -\n");
        }
    }
}

int solveSudoku(int ***blocks)
{
    // This is the function to solve the Sudoku (blocks). Feel free to use any helper functions.
    // YOU MUST NOT USE ANY ARRAY NOTATION ([])!

    //Your implementation here

    //-traverse the board row by row, and place 1-9 in each cell until the row is complete
    // -advance to the next row, set the column back to zero, set column zero all the way up to the length -1

    //our choice: place 1-9 in an empty cell
    //our constraints:  placement cannot break boards

    /******************************Properties of Sudoku******************************/
    //current number cannot be exist in the row or column                            /
    //current number cannot exit in the block                                        /
    /********************************************************************************/

    //REMEMBER FOR THE ITERATIONS: I IS THE SUB MATRIX YOU ARE IN,  J IS THE COLUMN YOU RESIDE WITHIN THE SUB MATRIX

    int i, j;
    int count = 0;
    int countj = 0;
    // int ***colPointer;
    // int **rowPointer;

    //*(blocks + i) iterates us through the columns
    //*(*(blocks + i) + j) iterates us through the rows


    //I IS THE iTTH SUBMATRIX! (I/9)
    for (i = 0; i < 9; i++)
    {
        *(blocks + i) = (int **)malloc(3 * sizeof(int *));
        //J IS THE COLUMN WITHIN THE SUBMATRIX! (J/3)
        for (j = 0; j < 3; j++)
        {
            *(*(blocks + i) + j) = (int *)malloc(3 * sizeof(int));
            ///////First Feature: iterate through the columns and find a zero
            if (*(*(*(blocks + i) + j)) == 0)
            {
                count++;

                printf("the %d zero we have found!\n", count);

                // printf("Found a zero at %d\n", *(*(*(blocks + i)+j)));
            }
            else
            {
                countj++;

                printf("the %d n0nzero we have found!\n", countj);
            }

            // if (i = 8)
            // {
            //     if (j = 2)
            //     {
            //         return 0;
            //     }
            //     // *(*(*(blocks + i) + j)) = 0;
            //     *(*(*(blocks + i) + j)) = 0;
            //     // *(blocks + i) =  *(blocks + i) + 1;
            //     *(blocks + i) = *(blocks + i) + 1;
            // }
        }
    }
}