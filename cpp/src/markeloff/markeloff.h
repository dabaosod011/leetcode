#ifndef _MARKELOFF_HEADER_
#define _MARKELOFF_HEADER_

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <boost/test/unit_test.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/assign/list_of.hpp>

using namespace std;

/**
**	Binary Tree 
***/
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void destoryTree(TreeNode *root);

#endif
