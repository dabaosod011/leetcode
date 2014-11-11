#include "markeloff.h"

/*
*	http://www.geeksforgeeks.org/print-binary-tree-vertical-order/
*/

namespace print_binarytree_in_vertical_order
{
	class Solution1 
	{
	public:
		void findMinMax(TreeNode *node, int &min, int &max, int hd)
		{
			if (node == NULL) 
				return;
 
			min = std::min(min,hd);
			max = std::max(max,hd);

			findMinMax(node->left, min, max, hd-1);
			findMinMax(node->right, min, max, hd+1);
		}

		void printVerticalLine(TreeNode *node, int line_no, int hd)
		{
			if (node == NULL) 
				return;
 
			if (hd == line_no)
				cout << node->val << " ";
 
			printVerticalLine(node->left, line_no, hd-1);
			printVerticalLine(node->right, line_no, hd+1);
		}

		void verticalOrder(TreeNode *root)
		{
			int min = 0, max = 0;
			findMinMax(root, min, max, 0);
 
			for (int line_no = min; line_no <= max; line_no++)
			{
				printVerticalLine(root, line_no, 0);
				cout << endl;
			}
		}
		
	};

	class Solution2
	{
	public:
		void generator(TreeNode* root, int hd, map<int, vector<int> > &m)
		{
			if (root == NULL)
				return;
 
			m[hd].push_back(root->val);
			generator(root->left, hd-1, m);
			generator(root->right, hd+1, m);
		}
 
		void verticalOrder(TreeNode* root)
		{
			map <int,vector<int> > m;
			generator(root, 0, m);
 
			for (auto it=m.begin(); it!=m.end(); it++)
			{
				for (auto i=0; i<it->second.size(); ++i)
					cout << it->second[i] << " ";
				cout << endl;
			}
		}
	};
}

BOOST_AUTO_TEST_SUITE( print_binarytree_in_vertical_order_test )

	boost::shared_ptr<print_binarytree_in_vertical_order::Solution1> solution_1(new print_binarytree_in_vertical_order::Solution1());
	boost::shared_ptr<print_binarytree_in_vertical_order::Solution2> solution_2(new print_binarytree_in_vertical_order::Solution2());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{	
		std::cout << "running print_binarytree_in_vertical_order_test case1..." <<std::endl;
		TreeNode *root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->right = new TreeNode(3);
		root->left->left = new TreeNode(4);
		root->left->right = new TreeNode(5);
		root->right->left = new TreeNode(6);
		root->right->right = new TreeNode(7);
		root->right->left->right = new TreeNode(8);
		root->right->right->right = new TreeNode(9);
 
		solution_1->verticalOrder(root);
		std::cout<<std::endl;
		solution_2->verticalOrder(root);
		destoryTree(root);
	}
BOOST_AUTO_TEST_SUITE_END()	