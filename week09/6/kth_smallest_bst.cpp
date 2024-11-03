/*
Given the root of a binary search tree, and an integer k, return the kth
smallest value (1-indexed) of all the values of the nodes in the tree.
*/
#include <cassert>

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

void Helper(TreeNode* v, int& k, int& ans) {
  if (v == nullptr) return;
  if (k <= 0) return;
  if (v->left) Helper(v->left, k, ans);
  if (k > 0) --k;
  if (k == 0 && ans < 0) {
    ans = v->val;
    return;
  }
  if (v->right) {
    Helper(v->right, k, ans);
  }
}

int kthSmallest(TreeNode* root, int k) {
  int ans = -1;
  Helper(root, k, ans);
  return ans;
}

int main() {
  TreeNode* t1 = new TreeNode(3);
  t1->left = new TreeNode(1);
  t1->right = new TreeNode(4);
  t1->left->right = new TreeNode(2);
  assert(kthSmallest(t1, 1) == 1);

  TreeNode* t2 = new TreeNode(5);
  t2->left = new TreeNode(3);
  t2->right = new TreeNode(6);
  t2->left->left = new TreeNode(2);
  t2->left->right = new TreeNode(4);
  t2->left->left->left = new TreeNode(1);
  assert(kthSmallest(t2, 3) == 3);
}