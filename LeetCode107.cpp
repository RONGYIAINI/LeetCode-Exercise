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
	vector<int> node; //用来存放每一层元素
	TreeNode* cur;
	queue<TreeNode*> qu; //进行层序遍历
	int Le = 1;  //记录层数
	int num; //记录每一层的元素数目
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root)  //返回一个2维vector
	{
		vector<vector<int>> BTree;  //需要返回的vector
		if (!root) {
			return BTree;
		}
		qu.push(root);
		for (int i = 0; i < Le; i++) {  //层数遍历
			num = qu.size();
			for (int j = 0; j < num; j++) { //元素保存
				cur = qu.front();
				node.push_back(cur->val);
				if (cur->left) {
					qu.push(cur->left);
				}
				if (cur->right) {
					qu.push(cur->right);
				}
				qu.pop();
			}
			BTree.insert(BTree.begin(),node);  //元素保存
			node.clear();
			if (!qu.empty()) {
				Le++;
			}
		}
		return BTree;
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



	Solution a;
	vector<vector<int>> BTree = a.levelOrderBottom(root);

	return 0;
}