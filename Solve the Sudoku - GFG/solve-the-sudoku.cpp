//{ Driver Code Starts
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
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return samadhaan(grid);
    }
    
    bool samadhaan(int grid[N][N]) {
        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < N ; j++) {
                if(grid[i][j] == 0) {
                    for(int digit = 1 ; digit <= 9 ; digit++) {
                        if(isValid(grid, i, j, digit)) {
                            grid[i][j] = digit;
                            if(samadhaan(grid) == true) {
                                return true;
                            }
                            else {
                                grid[i][j] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    
    bool isValid(int grid[N][N], int row, int col, int d) {
        for(int i = 0 ; i < 9 ; i++) {
            if(grid[row][i] == d) return false;
            if(grid[i][col] == d) return false;
            
            // In that specific grid
            if(grid[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == d) 
            return false;
        }
        return true;
    }
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here
        if(SolveSudoku(grid) == true) {
            for(int i = 0 ; i < N ; i++) {
                for(int j = 0 ; j < N ; j++) {
                    cout << grid[i][j] << " ";
                }
            }
        }
        
    }
};

//{ Driver Code Starts.

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
}
// } Driver Code Ends