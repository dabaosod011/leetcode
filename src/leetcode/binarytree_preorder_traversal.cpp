#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/binary-tree-preorder-traversal/
 */

namespace binary_tree_preorder_traversal
{
	class Solution 
	{
	public:
		vector<int> preorderTraversal(TreeNode *root) 
		{
			std::vector<int> pre_order;
			std::stack<TreeNode*> bucket;
			TreeNode *current_visited = root;

			if (root == NULL)
				return pre_order;

			while( current_visited != NULL || !bucket.empty() )
			{
				while( current_visited != NULL )
				{
					pre_order.push_back(current_visited->val);
					bucket.push(current_visited);
					current_visited = current_visited->left;
				}

				if( !bucket.empty() )
				{
					current_visited = bucket.top();
					bucket.pop();
					current_visited = current_visited->right;
				}
			}

			return pre_order;
		}
	};
};

BOOST_AUTO_TEST_SUITE( binary_tree_preorder_traversal_test )
	boost::shared_ptr<binary_tree_preorder_traversal::Solution> solution_(new binary_tree_preorder_traversal::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running binary_tree_preorder_traversal_test case1..." <<std::endl;

		TreeNode *root = new TreeNode(1);
		TreeNode *L1_left = new TreeNode(2);
		TreeNode *L1_right = new TreeNode(3);
		TreeNode *L2_right = new TreeNode(4);
		TreeNode *L2_left = new TreeNode(5);
		root->left = L1_left;
		root->right = L1_right;
		L1_left->right = L2_right;
		L1_right->left = L2_left;

		std::vector<int> preorder = solution_->preorderTraversal(root);		
		BOOST_ASSERT(	preorder[0] == 1
					 &&  preorder[1] == 2
					 &&  preorder[2] == 4
					 &&  preorder[3] == 3
					 &&  preorder[4] == 5 );

		destoryTree(root);
	}
	 
BOOST_AUTO_TEST_SUITE_END()	