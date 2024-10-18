// you can use includes, for example:
#include <vector>
#include <algorithm>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    sort(A.begin(), A.end());

    int product = 1;
    // All elements are negative
    if (A.back() < 0) {
        product *= A.at(A.size() - 1);
        product *= A.at(A.size() - 2);
        product *= A.at(A.size() - 3);
    }
    // The largest element is positive
    else {
        product *= A.back();
        // The 3rd largest element is negative
        if (A.at(A.size()-3) < 0) {
            product *= A.at(0);
            product *= A.at(1);
        }
        // The 3rd largest element is positive
        else {
            int pos_prod = A.at(A.size() - 2) * A.at(A.size() - 3);
            int neg_prod = A.at(0) * A.at(1);
            if (pos_prod > neg_prod) product *= pos_prod;
            else product *= neg_prod;
        }
    }
    
    return product;
}
