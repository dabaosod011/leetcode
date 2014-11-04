#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/path-sum-ii/
 */

namespace binarytree_path_sum2
{
	class Solution 
	{
	public:
		vector<vector<int> > pathSum(TreeNode *root, int sum) 
		{
			vector<vector<int> > result;
			vector<int> curpath;
			helper(root, sum, curpath, result);

			return result;   
		}

		void helper(TreeNode *root, int sum, vector<int> curpath, vector<vector<int> > & result)
		{
			if(root == NULL)
				return;

			if (root->left == NULL && root->right == NULL && root->val == sum)
			{
				curpath.push_back(root->val);
				result.push_back(curpath);
				return;
			}

			curpath.push_back(root->val);
			if (root->left != NULL)
				helper(root->left, sum-root->val, curpath, result);
			if (root->right != NULL)
				helper(root->right, sum-root->val, curpath, result); 
		}
	};
};

BOOST_AUTO_TEST_SUITE( binarytree_path_sum2_test )
	boost::shared_ptr<binarytree_path_sum2::Solution> solution_(new binarytree_path_sum2::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running binarytree_path_sum2_test case1..." <<std::endl;

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
		TreeNode *L3_3 = new TreeNode(5);
		TreeNode *L3_4 = new TreeNode(1);
		L2_1->left = L3_1;
		L2_1->right = L3_2;
		L2_3->left = L3_3;
		L2_3->right = L3_4;

		vector<vector<int> > result = solution_->pathSum(root, 22);
		for (auto i=result.begin(); i<result.end(); i++)
		{
			for (auto j=i->begin(); j<i->end(); j++)
				std::cout << *j << " ";
			std::cout << std::endl;
		}

		destoryTree(root);
	}

BOOST_AUTO_TEST_SUITE_END()	