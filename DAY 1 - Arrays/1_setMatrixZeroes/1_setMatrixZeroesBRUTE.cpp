// BRUTE FORCE SOLUTION
// T.C -> O( N * M * (N+M) )
// S.C -> O(1)
/* 
    Assumption: All elements in the matrix are Non-Negative. 

    1. Traverse through the 2D Matrix,
    2. if the value 0 -> change all it row & column elements to -1
    3. Don't do the change where there is 0 already because this might affect other columns and rows.
    4. Now traverse matrix again, and if an element is -1 change them to 0, which will be the answer.

    // LEAVE 0 as it is, REST MARK EVERYONE -1 & then changing the -1  to 0.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void setZeroes(vector< vector<int> > &arr){
    int rows = arr.size();
    int columns = arr[0].size();

    // Traverse the matrix
    // i pointer tells row Number
    // j pointer tells Column Number
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<columns; j++){

            // if the current Element 0 - mark all its rows and column elements -1 except where there is 0 already.
            if(arr[i][j] == 0){

                // Marking column elements -1
                for(int rowCounter = 0; rowCounter < rows; rowCounter++){
                    // Change the element to -1 only if it is non-zero
                    if(arr[rowCounter][j]!=0){
                        arr[rowCounter][j] = -1;
                    }
                }

                // Marking row elements -1 
                for(int columnCounter = j; columnCounter < rows; columnCounter++){
                    // Change the element to -1 only if it is non-zero
                    if(arr[i][columnCounter]!=0){
                        arr[i][columnCounter] = -1;
                    }
                }
            }
        }
    }

    // Now, traverse the Matrix Again ans set all these -1 back to 0.
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(arr[i][j]==-1){
                arr[i][j] = 0;
            }
        }
    }
}

void print2DArray(vector<vector<int> > &arr ){
    int rows = arr.size();
    int cols = arr[0].size();

    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector< vector<int> > arr;

    arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    cout<<"Matrix before operations: "<<endl;
    print2DArray(arr);

    setZeroes(arr);

    cout<<"Matrix after operations: "<<endl;
    print2DArray(arr);    
}