#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/path-sum/
 */

namespace binarytree_path_sum
{
	class Solution 
	{
	public:
		bool hasPathSum(TreeNode *root, int sum) 
		{
			if ( root == NULL )
				return false;
			else if (root->left == NULL && root->right == NULL && root->val == sum )
				return true;
			else
				return ( hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val) );
		}
	};
};

BOOST_AUTO_TEST_SUITE( binarytree_path_sum_test )
	boost::shared_ptr<binarytree_path_sum::Solution> solution_(new binarytree_path_sum::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running binarytree_path_sum_test case1..." <<std::endl;

		TreeNode *root = new TreeNode(5);

		TreeNode *L1_1 = new TreeNode(4);
		TreeNode *L1_2 = new TreeNode(8);
		root->left = L1_1;
		root->right = L1_2;

		TreeNode *L2_1 = new TreeNode(11);
		TreeNode *L2_2 = new TreeNode(13);
		TreeNode *L2_3 = new TreeNode(4);
		L1_1->left = L2_1;
		L1_2->left = L2_2;
		L1_2->right = L2_3;

		TreeNode *L3_1 = new TreeNode(7);
		TreeNode *L3_2 = new TreeNode(2);
		TreeNode *L3_3 = new TreeNode(1);
		L2_1->left = L3_1;
		L2_1->right = L3_2;
		L2_3->right = L3_3;	
		
		BOOST_ASSERT( true == solution_->hasPathSum(root, 22) );

		destoryTree(root);
	}

	BOOST_AUTO_TEST_CASE( case2 ) 	
	{
		std::cout << "running binarytree_path_sum_test case2..." <<std::endl;

		TreeNode *root = new TreeNode(-2);
		TreeNode *L1_1 = new TreeNode(-3);
		root->right = L1_1;

		BOOST_ASSERT( true == solution_->hasPathSum(root, -5) );

		destoryTree(root);
	}
	 
BOOST_AUTO_TEST_SUITE_END()	