#include<iostream>
#include"../BinaryTree.h"

using namespace std;

class Solution
{
    public :

    int temp_ans;
    int final_ans = INT_MIN;

    int heightSum(Node* node)
    {
        // Base Condition
        if(node == NULL) return 0;

        int left  = heightSum(node->left);
        int right = heightSum(node->right);


        /****************************************************************/
        if      (left > 0 && right > 0) temp_ans = node->data + left + right;
        else if (left < 0 && right < 0) temp_ans = node->data;
        else                            temp_ans = node->data + max(left,right);

        final_ans = max(temp_ans,final_ans);
        /****************************************************************/


        int ans = max(left,right);
        return (ans < 0) ? node->data : node->data + ans;

    }

    int findMaxSum(Node* root)
    {
        heightSum(root);
        return final_ans;
    }
};

int main()
{
    vector<int> levelOrder = {-2,-10,-90,-1,-1,-1,-1};

    Tree t1(levelOrder);
    Node* root = t1.root;

    Solution S1;

    cout << "Maximum Path Sum : " << S1.findMaxSum(root) << endl;

}