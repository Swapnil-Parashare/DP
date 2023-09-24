#include<iostream>
#include"../BinaryTree.h"

using namespace std;

class Solution
{
    public :

    int height(struct Node* node)
    {
        
        // Base Condition
        if(node == NULL ) return 0;
        
        int left = height(node->left);
        int right = height(node->right);
        
        return 1 + max(left,right);
        
    }
  
    
    int diameter(Node* root) 
    {
        
        // Base Condition
        if(root == NULL) return 0;
        
        int left = diameter(root->left);
        int right = diameter(root->right);
        int current = 1 + height(root->left) + height(root->right);
        
        return max(current,max(left,right));
        
        
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