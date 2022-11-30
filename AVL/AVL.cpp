#include <iostream>
using namespace std;

struct NODE 
{
	int key;
	NODE* pLeft;
	NODE* pRight;
};

NODE* createNode(int data)
{
	NODE* newNode = new NODE;
	newNode->key = data;
	newNode->pLeft = NULL;
	newNode->pRight = NULL;
	return newNode;
}

void NLR(NODE* pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}
	else
	{
		cout << pRoot->key << " ";
		NLR(pRoot->pLeft);
		NLR(pRoot->pRight);
	}
}

NODE* RightRotate(NODE* p)
{
    if (p == NULL)
    {
        return NULL;
    }
    else
    {
        NODE* pivot = p->pLeft;
        p->pLeft = pivot->pRight;
        pivot->pRight = p;
        return pivot;
    }
}

NODE* LeftRotate(NODE* p)
{
    if (p == NULL)
    {
        return NULL;
    }
    else
    {
        NODE* pivot = p->pRight;
        p->pRight = pivot->pLeft;
        pivot->pLeft = p;
        return pivot;
    }
}

int height(NODE* root)
{
    // base case: empty tree has a height of 0
    if (root == NULL) 
    {
        return 0;
    }
    // recur for the left and right subtree and consider maximum depth
    return 1 + max(height(root->pLeft), height(root->pRight));
}

int BalanceFactor(NODE* p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return height(p->pLeft) - height(p->pRight);
    }
}

NODE* Rebalance(NODE *&p)
{
    if (BalanceFactor(p) > 1) //Left case
    {
        if (BalanceFactor(p->pLeft) < 0) //Left - Right case
        {
            p->pLeft = LeftRotate(p->pLeft); //Rotate left at the left child of p
        }
        p = RightRotate(p); //Left - Left case
    }
    if (BalanceFactor(p) < -1) //Right case
    {
        if (BalanceFactor(p->pRight) > 0) //Right - Left case
        {
            p->pRight = RightRotate(p->pRight); //Rotate right at the right child of p
        }
        p = LeftRotate(p); // Right - Right case
    }
    return p;
}

//Add a node with given value x into a given AVL tree (Notify if the given value existed):
void Insert(NODE* &pRoot, int x)
{
    if (pRoot == NULL)
	{
		pRoot = createNode(x);
	}
	else 
	{
        if (x < pRoot->key)
        {
            Insert(pRoot->pLeft, x);
        }
        else if (x > pRoot->key)
        {
            Insert(pRoot->pRight, x);
        }
        else
        {
            cout << "Gia tri them vao khong hop le!" << endl;
        }
	}
    pRoot = Rebalance(pRoot);
}

void NodeTheMang(NODE* &pRoot, NODE *pTemp) //Tim node the mang
{
    if (pTemp->pLeft != NULL) //Find the leftmost node
    {
        NodeTheMang(pRoot, pTemp->pLeft);
    }
    else
    {
        pRoot->key = pTemp->key;
        pRoot = pTemp;
        pTemp = pTemp->pRight;
    }
}

//Remove a node with given value x from a given AVL tree(Notify if the given value not existed) :
void Remove(NODE*& pRoot, int x)
{
    if (pRoot == NULL)
    {
        return;
    }
    else
    {
        if (x < pRoot->key)
        {
            Remove(pRoot->pLeft, x);
        }
        else if (x > pRoot->key)
        {
            Remove(pRoot->pRight, x);
        }
        else
        {
            NODE* pDel = pRoot;
            if (pRoot->pLeft == NULL) // Node with only 1 child and is right subtree 
            {
                pRoot = pRoot->pRight;
            }
            else if (pRoot->pRight == NULL) // Node with only 1 child and is left subtree
            {
                pRoot = pRoot->pLeft;
            }
            else if (pRoot->pLeft == NULL && pRoot->pRight == NULL) // Node has no child
            {
                pRoot = NULL;
                delete(pDel);
            }
            else // Node with 2 children
            {
                NodeTheMang(pDel, pRoot->pRight); //Node the mang la node trai cung cua cay con phai
                delete(pDel);
            }
            pRoot = Rebalance(pRoot);
        }
    }
}

//Determine if a given Binary Tree is an AVL Tree :
bool isAVL(NODE * pRoot)
{
    int leftheight;
    int rightheight;
    if (pRoot == NULL)
    {
        return 1;
    }
    else
    {
        leftheight = height(pRoot->pLeft); // left height
        rightheight = height(pRoot->pRight); // right height
        if (abs(leftheight - rightheight) <= 1 && isAVL(pRoot->pLeft) && isAVL(pRoot->pRight))
        {
            return 1;
        }
        return 0;
    }
}

int main()
{
    NODE* pRoot = NULL;
    Insert(pRoot, 10);
    Insert(pRoot, 20);
    Insert(pRoot, 30);
    Insert(pRoot, 40);
    Insert(pRoot, 50);
    Insert(pRoot, 25);
    NLR(pRoot);
    cout << endl;
    if (isAVL(pRoot))
    {
        cout << "Is AVL Tree" << endl;
    }
    else
    {
        cout << "Not AVL Tree" << endl;
    }
    Remove(pRoot, 25);
    cout << "Delete node with value 25" << endl;
    NLR(pRoot);
    cout << endl;
    if (isAVL(pRoot))
    {
        cout << "Is AVL Tree" << endl;
    }
    else
    {
        cout << "Not AVL Tree" << endl;
    }
    return 0;
}