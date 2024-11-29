#include <algorithm>
#include <cassert>
#include <cmath>

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
 private:
  void helper(TreeNode* node, int& res, int cur_max, int cur_min) {
    if (node == nullptr) return;

    res = max(res, max(abs(cur_max - node->val), abs(cur_min - node->val)));
    cur_max = max(cur_max, node->val);
    cur_min = min(cur_min, node->val);
    helper(node->left, res, cur_max, cur_min);
    helper(node->right, res, cur_max, cur_min);
  }

 public:
  int maxAncestorDiff(TreeNode* root) {
    if (root == nullptr) return 0;

    int res = 0;
    int cur_max = root->val;
    int cur_min = root->val;

    helper(root, res, cur_max, cur_min);
    return res;
  }
};

int main() {
  TreeNode* t1 = new TreeNode(8);
  t1->left = new TreeNode(3);
  t1->left->left = new TreeNode(1);
  t1->left->right = new TreeNode(6);
  t1->left->right->left = new TreeNode(4);
  t1->left->right->right = new TreeNode(7);
  t1->right = new TreeNode(10);
  t1->right->right = new TreeNode(14);
  t1->right->right->left = new TreeNode(13);

  TreeNode* t2 = new TreeNode(1);
  t2->right = new TreeNode(2);
  t2->right->right = new TreeNode(0);
  t2->right->right->left = new TreeNode(3);

  Solution sol;
  assert(sol.maxAncestorDiff(t1) == 7);
  assert(sol.maxAncestorDiff(t2) == 3);
}