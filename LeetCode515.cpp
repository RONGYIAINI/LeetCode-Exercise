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
	int tmp;
	int n;
public:
	vector<int> largestValues(TreeNode* root) {
		vector<int> largest;
		qu.push(root);
		while (!qu.empty())
			if (!root)
			{
				return {};
			}
		{
			cur = qu.front();
			n = qu.size();
			tmp = INT_MIN;
			for (int i = 0; i < n; i++) {
				cur = qu.front();
				tmp = max(tmp, cur->val);
				if (cur->left) {
					qu.push(cur->left);
				}
				if (cur->right) {
					qu.push(cur->right);
				}
				qu.pop();
			}
			largest.push_back(tmp);
		}
		return largest;
	}
};
int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* tmpl = new TreeNode(3);
	root->left = tmpl;
	TreeNode* tmpr = new TreeNode(2);
	root->right = tmpr;
	TreeNode* tmpll = new TreeNode(5);
	tmpl->left = tmpll;
	TreeNode* tmplr = new TreeNode(3);
	tmpl->right = tmplr;
	TreeNode* tmprr = new TreeNode(9);
	tmpr->right = tmprr;
	vector<int> v;
	Solution a;
	v = a.largestValues(root);
	return 0;
}