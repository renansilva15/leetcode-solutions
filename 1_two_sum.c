#include <stdio.h>
#include <stdlib.h>

const int MEMORY_ALLOCATION_ERROR = 1;

typedef struct Node
{
  int key;
  int value;
  struct Node *next;
} Node;

typedef struct HashMap
{
  Node **nodes;
  int size;
} HashMap;

int hash(int key, int size)
{
  return abs(key) % size;
}

HashMap *createHashMap(int size)
{
  HashMap *hashMap = (HashMap *)malloc(sizeof(HashMap));

  if (hashMap == NULL)
  {
    perror("Error allocating memory for hashMap");
    exit(MEMORY_ALLOCATION_ERROR);
  }

  hashMap->nodes = (Node **)malloc(sizeof(Node *) * size);

  if (hashMap->nodes == NULL)
  {
    perror("Error allocating memory for nodes in hashMap");
    // Free previously allocated memory
    free(hashMap);
    exit(MEMORY_ALLOCATION_ERROR);
  }

  hashMap->size = size;

  for (int i = 0; i < size; i++)
  {
    hashMap->nodes[i] = NULL;
  }

  return hashMap;
}

void addToHashMap(HashMap *hashMap, int key, int value)
{
  Node *newNode = (Node *)malloc(sizeof(Node));

  if (newNode == NULL)
  {
    perror("Error allocating memory for newNode");
    exit(MEMORY_ALLOCATION_ERROR);
  }

  newNode->key = key;
  newNode->value = value;

  int hashedKey = hash(key, hashMap->size);

  newNode->next = hashMap->nodes[hashedKey];
  hashMap->nodes[hashedKey] = newNode;
}

int getFromHashMap(HashMap *hashMap, int key)
{
  int hashedKey = hash(key, hashMap->size);

  Node *node = hashMap->nodes[hashedKey];
  while (node != NULL && node->key != key)
  {
    node = node->next;
  }

  return node != NULL ? node->value : -1;
}

void freeHashMap(HashMap *hashMap)
{
  for (int i = 0; i < hashMap->size; i++)
  {
    Node *nodeToFree = hashMap->nodes[i];
    while (nodeToFree != NULL)
    {
      Node *temp = nodeToFree;
      nodeToFree = nodeToFree->next;
      free(temp);
    }
  }

  free(hashMap->nodes);
  free(hashMap);
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
  *returnSize = 2;
  int *result = (int *)malloc(sizeof(int) * (*returnSize));

  if (result == NULL)
  {
    perror("Error allocating memory for result");
    exit(MEMORY_ALLOCATION_ERROR);
  }

  HashMap *hashMap = createHashMap(numsSize);

  int complement, complementIndex;
  for (int i = 0; i < numsSize; i++)
  {
    complement = target - nums[i];
    complementIndex = getFromHashMap(hashMap, complement);

    if (complementIndex != -1)
    {
      result[0] = complementIndex;
      result[1] = i;
      break;
    }

    addToHashMap(hashMap, nums[i], i);
  }

  freeHashMap(hashMap);

  return result;
}

int main()
{
  int nums[] = {2, 7, 11, 15};
  int numsSize = 4;
  int target = 9;
  int returnSize;

  int *result = twoSum(nums, numsSize, target, &returnSize);
  printf("[%d, %d]\n", result[0], result[1]);

  free(result);
  return 0;
}