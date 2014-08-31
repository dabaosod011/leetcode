#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int number;
    int num_of_gem = 0;
    std::string tmp;
    std::vector<std::string> rocks;
    
    cin>> number;
    for (int i = 0; i < number; i++)
	{
        cin >> tmp;
        rocks.push_back(tmp);        
    }
    
    if (rocks.size() == 0)
        return 0;
    
    for (char alph = 'a'; alph <= 'z'; alph++)
	{
        bool isGem = true;
         for (auto it = rocks.begin(); it != rocks.end(); it++) 
		 {
			 if (it->find(alph) == std::string::npos)
			 {
                 isGem = false;
                 break;
             }
         }
        if (isGem == true)
            num_of_gem++;
    }
	std::cout << num_of_gem<< std::endl;
}