#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/
 */

namespace sum_root_to_leaf_numbers
{
	class Solution 
	{
	public:
		int sumNumbers(TreeNode *root) 
		{
			return sumhelper(root, 0);
		}

		int sumhelper(TreeNode *root, int sum)
		{
			if (NULL == root)
				return 0;

			if (NULL == root->left && NULL == root->right)  
				return sum*10 + root->val; 
			else 
				return sumhelper(root->left, sum*10 + root->val) + sumhelper(root->right, sum*10 + root->val);  
		}
	};
};

BOOST_AUTO_TEST_SUITE( sum_root_to_leaf_numbers_test )
	boost::shared_ptr<sum_root_to_leaf_numbers::Solution> solution_(new sum_root_to_leaf_numbers::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running sum_root_to_leaf_numbers_test case1..." <<std::endl;

		TreeNode *root = new TreeNode(1);
		TreeNode *L1_1 = new TreeNode(2);
		TreeNode *L1_2 = new TreeNode(3);
		root->left = L1_1;
		root->right = L1_2;

		BOOST_ASSERT( 25 == solution_->sumNumbers(root) );

		destoryTree(root);
	}

	BOOST_AUTO_TEST_CASE( case2 ) 	
	{
		std::cout << "running sum_root_to_leaf_numbers_test case2..." <<std::endl;

		TreeNode *root = new TreeNode(1);
		TreeNode *L1_1 = new TreeNode(0);
		root->left = L1_1;

		BOOST_ASSERT( 10 == solution_->sumNumbers(root) );

		destoryTree(root);
	}

	BOOST_AUTO_TEST_CASE( case3 ) 	
	{
		std::cout << "running sum_root_to_leaf_numbers_test case3..." <<std::endl;

		TreeNode *root = new TreeNode(0);
		TreeNode *L1_1 = new TreeNode(1);
		root->left = L1_1;

		BOOST_ASSERT( 1 == solution_->sumNumbers(root) );

		destoryTree(root);
	}
	 
BOOST_AUTO_TEST_SUITE_END()	