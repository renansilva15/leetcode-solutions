#include <iostream>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    return addTwoNumbersAux(l1, l2, 0);
  }

private:
  ListNode *addTwoNumbersAux(ListNode *l1, ListNode *l2, int carry)
  {
    if (l1 == nullptr && l2 == nullptr && carry == 0)
    {
      return nullptr;
    }

    int sum = carry;

    if (l1 != nullptr)
    {
      sum += l1->val;
      l1 = l1->next;
    }

    if (l2 != nullptr)
    {
      sum += l2->val;
      l2 = l2->next;
    }

    carry = sum / 10;
    sum = sum % 10;

    ListNode *newNode = new ListNode(sum);

    newNode->next = addTwoNumbersAux(l1, l2, carry);

    return newNode;
  }
};

void printList(ListNode *head)
{
  while (head != nullptr)
  {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "NULL" << endl;
}

void freeList(ListNode *head)
{
  while (head != nullptr)
  {
    ListNode *temp = head;
    head = head->next;
    delete temp;
  }
}

int main()
{
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  Solution solution;
  ListNode *result = solution.addTwoNumbers(l1, l2);

  cout << "List 1: ";
  printList(l1);
  cout << "List 2: ";
  printList(l2);
  cout << "Result: ";
  printList(result);

  freeList(l1);
  freeList(l2);
  freeList(result);

  return 0;
}
