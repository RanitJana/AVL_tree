#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data, height;
    Node *left, *right;
    Node(int value)
    {
        this->data = value;
        this->height = 1;
        this->left = this->right = NULL;
    }
};
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void inorderIteration(Node *root)
{
    if (!root)
        return;
    stack<Node *> s;
    while (root || s.size())
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}
void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void preorderIteration(Node *root)
{
    if (!root)
        return;
    stack<Node *> s;
    while (root || s.size())
    {
        while (root)
        {
            s.push(root);
            cout << root->data << " ";
            root = root->left;
        }
        root = s.top();
        s.pop();
        root = root->right;
    }
    cout << endl;
}
void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void postorderIteration(Node *root)
{
    if (!root)
        return;
    stack<Node *> s;
    while (root || s.size())
    {
        while (root)
        {
            s.push(root);
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        if (!s.empty() && root == s.top())
        {
            root = root->right;
        }
        else
        {
            cout << root->data << " ";
            root = NULL;
        }
    }
    cout << endl;
}
int main()
{

    return 0;
}