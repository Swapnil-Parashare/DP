#include<iostream>
#include"../BinaryTree.h"

using namespace std;

class Solution
{
    public :

    int heightSum(Node* node)
    {
        // Base Condition
        if(node == NULL) return 0;

        int left = heightSum(node->left);
        int right = heightSum(node->right);

        int ans = max(left,right);

        return (ans < 0) ? node->data : node->data + ans;
    }

    int findMaxSum(Node* root)
    {
        // Base Condition
        if(root == NULL) return INT_MIN;                    // Very IMP

        int left = findMaxSum(root->left);
        int right = findMaxSum(root->right);

        int current;
        int left_HeightSum = heightSum(root->left);
        int right_HeighSum = heightSum(root->right);

        if      (left_HeightSum > 0 && right_HeighSum > 0)    current = root->data + left_HeightSum + right_HeighSum;
        else if (left_HeightSum < 0 && right_HeighSum < 0)    current = root->data;       
        else                                                  current = root->data + max(left_HeightSum,right_HeighSum);
        

        return max(current, max(left,right));
    }

};

int main()
{   
    // vector<int> levelOrder = {10,2,10,20,1,-1,- 25,-1,-1,-1,-1,3,4,-1,-1,-1,-1};
    vector<int> levelOrder = {-2,-10,-90,-1,-1,-1,-1};

    Tree t1(levelOrder);
    Node* root = t1.root;

    Solution S1;

    cout << "Maximum Path Sum : " << S1.findMaxSum(root) << endl;

}