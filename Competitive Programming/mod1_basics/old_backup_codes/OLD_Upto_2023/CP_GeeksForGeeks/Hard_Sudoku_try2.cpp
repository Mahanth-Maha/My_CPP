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
    void written(int grid[N][N],int i, int j,vector<vector<vector<int>>>& pos){
        for(int p = 0; p < 9 ;p++){
            pos[i][p][grid[i][j]-1] = 0;
            pos[p][j][grid[i][j]-1] = 0;
        }   
        for(int q = 0 ; q <3 ;q++){
            for(int w = 0 ; w <3 ;w++){
                pos[((i/3)*3) + q][((j/3)*3) + w][grid[i][j]-1] = 0;
            }
        }
        for(int p = 0; p < 9 ;p++){
            pos[i][j][p] = 0;
        }
    }
    
    void fill1(int grid[N][N],int i, int j, int k,vector<vector<vector<int>>>& pos){
        int si = 0,sj = 0, sij = 0;
        for(int p = 0; p < 9 ;p++){
            si += pos[i][p][k];
            sj += pos[p][j][k];
        }
        for(int q = 0 ; q <3 ;q++){
            for(int w = 0 ; w <3 ;w++){
                sij += pos[((i/3)*3) + q][((j/3)*3) + w][k];
            }
        }
        if(si == 1 || sj == 1 || sij == 1) {
            grid[i][j] = k+1;
            written(grid,i,j,pos);
        }
    }

    bool isSafe(int grid[N][N],int i, int j,int k){
        for(int p = 0; p < 9 ;p++)
            if( grid[i][p] == k) return false;
        for(int p = 0; p < 9 ;p++)
            if( grid[p][j] == k) return false;
        for(int q = 0 ; q <3 ;q++)
            for(int w = 0 ; w <3 ;w++)
                if( grid[((i/3)*3) + q][ ((j/3)*3) + w ] == k ) return false;
        return true;
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // bool res = true;
        // vector<vector<vector<int>>>pos (N, vector<vector<int>>(N,vector<int> (9,1)));
        // for(int i = 0 ; i < N ; i++){
        //     for(int j = 0 ; j < N ; j++){
        //         if(grid[i][j] != 0)
        //             written(grid,i,j,pos);
        //     }
        // }
        
        // for(int e = 0 ; e < N * N; e++){
        //     for(int i = 0 ; i < N ; i++){
        //         for(int j = 0 ; j < N ; j++){
        //             for(int k = 0 ; k < N ; k++){
        //                 if(grid[i][j] == 0 && pos[i][j][k]){
        //                     fill1(grid,i,j,k,pos);
        //                 }
        //             }
        //         }
        //     }
        // }
        // return res;

        for(int  p= 1 ; p <= 9 ; p++){
            for(int i = 0 ; i < N ; i++){
                for(int j = 0 ; j < N ; j++){
                    if(grid[i][j] == 0){
                        if(isSafe(grid,i,j,p)){
                            grid[i][j] = p;
                        }
                    }
                }
            }
        }
        printGrid(grid);
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                if(grid[i][j] == 0){
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                cout << grid[i][j] << " ";
            }
            // cout << endl;
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