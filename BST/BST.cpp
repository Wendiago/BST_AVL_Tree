#include <iostream>
using namespace std;

struct NODE 
{
	int key;
	NODE* pLeft;
	NODE* pRight;
};

//Initialize a NODE from a given value:
NODE* createNode(int data)
{
	NODE* newNode = new NODE;
	newNode->key = data;
	newNode->pLeft = NULL;
	newNode->pRight = NULL;
	return newNode;
}

//Add a NODE with given value into a given Binary Search Tree:
void Insert(NODE*& pRoot, int x)
{
	if (pRoot == NULL)
	{
		NODE* newNode = createNode(x);
		pRoot = newNode;
	}
	else
	{
		//key < root
		if (x < pRoot->key)
		{
			Insert(pRoot->pLeft, x);
		}
		else
		{
			Insert(pRoot->pRight, x);
		}
	}
}

//Pre-order Traversal:
void NLR(NODE* pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}
	else
	{
		cout << pRoot->key << "";
		NLR(pRoot->pLeft);
		NLR(pRoot->pRight);
	}
}

//In - order Traversal :
void LNR(NODE* pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}
	else
	{
		LNR(pRoot->pLeft);
		cout << pRoot->key << "";
		LNR(pRoot->pRight);
	}
}

//Post-order Traversal:
void LRN(NODE* pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}
	else
	{
		LRN(pRoot->pLeft);
		LRN(pRoot->pRight);
		cout << pRoot->key << "";
	}
}

//Calculate the height of a given Binary Tree;
int Height(NODE* pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	else 
	{
		int lheight = Height(pRoot->pLeft); //Height of sub left tree
		int rheight = Height(pRoot->pRight); //Height of sub right tree
		if (lheight > rheight) //return the highest height
		{
			return lheight + 1;
		}
		else
		{
			return rheight + 1;
		}
	}
}

//Print Node at i level
void printnode_level(NODE* pRoot, int level)
{
	if (pRoot == NULL)
	{
		return;
	}
	else if (level == 0)
	{
		cout << pRoot->key;
	}
	else
	{
		printnode_level(pRoot->pLeft, level - 1);
		printnode_level(pRoot->pRight, level - 1);
	}
}

//Level-order Traversal:
void LevelOrder(NODE* pRoot)
{
	int height = Height(pRoot);
	for (int i = 0; i < height; i++)
	{
		printnode_level(pRoot, i);
	}
}

//Count the number of NODE from a given Binary Tree:
int countNode(NODE* pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + countNode(pRoot->pLeft) + countNode(pRoot->pRight);
	}
}

//Calculate the total value of all NODEs from a given Binary Tree:
int sumNode(NODE* pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}
	else
	{
		return pRoot->key + sumNode(pRoot->pLeft) + sumNode(pRoot->pRight);
	}
}

//Find and return a NODE with given value from a given Binary Search Tree:
NODE* Search(NODE* pRoot, int x)
{
	if (pRoot == NULL)
	{
		return;
	}
	else
	{

	}
}
