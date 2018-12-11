#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() != popV.size())
			return false;
		size_t pushindex = 0, popindex = 0;
		stack<int> s;
		while (popindex < popV.size())
		{
			while (s.empty() || s.top() != popV[popindex])
			{
				if (pushindex < pushV.size())
				{
					s.push(pushV[pushindex++]);
				}
				else
					return false;
			}
			s.pop();
			popindex++;
		}
		return s.empty();
	}
};
int main()
{
	Solution s;
	vector<int> v1{ 1,2,3,4,5 };
	vector<int> v2{ 2,5,3,2,1 };
	vector<int> v3{ 2,5,2,3,1 };
	s.IsPopOrder(v1, v2);     //·µ»Ø true
	s.IsPopOrder(v1, v3);    //·µ»Ø false
	return 0;
}