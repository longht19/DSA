#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

Node* NewNode(int data)
{
    Node* node = new Node;
    if(!node)
    {
        cout << "Error\n";
        return NULL;
    }
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* InsertLevelOrder(int arr[], int i, int n)
{
    Node* root = nullptr;
    if(i < n)
    {
        root = NewNode(arr[i]);
        root->left = InsertLevelOrder(arr, 2*i+1, n);
        root->right = InsertLevelOrder(arr, 2*i+2, n);
    }

    return root;
}

Node* InsertNode(Node* root, int data)
{
    if(root == NULL)
    {
        root = NewNode(data);
        return root;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp->left != NULL)
        {
            q.push(temp->left);
        } else {
            temp->left = NewNode(data);
            return root;
        }

        if(temp->right != NULL)
        {
            q.push(temp->right);
        } else 
        {
            temp->right = NewNode(data);
            return root;
        }
    }
    return NULL;
}
void InOrder(Node* root)
{
    if(root != NULL)
    {
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
}
void PreOrder(Node* root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(Node* root)
{
    if(root != NULL)
    {
        PreOrder(root->left);
        PreOrder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    int arr[] = { 8, 6, 7, 12, 5, 1, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = InsertLevelOrder(arr, 0, n);
    InOrder(root);
    cout << endl;
    PreOrder(root);
    cout << endl;
    PostOrder(root);
}