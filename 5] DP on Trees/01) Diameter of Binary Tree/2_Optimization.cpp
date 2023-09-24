#include<iostream>
#include"../BinaryTree.h"

using namespace std;

class Solution
{
    public :

    int temp_ans;
    int final_ans = INT_MIN;
    

    int height(Node* node)
    {
        if(node == NULL) return 0;

        int left = height(node->left);
        int right = height(node->right);

        temp_ans = left + right + 1;
        final_ans = max(temp_ans,final_ans);

        return 1 + max(left,right);
    }

    int diameter(Node* node)
    {
        height(node);
        return final_ans;
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