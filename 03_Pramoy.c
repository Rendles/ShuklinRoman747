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
void init(Tree* tree) {

tree->root = NULL;
}
void CreateList(List* q)
{
q->first = NULL;
q->last = NULL;
};

int Push(List* q, Node* n)
{
ListNode* newList = (ListNode*)malloc(sizeof(ListNode));
newList->ptr_node_tree = n;
newList->next = NULL;
if (q->first)
q->last->next = newList;
else
q->first = newList;
q->last = newList;
return 0;
}

void ClearList(List* q)
{
ListNode* Vague, * nq;
Vague = q->first;
do
{
nq = Vague;
Vague = Vague->next;
free(nq);
}
while (Vague);
q->first = NULL;
q->last = NULL;
}
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
void print(Node* node)
{
if (node)
{
List list1, list2;
List* ptrlist1 = &list1;
List* ptrlist2 = &list2;
CreateList(ptrlist1);
CreateList(ptrlist2);
Node* Vague = NULL;
ListNode* q = NULL;
int c = 0, val = node->value, j = 0;
Node* l = node->left;
Node* r = node->right;
Push(ptrlist1, node);
while (1)
{
while (ptrlist1->first)
{
if (ptrlist1->first)
{
ListNode* nodelist_pop;
Vague = ptrlist1->first->ptr_node_tree;
nodelist_pop = ptrlist1->first;
ptrlist1->first = ptrlist1->first->next;
if (ptrlist1->first == NULL)
ptrlist1->last = NULL;
free(nodelist_pop);
}
else
Vague = NULL;
if (ptrlist1->first == NULL)
{
if (Vague->value == val && c == 1)
printf(" ");
else
printf("%d ", Vague->value);
}
else if (Vague->value == val && c == 1)
printf(" ");
else
printf("%d ", Vague->value);
if (Vague->left)
Push(ptrlist2, Vague->left);
else
Push(ptrlist2, node);
if (Vague->right)
Push(ptrlist2, Vague->right);
else
Push(ptrlist2, node);
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
ClearList(ptrlist2);
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
printf(" ");
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
