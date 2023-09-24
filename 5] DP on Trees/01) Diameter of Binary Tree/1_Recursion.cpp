#include<iostream>
#include"../BinaryTree.h"

using namespace std;

class Solution
{
    public :

    int height(Node* root)
    {
        // Base Condition
        if(root == NULL) return 0;

        int left = height(root->left);
        int right = height (root->right);

        return 1 + max(left,right);
    }


    int temp_ans;
    int final_ans = INT_MIN;

    int diameter(Node* root)
    {
       if(root == NULL) return 0; 

       int left_Height = height(root->left);
       int right_Height = height(root->right);

       int left_Diameter = diameter(root->left);
       int right_Diameter = diameter(root->right);

       int temp_ans = 1 + left_Height + right_Height;                           // Diameter passing through current root.

       return max(temp_ans, max(left_Diameter,right_Diameter) );
    }
};

int main()
{
    vector<int> input = {1,2,3,4,5,6,7,-1,-1,-1,-1,-1,-1,-1,-1};
    Tree t1(input);
    Node* root = t1.root;

    Solution S1;
    cout << "Diameter : " << S1.diameter(root) << endl;
}