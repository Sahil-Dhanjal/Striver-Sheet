// Here, we'll be printing the first n rows of the Pascal Triangle
//     1
//    1 1
//   1 2 1
//  1 3 3 1
// 1 4 6 4 1

/*
    Three important Observations:
        1. The number of elements in each row are equal to the rowNumber [Therefore, for the nth row of the pascal triangle will always have n columns]
        2. The first and the last column in each row have element 1 [corner Elements]
        3. The remaining elements a[i,j] are the sum of the elements present directly above them -> a[i-1,j-1] + a[i-1][j]
*/ 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print2DArray(vector< vector<int> > &ans){
    int rows = ans.size();

    for(int i = 0; i<rows; i++){

        int cols = ans[i].size();
        for(int j = 0; j<cols; j++){

            cout<<ans[i][j]<<" ";

        }

        cout<<endl;
    }
}

void pascalTriangle(int n){
    vector< vector<int> > ans(n);

    for(int i = 0; i < n; i++){ 

        // Resize Function would change the size of the vector that we use to store each row values.
        ans[i].resize(i+1);

        // We put the 0th and the last column of the current row the value 1
        ans[i][0] = ans[i][i]  = 1;

        // Now, we fill the remaining values - from the 1st column to the n-1th column using the Pascal's Traingle's Formula:
        // An element is the sum of the previous two values!
        // ans[i][j] = ans[i-1][j-1] + ans[i-1][j]

        // This loop handles the column's values
        // From the 1st Column till the 2nd Last Column [The reason being this that the 0th and last column have already been filled with the value 1]
        for(int j = 1; j<i; j++){
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
    }

    print2DArray(ans);
}

int main(){
    int n;

    cout<<"Enter the number of rows of Pascal's Triangle -> ";
    cin>>n;

    pascalTriangle(n);
}