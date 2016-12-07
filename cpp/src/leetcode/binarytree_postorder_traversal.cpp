#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/binary-tree-postorder-traversal/
 */

namespace binary_tree_postorder_traversal
{
	class Solution 
	{
	public:
		vector<int> postorderTraversal(TreeNode *root) 
		{
			std::vector<int> post_order;
			std::stack<TreeNode*> bucket;
			TreeNode *current_visited, *last_visited=NULL;
			
			if (root == NULL)
				return post_order;

			bucket.push(root);
			while( !bucket.empty() )
			{
				current_visited = bucket.top();
				if ( (current_visited->left==NULL && current_visited->right==NULL )  // leaf node
					|| ( last_visited != NULL && (last_visited==current_visited->left || last_visited==current_visited->right)) )
				{
					post_order.push_back(current_visited->val);
					bucket.pop();
					last_visited = current_visited;
				}
				else
				{
					if (current_visited->right != NULL)
						bucket.push(current_visited->right);
					if  (current_visited->left != NULL)
						bucket.push(current_visited->left);
				}
			}

			return post_order;
		}
	};
};

BOOST_AUTO_TEST_SUITE( binary_tree_postorder_traversal_test )
	boost::shared_ptr<binary_tree_postorder_traversal::Solution> solution_(new binary_tree_postorder_traversal::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running binary_tree_postorder_traversal_test case1..." <<std::endl;

		TreeNode *root = new TreeNode(1);
		TreeNode *L1_left = new TreeNode(2);
		TreeNode *L1_right = new TreeNode(3);
		TreeNode *L2_right = new TreeNode(4);
		TreeNode *L2_left = new TreeNode(5);
		root->left = L1_left;
		root->right = L1_right;
		L1_left->right = L2_right;
		L1_right->left = L2_left;

		std::vector<int> postorder = solution_->postorderTraversal(root);		
		BOOST_ASSERT(	postorder[0] == 4
					 &&  postorder[1] == 2
					 &&  postorder[2] == 5
					 &&  postorder[3] == 3
					 &&  postorder[4] == 1 );

		destoryTree(root);
	}
	 
BOOST_AUTO_TEST_SUITE_END()	