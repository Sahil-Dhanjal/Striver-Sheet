// Finding the complete specific row's elements [asked for from the pascal's triangle]
// Here, the interviewer would've given you the rowNumber, and you're required to find all the elements of that row from the Pascal's Triangle.

// Every element in a Pascal's triangle follows this formula:
// (r-1)C(c-1), where r and c represent the rowNumber & column Number of that Element.
// nCr=n! / (r! * n-r!)

// Another important Note: The Column Number is specific to the row, it isn't looked at from a Global/bird eye's view POV.

// The result of the formula for just one element can be computed in O(N) Complexity because we're just calculating factorials.
// Now, as we're asked to compute some entire ith row, therefore doing the same for i elements in that row would be taking O(n^2) T.C. {in the worst case, the ith row will have n elements} We'll have to optimize it & work on the same formula in a much smarter way!

// Earlier, we found the value of nck [n * (n-1) * (n-2) * _ _ _ _ _ * (n-k+1)]  
// Now, when we do the iterations from 0 to k, for each value of k we'll be getting a value of nCk representing the kth column element of that row. We'll store it in the answer Vector & finally return it.
// So all this for the entire ith row, gets done in O(n) time (as in worst case k can be n) as we are not repeatedely finding the 'combinatorials' of each column element of that ith row.

// AN IMPORTANT OBSERVATION BEING USED HERE -> The ith row has same number of elements.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void nCkCompleteRow(int n , vector<int> &ans){
    int result = 1;

    // as i is starting from 0 in the below loop & the division is being done by (i+1) to prevent the number division by 0.
    // Therefore, we'll have to store the result of the 0th column separately here.
    ans.push_back(result);

    // The loop goes from 0 to (n-1) as the nth row would also have n elements [the Pascal's triangle obsevation being used here!]
    for(int i = 0; i<n; i++){
        // For each iteration,
        // 1. We multiply it by some value
        result *= (n-i);

        // 2. And, we divide it by some value
        result /= (i+1);

        // The 'result' at this point represents the ith column's values in the nth row, and hence we store it in the 'ans' vector.
        ans.push_back(result);
    }
}

// Coded with the assumption that rowNumber values start from 1 & not 0.
void findTheCompleteRow(int rowNumber, vector<int> &ans){
    int updatedRowNumber = rowNumber - 1;


    nCkCompleteRow(updatedRowNumber ,  ans);
}

void print1DArray(vector<int> &ans){
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    cout<<endl;
}

int main(){
    int rowNumber;
    int colNumber;

    cout<<"[ASSUMPTION: The RowNumber value starts from 1 & not 0!]"<<endl;
    cout<<"[It is because when they would've been starting from 0, we don't need the updation for Combinatorial calculation there, otherwise we do need to decrement the value by 1 for both the rowNumber & colNumber values]"<<endl;

    cout<<"Enter the RowNumber: ";
    cin>>rowNumber;

    // Ans vector that stores all the elements of the ith row
    vector<int> ans;

    // Making the function call to store the complete row.
    findTheCompleteRow(rowNumber , ans);
    
    cout<<"The Elements of the "<<rowNumber<<" row are: ";
    print1DArray(ans);
}