#include <stdio.h> 
#include <stdlib.h> 
#define MAX_N 100 
int count = 0; 
void print_board(int n, int board[]) {   
    int i, j;     
    for (i = 0; i < n; i++) {   
        for (j = 0; j < n; j++) {
            if (board[i] == j)    
            printf("Q ");        
            else                
            printf(". ");   
            }         
            printf("\n");  
            }   
            printf("\n");   
            printf("Solution %d: ", count);  
            for (i = 0; i < n; i++) {  
                printf("%d ", board[i]);  
                }  
                printf("\n"); 
} 
void queens(int n, int row, int board[]) 
{    
    int i, j;     
    if (row == n) { 
        printf("Solution %d:\n", ++count);    
        print_board(n, board); 
        } 
        else 
        {     
            for (i = 0; i < n; i++) {      
                int ok = 1;    
                for (j = 0; j < row; j++) {      
                    if (board[j] == i || board[j] == i-row+j || board[j] == i+row-j) {   
                        ok = 0;              
                        break;            
                        }           
                        }       
                        if (ok) {    
                            board[row] = i;      
                            queens(n, row+1, board);     
                            }       
                            }   
                            } 
    
} 
 
int main() {  
    int n;   
    int board[MAX_N]; 
    printf("Enter the value of n: ");
    scanf("%d", &n);
    queens(n, 0, board); 
    printf("Total number of calls to queen procedure: %d\n", count); 
    return 0; 
    
}