#include <bits/stdc++.h>
#include "RedBlackTree.h"
using namespace std;

void preorder(const RedBlackTree::Node *node, const RedBlackTree::Node *nil, vector<int> &result)
{
    if (node->isNil)
        return;
    result.push_back(node->key);
    preorder(node->left, nil, result);
    preorder(node->right, nil, result);
}

void inorder(const RedBlackTree::Node *node, const RedBlackTree::Node *nil, vector<int> &result)
{
    if (node->isNil)
        return;
    inorder(node->left, nil, result);
    result.push_back(node->key);
    inorder(node->right, nil, result);
}

void postorder(const RedBlackTree::Node *node, const RedBlackTree::Node *nil, vector<int> &result)
{
    if (node->isNil)
        return;
    postorder(node->left, nil, result);
    postorder(node->right, nil, result);
    result.push_back(node->key);
}

void printTraversal(const string &label, const vector<int> &v)
{
    cout << label << " : ";
    for (int i = 0; i < (int)v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}

int main()
{
    int N;
    cin >> N;

    RedBlackTree rbt;
    set<int> seen;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (!seen.count(x))
        {
            seen.insert(x);
            rbt.insert(x);
        }
    }

    int Q;
    cin >> Q;
    while (Q--)
    {
        string query;
        cin >> query;

        if (rbt.empty())
        {
            cout << "Tree kosong. Tidak ada yang bisa ditampilkan." << endl;
            continue;
        }

        vector<int> pre, in, post;
        preorder(rbt.root(), rbt.nil(), pre);
        inorder(rbt.root(), rbt.nil(), in);
        postorder(rbt.root(), rbt.nil(), post);

        if (query == "PREORDER")
        {
            printTraversal("[Preorder]", pre);
        }
        else if (query == "INORDER")
        {
            printTraversal("[Inorder]", in);
        }
        else if (query == "POSTORDER")
        {
            printTraversal("[Postorder]", post);
        }
        else if (query == "ALL")
        {
            printTraversal("[Preorder]", pre);
            printTraversal("[Inorder]", in);
            printTraversal("[Postorder]", post);
        }
    }
    return 0;
}