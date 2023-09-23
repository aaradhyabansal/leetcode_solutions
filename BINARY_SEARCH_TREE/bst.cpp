#include <bits/stdc++.h>
using namespace std;
class Node{
public:
int data;
Node* left;
Node* right;

Node(int data)
{
  this->data=data;
  this->left=NULL;
  this->right=NULL;
}
};

Node* insertIntoBST(Node* root,int data)
{
  if(root==NULL)
  {
    root=new Node(data);
    return root;
  }
  if(root->data>data)
  {
    root->left=insertIntoBST(root->left,data);
  }
  else
  {
    root->right=insertIntoBST(root->right,data);
  }
  return root;
}
void takeInput(Node* &root) {
        int data;
        cin >> data;

        while(data != -1) {
                root = insertIntoBST(root, data);
                cin >> data;
        }
}
void levelOrderTraversal(Node* root ) {
	queue<Node*> q;
	//initially
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		//A
		Node* temp = q.front();
		//B
		q.pop();
		
		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}	
		}
		else {
			//C
			cout << temp->data << " ";
			//D
			if(temp -> left) {
				q.push(temp ->left);
			}
			if(temp ->right) {
				q.push(temp->right);
			}
		}
  }
}
		void preOrderTraversal(Node* root) {
	//NLR
	if(root == NULL)
		return;

	cout << root->data << " ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root) {
	//LNR
	if(root == NULL)
		return;

	inOrderTraversal(root->left);
	cout << root->data << " ";
	inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
	//LRN
	if(root == NULL)
		return;

	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->data << " ";
}
Node* findNodeInBST(Node* root, int target){
  if(root==NULL)
  {
    return NULL;
  }
  if(root->data==target)
  {
    return root;
  }
 if(root->data>target)
  {
    return findNodeInBST(root->left,target);
  }
  else
  {
    return findNodeInBST(root->right,target);
  }
}

int minVal(Node* root) {
	Node* temp = root;
	if(temp == NULL) {
		return -1;
	}

	while(temp -> left != NULL) {
		temp = temp ->left;
	}
	return temp -> data;
}

int maxVal(Node* root) {
	Node* temp = root;
	if(temp == NULL) {
		return -1;
	}

	while(temp -> right != NULL) {
		temp = temp ->right;
	}
	return temp -> data;
}

Node* deleteNodeInBST(Node* root, int target){
  if(root==NULL)
  {
    return NULL;
  }
  if(root->data==target)
  {
    //4 cases
    //0 child
    if(root->left==NULL && root->right==NULL)
    {
      return NULL;
    }
    else if(root->left==NULL && root->right!=NULL)
    {
      Node* child=root->right;
      return child;
    }
    else if(root->left!=NULL && root->right==NULL)
    {
      Node* child=root->left;
      return child;
    }
    else{
      int inOrderPred=maxVal(root->left);

      root->data=inOrderPred;

      root->left=deleteNodeInBST(root->left,inOrderPred);
      return root;
      
    }
  }
  else if(target>root->data)
  {
    root->right=deleteNodeInBST(root->right,target);
  }
  else
  {
    root->left=deleteNodeInBST(root->left,target);
  }
  return root;
}


int main() {
	  Node* root = NULL;
	  cout << "Enter the data for Node " << endl;
	  takeInput(root);
	  cout << "Printing the tree" << endl;
	  levelOrderTraversal(root);
	  cout << endl;
	//   cout << "Printing Inorder: " << endl;
	//   inOrderTraversal(root);
	//   cout << endl;
	//   cout << "Printing Preorder: " << endl;
	//   preOrderTraversal(root);
	//   cout << endl;
	//   cout << "Printing Postorder: " << endl;
	//   postOrderTraversal(root);

	// bool ans  = findNodeInBST(root,155);
	// cout << "present or not : " << ans << endl;
	// cout << endl <<" Minimum value: " << minVal(root) << endl;
	// cout << endl << "Maximum value: " << maxVal(root) << endl;

	root = deleteNodeInBST(root, 100);
	levelOrderTraversal(root);
	
  return 0;
}