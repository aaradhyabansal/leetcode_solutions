/*The inorder predecessor of a node p is the node q that comes just before p in the binary tree's inorder traversal.

Given the root node of a binary search tree and the node p, find the inorder predecessor of node p. If it does not exist, return null.*/
/*Sample Input
4
9
2 1 3 -1 -1 -1 5 4 7
2
7
6 3 21 -1 -1 -1 89
1
12
8 3 9 -1 4 -1 10 -1 -1 -1 12 11
11
4
28 14 -1 11
1
Expected Output
2
-1
10
11
1 <= T <= 10
1 <= n <= 105
1 <= node value <= 109

*/

/* This is the Node class definition

class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int data) {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};
*/

Node* findPredecessor(Node* root, Node* p) {
    // add your logic here
	Node* pred=NULL;
	Node* curr=root;
	while(curr)
	{
		if(curr->data<p->data)
		{
			pred=curr;
			curr=curr->right;
		}
		else
			curr=curr->left;
	}
	return pred;
}