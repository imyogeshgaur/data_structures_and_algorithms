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

void traverse_inorder(struct tree *head)
{
  if (head != NULL)
  {
    traverse_inorder(head->left);
    printf("%d ", head->value);
    traverse_inorder(head->right);
  }
}

int main()
{
  struct tree *root = makeNode(10);
  root->left = makeNode(20);
  root->right = makeNode(30);
  root->right->left = makeNode(40);
  root->right->right = makeNode(50);

  printf("Our struct tree is : \n");
  traverse_inorder(root);
  return 0;
}