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
	vector<int> node; //�������ÿһ��Ԫ��
	TreeNode* cur;
	queue<TreeNode*> qu; //���в������
	int Le = 1;  //��¼����
	int num; //��¼ÿһ���Ԫ����Ŀ
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root)  //����һ��2άvector
	{
		vector<vector<int>> BTree;  //��Ҫ���ص�vector
		if (!root) {
			return BTree;
		}
		qu.push(root);
		for (int i = 0; i < Le; i++) {  //��������
			num = qu.size();
			for (int j = 0; j < num; j++) { //Ԫ�ر���
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
			BTree.insert(BTree.begin(),node);  //Ԫ�ر���
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