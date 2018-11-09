/**
 * @file life.c
 * @brief holds the functions used to implement conways game of life
 * @detail holds functions called by main in gl.c used to play game of life
 * 
 *
 * @author Joseph Ladino
 * @date Dec 1 2016
 * @bug none
 * @todo none
 **/

#include "life.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * initializes a matrix using calloc to set all the values to 0
 * @param rows, the number of rows in matrix
 * @param cols, number of columns in matrix
 * @return a pointer to the unsigned char matrix
 **/
unsigned char **init_matrix(int rows, int cols)
{
        int i;
        int j;
        unsigned char **a = NULL;

        a = calloc(rows, sizeof(unsigned char*));
        //a = malloc(rows*sizeof(unsigned char*));
        if (!a) {
                return NULL; /*error check*/
        }
        for(i=0; i<rows; i++) {
                a[i] = calloc(cols, sizeof(unsigned char)); /*allocates the second dimension in array*/
                //a[i] = malloc(cols*sizeof(unsigned char));
                if (!a[i]) {
                        for (j=0; j<i; j++) {
                                free(a[j]); /*error check that prevents memory leaks*/
                        }
                        free(a);
                        return NULL;
                }
        }
        return a;
}

/**
 * reads a file of cordinates into the program and sets the cordinates as true
 * @param pattern, pointer to an opened .lif file with the cordinates
 * @param array, pointer to the pointer to the array
 * @param rows, number of rows
 * @param cols, number of columns
 **/
void read_file(FILE *pattern, unsigned char **array, int x_start, int y_start)
{
        int i, j;
        char buf[1024];
        /*set points for the center of matrix, a [0,0] if you will.*/
        int orgy = y_start; /*Yes this is an orgy. Too lazy to change it after I noticed it*/
        int orgx = x_start;
        if (!pattern) {
                printf("file is not found\n");
                exit(1);
        }
        fgets(buf, 1024, pattern); /*gets rid of the first line of trash in each .lif file*/
                
        while(fgets(buf, 1024, pattern)) { /*gets all of the cordinates and turns them on in array*/
                sscanf(buf, "%d %d\n", &i, &j);
                array[(i+orgx)][(j+orgy)] = 1;
                printf("array[%d][%d] = %d\n", (i+orgx), (j+orgy), array[orgx+i][orgy+j]);
                       
        }
        fclose(pattern); /*like a good boy clean up*/

}

/**
 * takes sum of cells surrounding current and determines life in next generation based on klein edges.
 * @param **array array that has the current generation
 * @param array2 array that temp hols the next generation
 * @param rows number of rows in arrays
 * @param cols number of columns in arrays
 * @return void
 **/
void klein(unsigned char** array, unsigned char** array2, int rows, int cols)
{
        int sum = 0;
        int i, j;
        


        for (j=0; j<rows; j++) {
                for (i=0; i<cols; i++) {
                        array2[j][i] = array[j][i];
                }
        }
        for (j=0; j<rows; j++) {
                for (i=0; i<cols; i++) {
                        sum = get_klein(rows, cols, i, j-1, array) + 
                              get_klein(rows, cols, i-1, j-1, array)+ 
                              get_klein(rows, cols, i-1, j, array)+ 
                              get_klein(rows, cols, i-1, j+1, array)+ 
                              get_klein(rows, cols, i, j+1, array)+  
                              get_klein(rows, cols, i+1, j+1, array)+ 
                              get_klein(rows, cols, i+1, j, array)+ 
                              get_klein(rows, cols, i+1, j-1, array);
                        if(sum < 2 || sum > 3) {
                                array2[j][i] = 0;
                        }
                        else if (sum == 3 && array[j][i] == 0) {
                                array2[j][i] = 1;
                        }
                }
        }
        for (j=0; j<rows; j++) {
                for (i=0; i<cols; i++) {
                        array[j][i] = array2[j][i];
                }
        }
}

/**
 * finds cells surrounding current cell
 * @param rows number of rows in array
 * @param cols number of columns in array
 * @param i index from iteration through array
 * @param j index from iteration through array
 * @param **array the matrix being searched through
 * @return value stored at the indicated position in matrix
 **/
unsigned char get_klein(int rows, int cols, int i, int j, unsigned char** array)
{
        if ((j>rows-1)||(j<0)){
                if ((cols+i)%cols==0) {
                        return array[(rows+j)%rows][(cols+i)%cols];
                }
                else {
                        return array[(rows+j)%rows][cols-((cols+i)%cols)];
                }
        }
        else{
                return array[(rows+j)%rows][(cols+i)%cols];
        }
}

/**
 *takes sum of the cells surrounding current cell to determin next generation of life using torus edge
 *@param **array the matrix holding the current generation
 *@param **array2 the matrix that will hold the next generation temporarily.
 *@param rows number of rows in array
 *@param cols number of columns in array
 **/
void torus(unsigned char** array, unsigned char** array2, int rows, int cols)
{
        int sum = 0;
        int i, j;
        


        for (j=0; j<rows; j++) {
                for (i=0; i<cols; i++) {
                        array2[j][i] = array[j][i];
                }
        }
        for (j=0; j<rows; j++) {
                for (i=0; i<cols; i++) {
                        sum = get_tor(rows, cols, i, j-1, array) + 
                              get_tor(rows, cols, i-1, j-1, array)+ 
                              get_tor(rows, cols, i-1, j, array)+ 
                              get_tor(rows, cols, i-1, j+1, array)+ 
                              get_tor(rows, cols, i, j+1, array)+  
                              get_tor(rows, cols, i+1, j+1, array)+ 
                              get_tor(rows, cols, i+1, j, array)+ 
                              get_tor(rows, cols, i+1, j-1, array);
                        if(sum < 2 || sum > 3) {
                                array2[j][i] = 0;
                        }
                        else if (sum == 3 && array[j][i] == 0) {
                                array2[j][i] = 1;
                        }
                }
        }
        for (j=0; j<rows; j++) {
                for (i=0; i<cols; i++) {
                        array[j][i] = array2[j][i];
                }
        }
}

/**
 * finds cells surrounding indexed cell using a torus
 * @param rows number of rows in array
 * @param cols number of columns in array
 * @param i index of matrix from torus calc
 * @param j index of matrix from torus calc
 * @param **array matrix containing current generation of life
 * @return value stored in cell at indexes
 **/
unsigned char get_tor(int rows, int cols, int i, int j, unsigned char** array)
{
        return array[(rows+j)%rows][(cols+i)%cols];
}

/**
 * determines the next generation with each cell beyond the edge considered dead
 * @param **array matrix with current generation of life
 * @param array2 matrix that will temp hold the next generation of life
 * @param rows number of rows in arrays
 * @param cols number of columns in arrays
 * @return void
 **/
void life(unsigned char **array, unsigned char **array2, int rows, int cols)//hedge
{
        int i;
        int j;
        int sum = 0;
        
        for (j=1; j<rows; j++) {
                for (i=1; i<cols; i++) {
                        array2[j][i] = array[j][i];
                }
        }
        
        for (j=1; j<rows-1; j++) {
                for (i=1; i<cols-1; i++) {
                        sum = array[j-1][i] + 
                              array[j-1][i-1] + 
                              array[j][i-1] + 
                              array[j+1][i-1] + 
                              array[j+1][i] + 
                              array[j+1][i+1] + 
                              array[j][i+1] + 
                              array[j-1][i+1];
                        if(sum < 2 || sum > 3) {
                                array2[j][i] = 0;
                        }
                        else if (sum == 3 && array[j][i] == 0) {
                                array2[j][i] = 1;
                        }
                }
        }
        for (j=1; j<rows; j++) {
                for (i=1; i<cols; i++) {
                        array[j][i] = array2[j][i];
                }
        }


}

/**
 * frees the array passed in
 * @param **matrix the matrix to be freed
 * @param rows number of rows in array
 * @param cols number of columns in array
 * @return void
 **/
void kill_with_fire(unsigned char** matrix, int rows, int cols)
{
        int j;

        for (j=0; j<rows; j++){
                free(matrix[j]);
        }
        free(matrix);
}

