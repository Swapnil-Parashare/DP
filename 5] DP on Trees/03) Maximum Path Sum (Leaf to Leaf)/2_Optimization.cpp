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
            temp_ans = left + right + node->data;
            final_ans = max(temp_ans,final_ans);
            /****************************************************************/

            return node->data + max(left,right);
        }

        int findMaxSum(Node* root)
        {
            if(root == NULL || root->left == NULL || root->right == NULL)
            {
                return -1;
            }

            Solution S1;
            S1.heightSum(root);
            return S1.final_ans;
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