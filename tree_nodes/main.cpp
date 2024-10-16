// C++ program for different tree traversals
#include <iostream>
#include "tree_nodes.cpp"
#include <vector>

using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */




/* Driver code*/
int main()
{
	struct TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);

    vector<TreeNode*> nodes = {root->left->right->left, root->left->right->right};

    auto lca = lowestCommonAncestor(root, nodes);
	// cout << "\nInorder traversal of binary tree is \n";
	// printInorder(root);
    cout << lca->val;

	return 0;
}