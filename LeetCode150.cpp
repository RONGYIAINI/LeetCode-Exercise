#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> tmp;
		for (int i = 0; i < tokens.size(); i++)
		{
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
				if (tokens[i] == "+")
				{
					int a = tmp.top();
					tmp.pop();
					int b = tmp.top();
					tmp.pop();
					tmp.push(a + b);
				}
				if (tokens[i] == "-")
				{
					int a = tmp.top();
					tmp.pop();
					int b = tmp.top();
					tmp.pop();
					tmp.push(b - a);
				}
				if (tokens[i] == "*")
				{
					int a = tmp.top();
					tmp.pop();
					int b = tmp.top();
					tmp.pop();
					tmp.push(a * b);
				}
				if (tokens[i] == "/")
				{
					int a = tmp.top();
					tmp.pop();
					int b = tmp.top();
					tmp.pop();
					tmp.push(b / a);
				}
			}
			else {
				tmp.push(atoi(tokens[i].c_str()));
			}
		}
		return tmp.top();
	}
};
int main()
{
	Solution a;
	vector<string> tokens{ "4","13","5","/","+" };
	cout << a.evalRPN(tokens);
	return 0;
}