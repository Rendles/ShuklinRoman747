#include <stdio.h>
#include<stdlib.h>

struct Node {
int value;
struct Node *next;
} Node;
struct list {
struct Node* begin;
} list;
int isEmpty(struct list* SP)
{
return SP->begin == NULL;
}
struct Node* find(struct list* SP, int value)
{
struct Node *tmp = SP->begin;
while (tmp->value != value) {
if (tmp->next != NULL)
tmp = tmp->next;
else
return 0;
}
return tmp;
}
void init(struct list* SP, int value)
{
struct Node* tmp;
tmp = (struct Node*)malloc(sizeof(struct Node));
tmp->value = value;
tmp->next = NULL;
SP->begin = tmp;
}
int push_back(struct list* SP, int x)
{
if (isEmpty(SP) == 1)
init(SP, x);
else
{
struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
tmp->value = x;
tmp->next = NULL;
struct Node* temp = SP->begin;
while (temp->next != NULL)
temp = temp->next;
temp->next = tmp;
}
return 0;
}
int push_front(struct list* SP, int x)
{
if (isEmpty(SP) == 1)
init(SP, x);
else
{
struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
tmp->value = x;
tmp->next = SP->begin;
SP->begin = tmp;
}
return 0;
}
int clear(struct list* SP)
{
if (isEmpty(SP) == 1)
{
struct Node *tmp = SP->begin;
struct Node *temp = NULL;
while (tmp != NULL)
{
temp = tmp->next;
free(tmp);
tmp = temp;
}
SP->begin = NULL;
}
}
void _remove(struct list* SP, struct Node *tmp) {
if (tmp != NULL) {
if (tmp == SP->begin)
SP->begin = tmp->next;
else
{
struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
temp = SP->begin;
while (temp->next != tmp)
temp = temp->next;
temp->next = tmp->next;
}
free(tmp);
}
}
int removeFirst(struct list* SP, int x)
{
struct Node* element = find(SP, x);
if (element != NULL) {
_remove(SP, element);
return 0;
}
return -1;
}
int insertAfter(struct list* SP, int num, int value)
{
struct Node *temp = malloc(sizeof(Node));
temp->value = value;

struct Node* tmp = SP->begin;
struct Node* prev_tmp = SP->begin;

for (int i = 1; i<num + 1; i++)
{
prev_tmp = tmp;
tmp = tmp->next;
if (tmp == NULL)
return -1;
}
prev_tmp->next = temp;
temp->next = tmp;
return 0;
}
void print(struct list* SP)
{
struct Node* tmp = SP->begin;
while (tmp->next != NULL)
{
printf("%d ", tmp->value);
tmp = tmp->next;
}
printf("%d\n", tmp->value);
}

int main()
{
int n, a;
struct list* SP = (struct list*)malloc(sizeof(struct list));
scanf("%d", &n);
for (int i = 0; i<n; i++)
{
scanf("%d", &a);
push_back(SP, a);
}
print(SP);

int k[3];
scanf("%d%d%d", &k[0], &k[1], &k[2]);
for (int i = 0; i<3; i++) {
if (find(SP, k[i]) != NULL)
printf("1 ");
else
printf("0 ");
}
printf("\n");
int m;
scanf("%d", &m);
push_back(SP, m);
print(SP);
int t;
scanf("%d", &t);
push_front(SP, t);
print(SP);
int j, x;
scanf("%d%d", &j, &x);
insertAfter(SP, j, x);
print(SP);
int z;
scanf("%d", &z);
removeFirst(SP, z);
print(SP);
clear(SP);
return 0;
} 
