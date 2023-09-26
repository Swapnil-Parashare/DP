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

        return node->data + max(left,right);
    }

    int solve(Node* root)
    {
        // Base Condition
        if(root == NULL) return INT_MIN;                    // Very IMP

        int left = solve(root->left);
        int right = solve(root->right);

        int current;
        int left_HeightSum = heightSum(root->left);
        int right_HeighSum = heightSum(root->right);

        current = root->data + left_HeightSum + right_HeighSum;        

        return max(current, max(left,right));
    }

    int findMaxSum(Node* root)
    {
        if(root == NULL || root->left == NULL || root->right == NULL)                  // This is because we want "Leaf to Leaf". So our Root node must have 2 childs for sure.
        {
            return -1;
        }

        return solve(root);

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