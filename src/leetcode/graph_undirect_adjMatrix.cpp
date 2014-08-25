// undirection graph implemented by adjacency matrix

#include "lc_header.h"

class UDGMatrix
{
private:
	std::vector<std::string> mNodes;
	std::vector<std::vector<int> > mEdges;
	int mNodesNumber;
	int mEdgesNumber;

public:
	UDGMatrix(std::vector<std::string> &nodes, std::vector<std::vector<int> > &edges);

	void display();
	std::vector<std::string> dfs();
	std::vector<std::string> bfs();

private:
	UDGMatrix()	{}
};

UDGMatrix::UDGMatrix(std::vector<std::string> &nodes, std::vector<std::vector<int> > &edges)
{
	mNodes.clear();
	mNodes = nodes;
	mNodesNumber = mNodes.size();

	mEdges.clear();
	mEdges = edges;

	mEdgesNumber = 0;
	for (int i = 0; i < nodes.size(); i++)
	{	
		for (int j = 0; j < i; j++)
		{
			if ( mEdges[i][j] == 1 )
				mEdgesNumber++;
		}
	}
}

void UDGMatrix::display()
{
	for (auto i = mEdges.begin(); i < mEdges.end(); i++ )
	{
		for (auto j = i->begin(); j < i->end(); j++)
			std::cout << *j << " ";
		
		std::cout <<endl;
	}
}

std::vector<std::string> UDGMatrix::dfs()
{
	std::vector<std::string> result;
	std::stack<int> stk;
	std::vector<bool> visitedVec(mNodesNumber, false);
	
	visitedVec[0] = true;
	stk.push(0);
	result.push_back(mNodes[0]);

	while( !stk.empty() )
	{
		int curNodeIndex = stk.top();
		int j = 0;
		for ( ; j < mNodesNumber; j++)
		{
			if( mEdges[curNodeIndex][j] == 1 && !visitedVec[j] )
			{
				result.push_back( mNodes.at(j) );
				visitedVec[j] = true;
				stk.push(j);
				break;
			}
		}
			
		if ( j == mNodesNumber )
			stk.pop();
	}

	return result;
}

std::vector<std::string> UDGMatrix::bfs()
{
	std::vector<std::string> result;
	std::queue<int> que;
	std::vector<bool> visitedVec(mNodesNumber, false);
	
	visitedVec[0] = true;
	que.push(0);
	result.push_back(mNodes[0]);

	while(!que.empty()) 
	{
		int curNodeIndex = que.front();
		que.pop();
		int j = 0;
		for ( ; j < mNodesNumber; j++)
		{
			if( mEdges[curNodeIndex][j] == 1 && !visitedVec[j] )
            {
                result.push_back( mNodes.at(j) );
                visitedVec[j] = true;
                que.push(j);
            }
		}
	}

	return result;
}



BOOST_AUTO_TEST_SUITE( udg_matrix_test )

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running udg_matrix_test case1..." <<std::endl;

		std::vector<std::string> nodes = boost::assign::list_of("A")("B")("C")("D")("E")("F")("G");
		std::vector<std::vector<int> > edges( nodes.size() , vector<int>(nodes.size(),0));
		edges[0][2] = edges[2][0] = 1;
		edges[0][3] = edges[3][0] = 1;
		edges[0][5] = edges[5][0] = 1;
		edges[1][2] = edges[2][1] = 1;
		edges[2][3] = edges[3][2] = 1;
		edges[4][6] = edges[6][4] = 1;
		edges[5][6] = edges[6][5] = 1;

		UDGMatrix graph = UDGMatrix(nodes, edges);
		graph.display();

		std::vector<std::string> result = graph.dfs();
		for (auto it = result.begin(); it < result.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		result = graph.bfs();
		for (auto it = result.begin(); it < result.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

BOOST_AUTO_TEST_SUITE_END()	