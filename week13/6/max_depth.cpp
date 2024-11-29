#include <algorithm>
#include <cassert>
#include <memory>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
  }
};

int main() {
  TreeNode* t1 = new TreeNode(3);
  t1->left = new TreeNode(9);
  t1->right = new TreeNode(20);
  t1->right->left = new TreeNode(15);
  t1->right->right = new TreeNode(7);

  TreeNode* t2 = new TreeNode(1);
  t2->right = new TreeNode(2);

  Solution sol;
  assert(sol.maxDepth(t1) == 3);
  assert(sol.maxDepth(t2) == 2);
}
