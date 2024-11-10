/*There are N ropes numbered from 0 to N − 1, whose lengths are given in an array A, lying on the floor in a line. For each I (0 ≤ I < N), the length of rope I on the line is A[I].

We say that two ropes I and I + 1 are adjacent. Two adjacent ropes can be tied together with a knot, and the length of the tied rope is the sum of lengths of both ropes. The resulting new rope can then be tied again.

For a given integer K, the goal is to tie the ropes in such a way that the number of ropes whose length is greater than or equal to K is maximal.

For example, consider K = 4 and array A such that:

    A[0] = 1
    A[1] = 2
    A[2] = 3
    A[3] = 4
    A[4] = 1
    A[5] = 1
    A[6] = 3

We can tie:
    rope 1 with rope 2 to produce a rope of length A[1] + A[2] = 5;
    rope 4 with rope 5 with rope 6 to produce a rope of length A[4] + A[5] + A[6] = 5.
    After that, there will be three ropes whose lengths are greater than or equal to K = 4. It is not possible to produce four such ropes.

Write a function:
    int solution(int K, vector<int> &A) 

that, given an integer K and a non-empty array A of N integers, returns the maximum number of ropes of length greater than or equal to K that can be created.*/

/*Assumptions
    N is an integer within the range [1..100,000];
    K is an integer within the range [1..1,000,000,000];
    each element of array A is an integer within the range [1..1,000,000,000]*/

/*문제풀이
    1. i를 기반으로 순회한다.시작 시에는 cur_sum= 0, count = 0
    2. 만약 A[i] >= K: count+= 1, cur_sum = 0으로 만들기.
        Else : cur_sum + A[i] >= K : count += 1, cur_sum = 0
                cur_sum + A[i] < K : cur_sum += A[i]*/

#include <iostream>
#include <vector>
using namespace std;

int solution(int K, vector<int> &A){
    int cur_sum = 0;
    int count = 0;

    for (int a : A){
        if (a >= K) {
            count++;
            cur_sum = 0;
        } else {
            if (cur_sum + a >= K) {
                count++;
                cur_sum = 0;
            } else cur_sum += a;
        }
    }
    return count;
}

int main(){
    vector<int> A = {1,2,3,4,1,1,3};
    int K = 4;
    cout << solution(K, A);
}