/*
559. Maximum Depth of N-ary Tree
Easy

Topics

Companies
Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root
node down to the farthest leaf node.

Nary-Tree input serialization is represented in their level order traversal,
each group of children is separated by the null value (See examples).

Input: root = [1,null,3,2,4,null,5,6]
Output: 3

Input: root =
[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 5
*/
#include <cassert>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

int DepthHelper(Node* v, int depth) {
  int max_depth = depth;

  for (const auto& child : v->children) {
    int res = DepthHelper(child, depth + 1);
    max_depth = res > max_depth ? res : max_depth;
  }

  return max_depth;
}

int maxDepth(Node* root) {
  if (root == nullptr) return 0;
  return DepthHelper(root, 1);
}

int main() {
  Node* tree1 = new Node(1);
  tree1->children.push_back(new Node(3));
  tree1->children.push_back(new Node(2));
  tree1->children.push_back(new Node(4));
  tree1->children[0]->children.push_back(new Node(5));
  tree1->children[0]->children.push_back(new Node(6));
  assert(maxDepth(tree1) == 3);

  Node* tree2 = new Node(1);
  tree2->children.push_back(new Node(2));
  tree2->children.push_back(new Node(3));
  tree2->children.push_back(new Node(4));
  tree2->children.push_back(new Node(5));
  tree2->children[1]->children.push_back(new Node(6));
  tree2->children[1]->children.push_back(new Node(7));
  tree2->children[2]->children.push_back(new Node(8));
  tree2->children[3]->children.push_back(new Node(9));
  tree2->children[3]->children.push_back(new Node(10));
  tree2->children[1]->children[1]->children.push_back(new Node(11));
  tree2->children[2]->children[0]->children.push_back(new Node(12));
  tree2->children[3]->children[0]->children.push_back(new Node(13));
  tree2->children[1]->children[1]->children[0]->children.push_back(
      new Node(14));
  assert(maxDepth(tree2) == 5);
}
