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

int Helper(TreeNode* v, bool is_left) {
  if (v == nullptr) return 0;

  if (v->left || v->right) {
    int sum = 0;
    if (v->left != nullptr) sum += Helper(v->left, true);
    if (v->right != nullptr) sum += Helper(v->right, false);
    return sum;
  }

  // Is leaf
  if (is_left) return v->val;
  return 0;
}

int SumOfLeftLeaves(TreeNode* root) { return Helper(root, false); }

int main() {
  // Consider freeing them
  TreeNode* tree1 = new TreeNode(3);
  tree1->left = new TreeNode(9);
  tree1->right = new TreeNode(20);
  tree1->right->left = new TreeNode(15);
  tree1->right->right = new TreeNode(7);
  assert(SumOfLeftLeaves(tree1) == 24);

  TreeNode* tree2 = new TreeNode(3);
  tree2->right = new TreeNode(7);

  assert(SumOfLeftLeaves(tree2) == 0);
}