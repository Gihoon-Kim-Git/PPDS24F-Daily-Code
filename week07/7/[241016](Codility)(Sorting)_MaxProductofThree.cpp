/*<문제>
A non-empty array A consisting of N integers is given. The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).

For example, array A such that:
    A[0] = -3
    A[1] = 1
    A[2] = 2
    A[3] = -2
    A[4] = 5
    A[5] = 6
contains the following example triplets:

(0, 1, 2), product is −3 * 1 * 2 = −6
(1, 2, 4), product is 1 * 2 * 5 = 10
(2, 4, 5), product is 2 * 5 * 6 = 60
Your goal is to find the maximal product of any triplet.

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A, returns the value of the maximal product of any triplet.


Write an efficient algorithm for the following assumptions:

N is an integer within the range [3..100,000];
each element of array A is an integer within the range [−1,000..1,000].*/

/*풀이
    1. 일단 오름차순으로 sort를 한다.
    2. maxproduct1 : A[0], A[1], A[A.size()-1]  #-값 2개와 가장 큰 +값 하나
        maxproduct2 : A[A.size()-1], A[A.size()-2], A[A.size()-3] # 큰 값 3개
    3. 2에서 얻은 두 값 중 큰 거 반환.
*/

#include <iostream>
#include <vector>
#include <algorithm> //sort위해서 필요함.
using namespace std;

int solution(vector<int> &A){
    sort(A.begin(), A.end());
    
    int maxproduct1 = A[0] * A[1] * A[A.size()-1];
    int maxproduct2 = A[A.size()-1] * A[A.size()-2] * A[A.size()-3];

    return maxproduct1 > maxproduct2 ? maxproduct1 : maxproduct2;
}

//Quicksort를 사용한 풀이-----------------------------------------------------------------
class Solution{
    public:
    void quickSort(vector<int> &arr, int low, int high){
        if (low < high) {
            int pivot_done = partition(arr, low, high);
            quickSort(arr, low, pivot_done-1);
            quickSort(arr,pivot_done+1, high);
        }
    }
    public:
    int partition(vector<int> &arr, int low, int high){
        //1) 
        int pivotValue = arr[high];
        int i = low;

        //2)
        for (int j = low; j < high; j++){
            if (arr[j] <= pivotValue){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                i++;
            }
        }

        //3
        int temp2 = arr[i];
        arr[i] = pivotValue;
        arr[high] = temp2; // arr[i]값을 기존 pivotValue가 위치했던 자리로.

        //4
        return i;
    }
};

int solution(vector<int> &A){
    Solution sol1;
    sol1.quickSort(A, 0, A.size()-1);
    
    int maxproduct1 = A[0] * A[1] * A[A.size()-1];
    int maxproduct2 = A[A.size()-1] * A[A.size()-2] * A[A.size()-3];

    return maxproduct1 > maxproduct2 ? maxproduct1 : maxproduct2;
}


//----------번외 : 최대곱과 그 때의 index까지 같이 반환해야 한다면...? ---------------------

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareByValueAscending(const pair<int, int>& a, const pair<int, int>& b){
    return a.first < b.first;
}

vector<int> solution_with_index(vector<int> &A){
    vector<pair<int,int>> indexed_A;
    for (int i = 0; i < A.size(); i++){
        pair<int, int> new_pair = make_pair(A[i], i);
        indexed_A.push_back(new_pair);
    }

    sort(indexed_A.begin(), indexed_A.end(), compareByValueAscending);

    int maxproduct1 = indexed_A[0].first * indexed_A[1].first * indexed_A[A.size()-1].first;
    vector<int> indices1 = {indexed_A[0].second, indexed_A[1].second, indexed_A[A.size()-1].second};
    
    int maxproduct2 = indexed_A[A.size()-1].first * indexed_A[A.size()-2].first * indexed_A[A.size()-3].first;
    vector<int> indices2 = {indexed_A[A.size()-1].second, indexed_A[A.size()-2].second, indexed_A[A.size()-3].second};

    return maxproduct1 > maxproduct2 ? indices1 : indices2;
}

int main(){
    vector<int> A = {-3, 1, 2, -2, 5, 6};
    vector<int> result = solution_with_index(A);
    cout << "Indices: {" << result[0] << ", " << result[1] << ", " << result[2] << "}";
    // {5,4,2}
    return 0;
}