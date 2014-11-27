#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/
 */

namespace binarytree_maximum_path_sum
{
	class Solution 
	{
	public:
		int maxPathSum(TreeNode *root) 
		{
			int res = std::numeric_limits<int>::min();
			int maxRootSum = helper(root, res);
			return std::max(res,maxRootSum);
		}

		int helper(TreeNode *root, int &maxSum)
		{
			if (NULL == root)
				return 0;

			int maxSumLeft = helper(root->left, maxSum);
			int maxSumRight = helper(root->right, maxSum);

			int result = std::max(root->val, root->val+maxSumLeft);
			result = std::max(result, root->val+maxSumRight);
			result = std::max(result, root->val+maxSumLeft+maxSumRight);

			maxSum = std::max(result, maxSum);

			return std::max(root->val, std::max(root->val + maxSumLeft, root->val + maxSumRight) );
		}
	};
};

BOOST_AUTO_TEST_SUITE( binarytree_maximum_path_sum_test )
	boost::shared_ptr<binarytree_maximum_path_sum::Solution> solution_(new binarytree_maximum_path_sum::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running binarytree_maximum_path_sum_test case1..." <<std::endl;

		TreeNode *root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->right = new TreeNode(3);
		
		BOOST_ASSERT( 6 == solution_->maxPathSum(root) );
		destoryTree(root);
	}

	BOOST_AUTO_TEST_CASE( case2 ) 	
	{
		std::cout << "running binarytree_maximum_path_sum_test case2..." <<std::endl;

		TreeNode *root = new TreeNode(-15);
		root->left = new TreeNode(5);
		root->right = new TreeNode(6);
		root->left->left = new TreeNode(-8);
		root->left->right = new TreeNode(1);
		root->left->left->left = new TreeNode(2);
		root->left->left->right = new TreeNode(6);
		root->right->left = new TreeNode(3);
		root->right->right = new TreeNode(9);
		root->right->right->right = new TreeNode(0);
		root->right->right->right->left = new TreeNode(4);
		root->right->right->right->right = new TreeNode(-1);
		root->right->right->right->right->left = new TreeNode(10);
		
		BOOST_ASSERT( 27 == solution_->maxPathSum(root) );
		destoryTree(root);
	}

	BOOST_AUTO_TEST_CASE( case3 ) 	
	{
		std::cout << "running binarytree_maximum_path_sum_test case3..." <<std::endl;

		TreeNode *root = new TreeNode(-3);

		BOOST_ASSERT( -3 == solution_->maxPathSum(root) );
		destoryTree(root);
	}

BOOST_AUTO_TEST_SUITE_END()	