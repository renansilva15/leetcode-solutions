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
