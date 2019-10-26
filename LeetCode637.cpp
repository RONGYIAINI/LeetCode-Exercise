#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution {
	queue<TreeNode*> qu;
	TreeNode* cur;
	double tmp = 0;
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> average;
		qu.push(root);
		while (!qu.empty())
		{
			int n = qu.size();
			if (n == 1) {
				cur = qu.front();
				average.push_back(cur->val);
			}
			
			for (int i = 0; i < n; i++) {
				cur = qu.front();
				if (cur->left) {
					qu.push(cur->left);
					tmp += cur->left->val;
				}
				if (cur->right) {
					qu.push(cur->right);
					tmp += cur->right->val;
				}
				qu.pop();
			}
			if (qu.size() != 1 && !qu.empty()) {
				average.push_back(tmp / qu.size());
			}
			tmp = 0;
		}
		return average;
	}
};
int main()
{
	TreeNode* root = new TreeNode(3);
	TreeNode* tmpl = new TreeNode(9);
	root->left = tmpl;
	TreeNode* tmpr = new TreeNode(20);
	root->right = tmpr;
	TreeNode* tmprl = new TreeNode(15);
	tmpr->left = tmprl;
	TreeNode* tmprr = new TreeNode(7);
	tmpr->right = tmprr;
	vector<double> v;
	Solution a;
	v = a.averageOfLevels(root);
	return 0;
}