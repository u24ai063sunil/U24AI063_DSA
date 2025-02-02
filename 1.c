/* Write a C program to multiply two matrices using dynamic memory allocation. 
Each two-dimensional array should be processed as array of pointers to a set of 1-
dimensional integer arrays. Read, access and display the matrix elements using 
pointers instead of subscript notation. Use three functions i) To read input matrix ii) To 
compute the product and iii) To display the resultant matrix.
*/
# include <stdio.h
# include <stdlib.h>
//Function to multiply two matrices
int** multiply(int **a, int **b, int **c, int r1, int c1, int r2, int c2)
{
     int i, j, k;
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
             *(*(c + i) + j) = 0;
             for (k = 0; k < c1; k++)
             {
                   *(*(c + i) + j) += (*(*(a + i) + k)) * (*(*(b + k) + j));
             }
         }
     }
     return c;
}
//Function to display matrix
void display(int **a, int r, int c)
{
     int i, j;
     printf("The resultant matrix is: \n");
     for (i = 0; i < r; i++)
     {
         for (j = 0; j < c; j++)
        {
           printf("%d ", *(*(a + i) + j));
        }
        printf("\n");
     }
}
//Function to allocate memory
int** memory_allocation(int r, int c)
{
     int **a = (int **)malloc(r * sizeof(int *));
     for (int i = 0; i < r; i++)
     {
          a[i] = (int *)malloc(c * sizeof(int));
     }
      return a;
}
//Function to read matrix
int** read(int **a, int r, int c)
{ 
     int i, j;
     printf("Enter the elements of the matrix: \n");
     for (i = 0; i < r; i++)
     {
          for (j = 0; j < c; j++)
          {
            scanf("%d", (*(a + i) + j));
          }
     }
     printf("\n");
     return a;
}
//Main Driver Code 
int main()
{
     int r1, c1, r2, c2, i, j, k;
     printf("Enter the number of rows and columns of first matrix: ");
     scanf("%d %d", &r1, &c1);
     printf("Enter the number of rows and columns of second matrix: ");
     scanf("%d %d", &r2, &c2);
     if (c1 != r2)
     {
         printf("The number of columns of first matrix should be equal to the number of 
         rows of the second matrix.");
         exit(0);
      }
      int **a, **b, **c;
      a = memory_allocation(r1, c1);
      b = memory_allocation(r2, c2);
      c = memory_allocation(r1, c2);
      a = read(a, r1, c1);
      b = read(b, r2, c2);
      display(a, r1, c1);
      display(b, r2, c2);
      printf("The resultant matrix is: ");
      c = multiply(a, b, c, r1, c1, r2, c2)
      display(c,r1,c2); 
      return 0;
      }
