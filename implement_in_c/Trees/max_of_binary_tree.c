#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int value;
    struct tree *left;
    struct tree *right;
};

struct tree *makeNode(int data)
{
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));

    node->value = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int maxOfTree(struct tree *head)
{

    if (head == NULL)
    {
        return 0;
    }
    else
    {
        int leftMax, rightMax;

        int max = head->value;

        if (head->left != NULL)
        {
            leftMax = maxOfTree(head->left);
            max = (max > leftMax) ? max : leftMax;
        }
        if (head->right != NULL)
        {

            rightMax = maxOfTree(head->right);
            max = (max > rightMax) ? max : rightMax;
        }
        return max;
    }
}

int main()
{
    struct tree *root = makeNode(10);
    root->left = makeNode(20);
    root->right = makeNode(30);
    root->right->left = makeNode(40);
    root->right->right = makeNode(50);
    int res = maxOfTree(root);
    printf("The size of the tree is %d", res);
    return 0;
}