#include<iostream>
#include<queue>

using namespace std;

struct Node
{
    int data;
    Node* left = NULL;                                   // Default value is NULL for Left and Right Child.
    Node* right = NULL;
};

queue<Node*> que;

Node* create()
{
    Node* RootNode = new Node;                           // IMP :- After declaring a pointer, never forget to allocate memory to it !!!

    int root;
    cout << "Enter the value of Root : ";
    cin >> root;

    RootNode->data = root;

    que.push(RootNode);

    Node* current;
    int value;

    while(!que.empty())
    {
        current = que.front();
        que.pop();

        cout << "Enter the value of Left Child of " << current->data << " : " ;
        cin >> value;
        if(value != -1)
        {
            Node* temp = new Node;
            temp->data = value;
            current->left = temp;
            que.push(temp);
        }


        cout << "Enter the value of Right Child of " << current->data << " : " ;
        cin >> value;
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

    Node* bt = create();
}