// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int partition(vector<int> &A, int low, int high)
    {
        int pivot = A[low];
        int i = low + 1;
        int j = high;

        while (true){
            while (i <= high && A[i] <= pivot){
                i++;
            }
            while (j >= low + 1 && A[j] >= pivot){
                j--;
            }
            if (i > j) {
                break;
            }
            swap(A[i], A[j]);
        }
        swap(A[low], A[j]);
        return j;
    }

void quickSort(vector<int> &A, int low, int high)
    {   
        if (low < high) {
            int q = partition(A, low, high);
            quickSort(A, low, q - 1);
            quickSort(A, q + 1, high);
        }
    }
    


int solution(vector<int> &A) {
    quickSort(A, 0, A.size()-1);
    int a1 = A[0] * A[1] * A[A.size() - 1];
    int a2 = A[A.size() - 3] * A[A.size() - 2] * A[A.size() -1];
    int ans = (a1 > a2 ? a1 : a2);
    return ans;

};
