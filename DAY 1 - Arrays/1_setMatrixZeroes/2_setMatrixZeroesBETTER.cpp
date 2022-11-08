// A Better Solution to the Brute FOrce Solution
// T.C -> O(n*m + n*m)
// S.C -> o(n + m)

/*

    APPROACH:
        1. Take two dummy arrays of the lengths of the rows and columns respectively initialised as -1.
        2. Traverse through the array:
            2.1. Whenever a 0 in encountered, at its rowIndex in the dummyArray(size: rows) mark a 0 there.
            2.2. And, at its column index in dummyArray(Size: Columns) mark a 0 as well.
        3. By the end of traversal, we'll know what all rows and columns have to changed to 0 entirel [w/o having to affect any other 0 values as in previous attempt]
        4. Now, for the indices where the value is 0 in the dummy Arrays, only change those rows/columns entirely to 0. [FOr this both the Dummy Arrays would have to be traversed]

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector< vector<int> > &arr){

    int rows = arr.size();
    int cols = arr[0].size();

    // Create two Dummy Arrays
    vector<int> dummyRows(rows , -1); // stores the  marked the row indices of the element with the value 0 as 0, encountered while traversing the 2D Array
    vector<int> dummyColumns(cols , -1); // stores the marked column indices of the element with the value 0 as 0, encountered while traversing the 2D Array

    // Traversing the 2D Array
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            // If element 0, mark its indices in the respective dummy arrays to be 0.
            if(arr[i][j]==0){
                // Row Index marked 0 at its respective index.
                dummyRows[i] = 0;

                // Column Index Marked 0 at its respective index.
                dummyColumns[j] = 0;
            }
        }
    }

    // Now, change all the elements of the marked rows and columns as 0 entirely
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            // If either of the current Indices of row/column in the Dummy Array is 0, we'll update the current element to 0 as it was a part of such a row/column.
            if(dummyRows[i] == 0 || dummyColumns[j] == 0){
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