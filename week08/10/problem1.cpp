#include<iostream>
#include<vector>

using namespace std;



int solution(int K, vector<int> &A) {
    // Implement your solution here
    int ans;
    vector < vector <int> > results;
    vector<int> merge;
    int merged = 0;
    int will_subtract = 0;
    
    for (int i = 0; i < A.size(); i++) {
        if (A[i] < K) {
            while (merged < K ) {
                merged += A[i];
                merge.push_back(A[i]);
                i++;
                if (i == A.size() && merged < K) {
                    will_subtract = -1;
                }
            }
            results.push_back(merge);
            merged = 0;
            merge.clear();
            i--;
        } else {
            vector <int> temp;
            temp.push_back(A[i]);
            results.push_back(temp);
        }
    }

    ans = results.size();
    return ans + will_subtract;
}


int main(void) {

    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(1);
    A.push_back(1);
    A.push_back(3);

    cout << solution(4, A) << endl; // should return 3
    
    return 0;
}


