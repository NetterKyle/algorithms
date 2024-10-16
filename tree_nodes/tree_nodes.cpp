#include <iostream>
#include <vector>
#include <set>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

TreeNode* dfs(TreeNode* node, const set<TreeNode*> targets) {
    if (node == nullptr) return nullptr; // Node does not exist, return to ancestor
    if (targets.count(node)) return node; // Found one of the target nodes, return address to ancestor

    auto leftNode = dfs(node->left, targets); // Call on left node
    auto rightNode = dfs(node->right, targets); // Call on right node
    if (leftNode && rightNode) return node; // Current node is an ancestor of two target nodes, this is the LCA so far
    return leftNode ? leftNode : rightNode; // Current node contains one target node, so it is not the LCA yet
}

TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
    set<TreeNode*> targets(nodes.begin(), nodes.end());
    auto lca =  dfs(root, targets);
    return lca;
}

struct Node {
	int data;
	struct Node *left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	cout << node->data << " ";

	/* now recur on right child */
	printInorder(node->right);
}