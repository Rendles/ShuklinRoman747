#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{
int Value;
struct Node* left;
struct Node* right;
struct Node* parent;
} Node;

typedef struct tree
{
struct Node* root;
int count;
} Tree;

void init(Tree* tree)
{
tree->root = NULL;
}
int Insert(Tree* tree, int value) {
Node* Vague = (Node*)malloc(sizeof(Node));

Vague->Value = value;


if (tree->root == NULL) {
Vague->left = Vague->right = NULL;
Vague->parent = NULL;
tree->root = Vague;
tree->count = 1;
return 0;
}

if (Vague->Value == tree->root->Value)
return -1;

Node* root2 = (Node*)malloc(sizeof(Node)), * root3 = NULL;

root2 = tree->root;

while (root2 != NULL)
{
root3 = root2;
if (value < root2->Value)
root2 = root2->left;
else
root2 = root2->right;
}

if (Vague->Value == root3->Value)
{
return -1;
}

Vague->parent = root3;
Vague->left = NULL;
Vague->right = NULL;

if (value < root3->Value)
root3->left = Vague;
else
root3->right = Vague;
tree->count++;
return 0;
}
void NoRecursion(Tree* Root)
{
Node* f[15];
int tmp = 0;
Node* temp[15];
int tmp_2 = 0;
Node* node = Root->root;
while (tmp_2 < Root->count)
{
while (node != NULL)
{
tmp_2++;
if (node->right != NULL)
{
tmp++;
f[tmp] = node->right;
}
temp[tmp_2] = node;
node = node->left;

}
node = f[tmp];
tmp = tmp - 1;
}
for (int i = 1; i <= tmp_2; i++)
{
printf("%d ", temp[i]->Value);
}
printf("\n");
}
int main()
{
Tree* tree = malloc(sizeof tree);
init(tree);

int a[7];
scanf("%d%d%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]);
for (int i = 0; i < 7; i++)
{
Insert(tree, a[i]);
}
NoRecursion(tree);

return 0;
}
