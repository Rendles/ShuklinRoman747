#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
int value;
struct Node* left;
struct Node* right;
struct Node* parent;
} Node;

typedef struct Tree
{
struct Node* root;
int count;
} Tree;

typedef struct ListNode
{
Node* ptr_node_tree;
struct ListNode* next;
} ListNode;

typedef struct List
{
ListNode* first;
ListNode* last;
} List;

void init(Tree* tree) 
{
tree->root = NULL;
}
void CreateList(List* q)
{
q->first = NULL;
q->last = NULL;
};

int Insert(Tree* tree, int value) {
Node* Vague = (Node*)malloc(sizeof(Node));

Vague->value = value;

if (tree->root == NULL) {
Vague->left = Vague->right = NULL;
Vague->parent = NULL;
tree->root = Vague;
tree->count = 1;
return 0;
}

if (Vague->value == tree->root->value)
return -1;

Node* root2 = (Node*)malloc(sizeof(Node)), * root3 = NULL;

root2 = tree->root;

while (root2 != NULL)
{
root3 = root2;
if (value < root2->value)
root2 = root2->left;
else
root2 = root2->right;
}

if (Vague->value == root3->value)
{
return -1;
}

Vague->parent = root3;
Vague->left = NULL;
Vague->right = NULL;

if (value < root3->value)
root3->left = Vague;
else
root3->right = Vague;
tree->count++;
return 0;
}

void Shift(Node* root)
{
if (root)
{
Shift(root->left);
Shift(root->right);
printf("%d ", root->value);
}
}
int main()
{
Tree* tree = (Tree*)malloc(sizeof(Node));
init(tree);

int a[7];
scanf("%d%d%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]);
for (int i = 0; i < 7; i++)
Insert(tree, a[i]);
Shift(tree->root);

printf("\n");

return 0;
}
