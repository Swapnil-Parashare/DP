#include <iostream>
#include<queue>
#include<vector>

using namespace std;

struct Node                                                 // This is not a Data Member. It is just a structure. (Blue Print)
{
    int data;
    Node* left = NULL;
    Node* right = NULL;
};


class Tree
{
    public :

    Node* root;                                                 

    // Constructor 
    Tree(vector<int> input)
    {
        root = create(input);
    }

    Node* create(vector<int> levelOrder)
    {
        queue<Node* > que;

        int i = 0;

        Node* RootNode = new Node;                           // IMP :- After declaring a pointer, never forget to allocate memory to it !!!

        int root = levelOrder[i++];                          // Observe Carefully. "Post Increment"

        RootNode->data = root;
        que.push(RootNode);

        Node* current;
        int value;

        while(!que.empty())
        {

            current = que.front();
            que.pop();


            // Left Child.
            value = levelOrder[i++];
            if(value != -1)
            {
                Node* temp = new Node;
                temp->data = value;
                current->left = temp;
                que.push(temp);
            }


            // Right Child
            value = levelOrder[i++];
            if(value != -1)
            {
                Node* temp = new Node;
                temp->data = value;
                current->right = temp;
                que.push(temp);
            }

        }

        cout << "\nBinary Tree created successfully!!!" << endl;
        return RootNode;
    }

};

/*
                    Objective : To create a Binary Tree.

1. Include this file as a header in the required class.
2. Create Object of this class.
3. Remember, this class have a parameterized constructor.
4. It means you need to pass the argument while creating the object itself.
5. It takes "Level Order Traversal" of Binary Tree as an input.
6. It will create the Binary Tree based on given Level Order Traversal.
7. The only Data Member of class i.e "root" will be initialized with the actual root of the created Binary Tree.
8. Now you can use this "root" to do whatever operations you want.

Note : In Level Order Traversal, -1 stands for NULL.

*/
