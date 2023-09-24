#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node
{
    int data;
    Node* left = NULL;                                   // Default value is NULL for Left and Right Child.
    Node* right = NULL;
};

queue<Node*> que;

Node* create(vector<int> levelOrder)
{
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

int main()
{   
    vector<int> levelOrder = {1,2,3,4,5,6,7,-1,-1,-1,-1,-1,-1,-1,-1};
    Node* bt = create(levelOrder);
    cout << "Hello" << endl;
}


/*

Note :-
1. Checking the "-1" is neccessary. Through this code, you can create non-strict binary tree. Means a Binary Tree which have only one child.
2. You can avoid giving -1 for the last level of a Binary Tree by checking the size of input array in the while loop itself.
3. I am not doing it, as it will reduce the readability & will make program difficult to understand.

*/