// T.C -> O(nlogn) + o(n^2);
// 'nlogn' for sorting & n^2 because we are checking to the right for each index which is a nested loop.

// S.C-> O(n) in the worst case, no merge possible, therefore we put all the Sub-intervals in the vector as it is

// Given Intervals:
// [[1,3],[2,6],[8,10],[15,18]]

// O/p: 
// [[1,6],[8,10],[15,18]]

// Approach:
// 1. Is Array Sorted or not? if not, sort.
// 2. Linearly iterate, do the checks for merge possibility of the Sub-interval at the current index with all of its next Sub-intervals.
// 3. Create a new Data Structure and insert the overlapped/Merged Sub-Intervals in this D.S.

// IMPORTANT NOTE: while iterating, if current sub-interval lies within the overlapped interval, then continue & move to the next one.

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

        // The current Sub-interval in Hand.
        int start = input[i].first;
        int end = input[i].second;

        // Since the intervals already lies in the data structure present, we continue
        if(!ans.empty()){
            // We won't check here that start>=ans.back().second
            // Because, yeh toh already hoga as the input array has been sorted!
            if( (start <= ans.back().second) ){
                continue;
            }
        }

        // For the current sub-interval in hand do the merge possibility checks with all the following Sub-Intervals.
        // Therefore, the inner loop starts from i+1
        for(int j = i+1; j<n; j++){
            // Checking the merge possibility
            if( input[j].first <= end ){
                end = max(end , input[j].second);
            }
        }

        ans.push_back({start , end});
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
