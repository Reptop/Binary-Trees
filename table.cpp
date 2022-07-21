#include <bits/stdc++.h>
//Author: Raed K (Reptop)
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // constructor
    Node(int val)
    {
        data = val;

        // the children, which is diffrentiated based on its left or right pos
        left = NULL;
        right = NULL;
    }
};

// passing the answer by reference so it is changed outside the funcitons context
void sum(Node *root, int &answer);

int main()
{

    int answer = 0;

    /*create root*/
    Node *root = new Node(2);
    /* following is the tree after above statement

             2
            / \
        NULL   NULL
    */

    root->left = new Node(3);
    root->right = new Node(4);
    /* 3 and 4 become left and right children of 2
                  2
                /   \
                3      4
               / \     / \
            NULL NULL NULL NULL
    */

    root->left->left = new Node(5);
    /*
              2
            /    \
           3      4
          / \     / \
         5 NULL NULL NULL
        / \
      NULL NULL
    */
    root->left->right = new Node(6);
    /*
              2
            /    \
           3      4
          / \     / \
         5  6 NULL NULL
        / \
      NULL NULL
    */

    sum(root, answer);
    cout << answer;

    return 0;
}

// time complexity = O(N)
void sum(Node *root, int &answer)
{

    if (root == NULL)
    {
        return;
    }
    
    //add data to answer
    answer += root->data;

    // first travserse left branches
    sum(root->left, answer);

    // then traverse to right branches
    sum(root->right, answer);
}