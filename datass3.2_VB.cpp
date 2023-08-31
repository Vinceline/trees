#include <iostream>
#include <stack>
using namespace std;

//creating doubly linked list for tree implementation
struct tree {
    int data;
    tree* prev;
    tree* next;
};
//putting data value in node
tree* getnode( int data)
{
    tree* newtree = new tree;
    newtree->data = data;
    newtree->prev = newtree->next = nullptr;
    return newtree;
}
//passing by reference so root is updated correctly
void insert(tree*& root, int data)
{
    //if root is empty, get new node
    if (root == nullptr)
    {
        root = getnode(data);
    }
    //if data is less than data of current node
    else if (data <= root->data)
    {
        //data is in left node of tree
        insert(root->prev, data);
    }
    else
    {
        //if greater, data is inserted to right node of tree
        insert(root->next, data);
    }
}
void inorder(tree* root)
{
    stack <tree*> stak;
    tree* current = root;

    //while stack or tree isn't empty
    while (current != nullptr || !stak.empty())
    {
        //double checking tree isn't empty
         //each node of tree is pushed to stack
        while (current != nullptr)
        {
            //each node of tree is pushed to stack and moved to left
            stak.push(current);
            current = current->prev;
        }

        current = stak.top();
        stak.pop();

        cout << current->data << " ";
        //move to right child of current node
        current = current->next;
    }
}
tree* binarytree()
{
    tree* root = nullptr;
    int num, data;
    cout << "please enter number of nodes for tree" << endl;
    cin >> num;
    //if number of nodes isn't zero
    //limiting to 7 subtrees total
    if (cin.fail()|| num == 0 || num >15)
    {
        cout << "sorry, invalid input... exiting program." << endl;
        exit(1);
    }
    cout << "please enter data for nodes: " << endl;
  
    while (num != 0)
    {
        //asking for data for each node and decrementing num
        cin >> data;
        //invalid input handling
        if (cin.fail())
        {
            cout << "sorry, invalid input... exiting program." << endl;
            exit(1);
        }
        insert(root, data);
        num--;

    }
    return root;
}
void deletetree(tree* root)
{
    if (root == nullptr)
        return;

    deletetree(root->prev);
    deletetree(root->next);

    delete root;
}

int main()
{
    //making tree empty before starting
    tree* root = nullptr;

    root = binarytree();

    cout << "Binary tree in inorder traversal: ";
    inorder(root);
    cout << endl;

    // freeing memory
    deletetree(root);
	return 0;
}