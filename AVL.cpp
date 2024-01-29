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

int getHeight(Node *root)
{
    return root ? root->height : 0;
}
int getBalanceFactor(Node *root)
{
    return getHeight(root->left) - getHeight(root->right);
}

/*
        x
       / \
      y   t3
     / \
    t1  t2

    right rotate->>>
    <<-left rotate

        y
       / \
     t1   x
         / \
        t2  t3

*/

Node *rightRotate(Node *x)
{
    Node *y = x->left;
    Node *t2 = y->right;

    y->right = x;
    x->left = t2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

Node *leftRotate(Node *y)
{
    Node *x = y->right;
    Node *t2 = x->left;

    x->left = y;
    y->right = t2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node *insert(Node *root, int value)
{
    if (!root)
        return new Node(value);
    if (value > root->data)
        root->right = insert(root->right, value);
    else if (value < root->data)
        root->left = insert(root->left, value);
    else
    {
        cout << value << " is already present.\n";
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int bf = getBalanceFactor(root);

    if (bf > 1)
    {
        if (value < root->left->data)
        {
            return rightRotate(root);
        }
        else
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    else if (bf < -1)
    {
        if (value > root->right->data)
        {
            return leftRotate(root);
        }
        else
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    return root;
}

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
    Node *root = NULL;
    root = insert(root, 11);
    root = insert(root, 9);
    root = insert(root, 18);
    root = insert(root, 5);
    root = insert(root, 10);
    preorder(root);
    cout << endl;
    root = insert(root, 4);
    preorder(root);
    return 0;
}