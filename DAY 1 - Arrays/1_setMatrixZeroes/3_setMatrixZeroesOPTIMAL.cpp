// An OPTIMAL Solution to the better Solution
// T.C -> O(n*m + n*m)
// S.C -> o(1) [Space Optimized as compared to our last solution]

/*
    APPROACH: Read the Algorithm written here for more clarity along with Animation. [link](https://leetcode.com/problems/set-matrix-zeroes/solutions/177436/set-matrix-zeroes/)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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

void setZeroes(vector< vector<int> > &arr){

    int rows = arr.size();
    int cols = arr[0].size();

    // We'll use the 0th row and 0th column for the purpose of markings exactly how we used the dummy Arrays in the previous question.
    // Since they've the (0,0) element overlapping, we'll take a separate boolean variable to mark the 0th column but we use the (0,0)th element to mark the 0th row.
    // For this solution we are using an additional variable for the first column and using matrix[0][0] for the first row.

    // currently the boolean variable indicates that the 0th column has no 0 as it currently has the value 1.
    // When it has the value 0, it means that the 0th column has value 0.
    bool col0 = 1;

    // Traversing the 2D Array
    for(int i = 0; i<rows; i++){
            // if the 0th column element is 0 for the current row, mark the boolean variable 0 indicating that the 0th column contains a 0.
            if(arr[i][0] == 0) col0 = 0;
        for(int j = 1; j<cols; j++){

            // If an element is zero, we set the first element of the corresponding row and column to 0
            if(arr[i][j] == 0){
                arr[i][0] = 0;
                arr[0][j] = 0;
            }

            cout<<"Current Element Being Checked -> "<<arr[i][j]<<endl;
            print2DArray(arr);
            cout<<"----------------------------"<<endl;
        }
    }

    // Iterating over the Array once again & now using the 0th row and 0th column, we'll be updating the rest values
    for(int i = 1; i<rows; i++){
        for(int j = 1; j<cols; j++){
            if(arr[i][0] == 0 || arr[0][j] == 0){
                arr[i][j] = 0;
            }
        }
    }

    // Now, checking if the 0th row has to be updated or not by looking at arr[0][0] element
    if(arr[0][0] == 0){
        for(int i = 0; i<cols; i++){
            arr[0][i] = 0;
        }
    }

    // Now, checking if the 0th column has to be updated or not by looking at boolean variable col0
    if(col0 == 0){
        for(int i = 0; i<rows; i++){
            arr[i][0] = 0;
        }
    }

}

int main(){
    vector< vector<int> > arr;

    // arr = {{7, 19, 3},{4, 21, 0}};
    arr = { {1, 2, 3},{ 4, 0 ,6}, {7, 8 , 9} };
    // arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    cout<<"Matrix before operations: "<<endl;
    print2DArray(arr);

    setZeroes(arr);

    cout<<"Matrix after operations: "<<endl;
    print2DArray(arr);    
}
