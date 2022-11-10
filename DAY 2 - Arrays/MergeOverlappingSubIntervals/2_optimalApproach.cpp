// T.C -> O(nlogn) + o(n);
// 'nlogn' for sorting & n for LINEARLY ITERATING to check for merging possibilities with its following elements
// the sub-interval where we couldn't merge, we start from it the next time. [therefore, it is O(n) in total] 

// S.C-> O(n) in the worst case, no merge possible, therefore we put all the Sub-intervals in the vector as it is

// Given Intervals:
// [[1,3],[2,6],[8,10],[15,18]]

// O/p: 
// [[1,6],[8,10],[15,18]]

// Approach:
// 1. Create a new Data Structure and insert the first Sub-interval in it if it is empty.
// 2. Linearly iterate over the given input vector, do the checks for merge possibility of subsequent Sub-intervals by updating the last element in our created D.S. if the element would've been lying within it.
// 3. If the if the element would've bot been lying within it, we simply insert this non-mergable sub-interval in the ans vector as it is & start with the above procedure (2nd step) from this position now.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print1DArrayWithPairs(vector< pair<int,int> > &input){
    int n = input.size();
    for(int i = 0; i<n; i++){
        cout<<"{"<<input[i].first<<","<<input[i].second<<"}"<<" ";
    }
    cout<<endl;
}

vector< pair<int,int> > mergeSubIntervals(vector< pair<int,int> > &input){

    // Create an answer vector of pairs that stores the merged Sub-intervals.
    vector< pair<int,int> > ans;

    // Base case!
    // No intervals given, therefore return an empty Answer
    if(input.size() == 0){
        return ans;
    }

    int n = input.size();

    // Sort the input Array first
    sort(input.begin(), input.end());

    // Now, start with the traversals
    for(int i = 0; i<n; i++){

        // Is the ans vector empty currently?
        // If yes, then insert the first element from the input array into it.
        if(!ans.size()){
            ans.push_back(input[i]);
        }else{

            // The current Sub-interval in Hand.
            int start = input[i].first;
            int end = input[i].second;

            // Check if it can be merged with the last element in the ans vector
            // if yes, then update that last element [to the merged sub-interval]
            // if no, then insert this element into the ans vector as it is

            auto &lastElement = ans.back();

            if(start <= lastElement.second){
                // Merge possible
                // Update the last element in the ans vector
                lastElement.second = max(lastElement.second , end);

            }else{
                // Merge Ain't possible
                // Insert the current pair as it is
                ans.push_back({start , end});
            }
        }
    }

    return ans;
}

int main(){
    vector< pair<int,int> > input = {{1,3},{2,6},{8,10},{15,18}};

    vector< pair<int,int> > ans = mergeSubIntervals(input);

    cout<<"Before Merge -> ";
    print1DArrayWithPairs(input);

    cout<<"After Merge -> ";
    print1DArrayWithPairs(ans);
}
