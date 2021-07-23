// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isSafe(int grid[N][N], int row, int col, int num){
        for(int i=0; i<9; i++){
            if(grid[i][col] == num){
                return false;
            }
            if(grid[row][i] == num){
                return false;
            }
        }

        int r=row-row%3;
        int c=col-col%3;
     
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(grid[i+r][j+c] == num){
                    return false;
                }
            }
        }
        return true;
    }
    
    // bool solve(int grid[N][N], int row, int col){
    //     if(row == N-1 && col == N){
    //         return true;
    //     }
        
    //     if(col == N){
    //         row++;
    //         col = 0;
    //     }
        
    //     if(grid[row][col] > 0){
    //         return solve(grid, row, col+1);
    //     }
        
    //     for(int num = 1; num<N+1; num++){
    //         if(isSafe(grid, row, col, num)){
    //             grid[row][col] = num;
            
    //             if(solve(grid, row, col+1)){
    //                 return true;
    //             }
    //         }
    //         grid[row][col] = 0;
    //     }
    //     return false;
    // }
    
    bool findEmpty(int grid[N][N], int &row, int &col){
        for(row=0; row<N; row++){
            for(col=0; col<N; col++){
                if(grid[row][col] == 0){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        int row, col;
        if(!findEmpty(grid, row, col)){
            return true;
        }
        
        for(int i=1; i<10; i++){
            if(isSafe(grid, row, col, i)){
                grid[row][col] = i;
                if(SolveSudoku(grid)){
                    return true;
                }
                grid[row][col] = 0;
            }
        }
        
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends