#include <iostream>
#include "../../BinaryTree.h"                     // Observe the Path : ../../ means two directories backwards.

using namespace std;


class Solution
{
    public : 
    
    int height(Node* node)                                                          // Thou Data Members are accessbile inside class, still we give argument. This is because we want to implement Recurssive Logic.
    {
        // Base Condition
        if(node == NULL) return 0;
        
        int left = height(node->left);
        int right = height(node->right);

        return 1 + max(left,right);
    }
};

int main()
{   
    vector<int> input = {1,2,3,4,5,6,7,-1,-1,-1,-1,-1,-1,-1,-1};
    Tree t1(input);
    Node* root = t1.root;

    Solution S1;
    cout << "Height : " << S1.height(root) << endl;
}