/*You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
*/
/*Constraints:
    m == mat.length
    n == mat[i].length
    2 <= n, m <= 100
    1 <= k <= m
    matrix[i][j] is either 0 or 1.*/

/*수도코드
목표 : minPriority_Queue에 sum(row)를 priority로 넣고, eleme에는 index를 넣고, K개를 뽑음. 
*/



#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

        for (int i = 0; i < mat.size(); i++){
            int row_sum = 0;
            for (int j = 0; j < mat[i].size(); j++){
                row_sum = row_sum + mat[i][j];
            }
            q.push(make_pair(row_sum, i));
        }

        vector<int> answer;
        for (int m = 0; m < k ; m++){
            answer.push_back(q.top().second);
            q.pop();
        }

        return answer;
    }
};