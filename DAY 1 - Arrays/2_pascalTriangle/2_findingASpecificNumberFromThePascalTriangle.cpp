// Finding the (i,j)the element asked for from the pascal's triangle
// Here, the interviewer would've given you the rowNumber and the columnNumber of some element from the Pascal's Triangle and we're required to find that.

// Every element in a Pascal's triangle follows this formula:
// (r-1)C(c-1), where r and c represent the rowNumber & column Number of that Element.
// nCr=n! / (r! * n-r!)

// Another important Note: The Column Number is specific to the row, it isn't looked at from a Global/bird eye's view POV.

// The result of the formula for just one element can be computed in O(N) Complexity because we're just calculating factorials.
// Now, say that we're asked to computed some entire nth row, therefore doing the same for n elements in that row would be taking O(N^2) T.C. We'll have to optimize it & work on the same formula in a much smarter way!

// Watch this video from 4:00 -> https://www.youtube.com/watch?v=6FLvhQjZqvM&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=9&ab_channel=takeUforward

// Finding the value of nck(optimally as discussed above) = [n * (n-1) * (n-2) * _ _ _ _ _ * (n-k+1)]  

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int nCk(int n, int k){
    int result = 1;

    // Base cases
    if(k == 0 || k == n){
        // In these cases the value comes out to be 1.
        return result;
    }

    for(int i = 0; i<k; i++){
        // For each iteration,
        // 1. We multiply it by some value
        result *= (n-i);

        // 2. And, we divide it by some value
        result /= (i+1);
    }

    return result;
}

// Coded with the assumption that rowNumber & ColNumber values start from 1 & not 0.
int findTheElementValue(int rowNumber , int colNumber){
    int updatedRowNumber = rowNumber - 1;
    int updatedColNumber = colNumber - 1;

    return nCk(updatedRowNumber, updatedColNumber);
}

int main(){
    int rowNumber;
    int colNumber;

    cout<<"[ASSUMPTION: The RowNumber and colNumber values start from 1 & not 0!]"<<endl;
    cout<<"[It is because when they would've been starting from 0, we don't need the updation for Combinatorial calculation there, otherwise we do need to decrement the value by 1 for both the rowNumber & colNumber values]"<<endl;

    cout<<"Enter the RowNumber: ";
    cin>>rowNumber;

    cout<<"Enter the colNumber: ";
    cin>>colNumber;

    cout<<"\nThe Element is -> "<<findTheElementValue(rowNumber , colNumber);
}