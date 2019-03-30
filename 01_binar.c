#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
int value;
struct Node *left;
struct Node *right;
struct Node *parent;
} Node;

typedef struct tree
{
struct Node *root;
int count;
} Tree;

typedef struct listNode
{
Node *ptr_node_tree;
struct listNode *next;
} ListNode;

typedef struct list
{
ListNode *first;
ListNode *last;
} List;

void createlist(List *q)
{
q->first = NULL;
q->last = NULL;
};

int push(List *q, Node *n)
{
ListNode *newList = (ListNode*)malloc(sizeof(ListNode));
newList->ptr_node_tree = n;
newList->next = NULL;
if (q->first)
q->last->next = newList;
else
q->first = newList;
q->last = newList;
return 0;
}

void clearlist(List *q)
{
ListNode *Value, *nq;
Value = q->first;
do
{
nq = Value;
Value = Value->next;
free(nq);
}
while (Value);
q->first = NULL;
q->last = NULL;
}

void init(Tree *tree)
{tree->root = NULL;}

void clear(Tree *tree) {
while (tree->root != NULL)
RemoveMin(tree->root, tree);
}

int insert(Tree *tree, int value)
{
Node *Value = (Node*)malloc(sizeof(Node));

Value->value = value;


if (tree->root == NULL) {
Value->left = Value->right = NULL;
Value->parent = NULL;
tree->root = Value;
tree->count = 1;
return 0;
}

if (Value->value == tree->root->value)
return -1;

Node *root2 = (Node*)malloc(sizeof(Node)), *root3 = NULL;

root2 = tree->root;

while (root2 != NULL)
{
root3 = root2;
if (value < root2->value)
root2 = root2->left;
else
root2 = root2->right;
}

if (Value->value == root3->value)
{return -1;}

Value->parent = root3;
Value->left = NULL;
Value->right = NULL;

if (value < root3->value)
root3->left = Value;
else
root3->right = Value;
tree->count++;
return 0;
}

int RemoveMin(Node *n, Tree *t) {
t->count--;

if (t->count != 1) {

while (n->left != NULL)
n = n->left;

if (n->right != NULL) {
n->right->parent = n->parent;

if (n == t->root)
t->root = n->right;
else
n->parent->left = n->right;
}
else
n->parent->left = NULL;

int value = n->value;
free(n);

return value;
}
else {
t->root = NULL;
t->count = 0;
free(t->root);

return 0;
}
}

Node *search(Node *node, int value) {
if ((node == NULL) || (node->value == value))
return node;
if (value < node->value)
return search(node->left, value);
else
return search(node->right, value);
}

Node *min(Node *root) {
Node *l = root;
while (l->left != NULL)
l = l->left;
return l;
}

int findNode(Tree *tree, int value, Node **node) {
Node *Value, *root2;
root2 = tree->root;
Value = search(root2, value);
if (Value == NULL) {
return 1;
}

*node = Value;
return 0;
}


int rotateLeft(Tree* tree) {
Node *Value = tree->root->right;

if (Value == NULL)
return 1;

tree->root->right = Value->left;
Value->left = tree->root;
Value->parent = tree->root->parent;
tree->root->parent = Value;
tree->root = Value;

return 0;
}

int rotateRight(Tree *tree) {
Node *Value = tree->root->left;

if (Value == NULL)
return 1;

tree->root->left = Value->right;
Value->right = tree->root;
Value->parent = tree->root->parent;
tree->root->parent = Value;
tree->root = Value;

return 0;
}

void print(Node* node)
{
if (node)
{
List list1, list2;
List *ptrlist1 = &list1;
List *ptrlist2 = &list2;
createlist(ptrlist1);
createlist(ptrlist2);
Node *Value = NULL;
ListNode*q = NULL;
int c = 0, val = node->value, j = 0;
Node *l = node->left;
Node *r = node->right;
push(ptrlist1, node);
while (1)
{
while (ptrlist1->first)
{
if (ptrlist1->first)
{
ListNode *nodelist_pop;
Value = ptrlist1->first->ptr_node_tree;
nodelist_pop = ptrlist1->first;
ptrlist1->first = ptrlist1->first->next;
if (ptrlist1->first == NULL)
ptrlist1->last = NULL;
free(nodelist_pop);
}
else
Value = NULL;
if (ptrlist1->first == NULL)
{
if (Value->value == val && c == 1)
printf("_\n");
else
printf("%d\n", Value->value);
}
else if (Value->value == val && c == 1)
printf("_ ");
else
printf("%d ", Value->value);
if (Value->left)
push(ptrlist2, Value->left);
else
push(ptrlist2, node);
if (Value->right)
push(ptrlist2, Value->right);
else
push(ptrlist2, node);
}
node->left = node->right = NULL;
c = 1;
q = ptrlist2->first;
while (ptrlist2->first->ptr_node_tree->value == val)
{
ptrlist2->first = ptrlist2->first->next;
if (ptrlist2->first->next == NULL)
if (ptrlist2->first->ptr_node_tree->value == val)
{
j = 1;
node->left = l;
node->right = r;
clearlist(ptrlist2);
break;
}
}
ptrlist2->first = q;
if (j == 1)
break;
ptrlist1->first = ptrlist2->first;
ptrlist1->last = ptrlist2->last;
ptrlist2->first = NULL;
ptrlist2->last = NULL;
}
}
else
printf("-\n");
}

void printTree(Tree *tree) {
print(tree->root);

}

Node* _Remove(Node* tree, int value)
{
Node* temp;
if (!tree) {
return tree;
}
else if (value < tree->value) {
tree->left = _Remove(tree->left, value);
}
else if (value > tree->value) {
tree->right = _Remove(tree->right, value);
}
else {
if (tree->left && tree->right) {
temp = min(tree->right);
temp->left = tree->left;
temp = tree->right;
free(tree);
return temp;
}
else if (tree->left == tree->right) {
free(tree);
return NULL;
}
else {
if (!tree->left) temp = tree->right;
else temp = tree->left;
free(tree);
return temp;
}
}
return tree;
}

int Remove(Tree *tree, int value) {
Node *Value = _Remove(tree->root, value);
if (!Value)
return 1;
else {
tree->count--;
tree->root = Value;
return 0;
}
}


int main() {
Tree *tree = (Tree*)malloc(sizeof(Node));
init(tree);

int a[4];
scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
for (int i = 0; i < 4; i++)
insert(tree, a[i]);

print(tree->root);

scanf("%d%d%d", &a[0], &a[1], &a[2]);
for (int i = 0; i < 3; i++)
insert(tree, a[i]);

print(tree->root);

int m;

scanf("%d", &m);

Node *TreeNode = (Node*)malloc(sizeof(Node));

if (findNode(tree, m, &TreeNode) == 1)
printf("-\n");
else
{
if (TreeNode->parent == NULL)
printf("_ ");
else
printf("%d ", TreeNode->parent->value);

if (TreeNode->left == NULL)
printf("_ ");
else
printf("%d ", TreeNode->left->value);
if (TreeNode->right == NULL)
printf("_ ");
else
printf("%d ", TreeNode->right->value);
}

printf("\n");

scanf("%d", &m);

if (findNode(tree, m, &TreeNode) == 1)
printf("-\n");
else
{
if (TreeNode->parent == NULL)
printf("_ ");
else
printf("%d ", TreeNode->parent->value);

if (TreeNode->left == NULL)
printf("_ ");
else
printf("%d ", TreeNode->left->value);
if (TreeNode->right == NULL)
printf("_ ");
else
printf("%d ", TreeNode->right->value);
}

scanf("%d", &m);

Remove(tree, m);

print(tree->root);

while (rotateLeft(tree) == 0);

print(tree->root);
while (rotateRight(tree) == 0);

print(tree->root);

printf("%d\n", tree->count);

clear(tree);

print(tree->root);

system("pause");
return 0;
}
