#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode *addTwoNumbersAux(struct ListNode *l1, struct ListNode *l2, int carry)
{
  if (l1 == NULL && l2 == NULL && carry == 0)
  {
    return NULL;
  }

  int sum = carry;

  if (l1 != NULL)
  {
    sum += l1->val;
    l1 = l1->next;
  }

  if (l2 != NULL)
  {
    sum += l2->val;
    l2 = l2->next;
  }

  carry = (int)sum / 10;
  sum = sum % 10;

  struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
  if (newNode == NULL)
  {
    perror("Error allocating memory for newNode");
    exit(1);
  }

  newNode->val = sum;

  newNode->next = addTwoNumbersAux(l1, l2, carry);

  return newNode;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
  return addTwoNumbersAux(l1, l2, 0);
}

void printList(struct ListNode *head)
{
  while (head != NULL)
  {
    printf("%d -> ", head->val);
    head = head->next;
  }
  printf("NULL\n");
}

void freeList(struct ListNode *head)
{
  struct ListNode *temp;

  while (head != NULL)
  {
    temp = head;
    head = head->next;
    free(temp);
  }
}

int main()
{
  struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
  struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));

  l1->val = 2;
  l1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  l1->next->val = 4;
  l1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  l1->next->next->val = 3;
  l1->next->next->next = NULL;

  l2->val = 5;
  l2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  l2->next->val = 6;
  l2->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  l2->next->next->val = 4;
  l2->next->next->next = NULL;

  printf("List 1: ");
  printList(l1);
  printf("List 2: ");
  printList(l2);

  struct ListNode *result = addTwoNumbers(l1, l2);
  printf("Result: ");
  printList(result);

  freeList(l1);
  freeList(l2);
  freeList(result);

  return 0;
}
