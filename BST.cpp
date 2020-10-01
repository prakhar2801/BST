#include<bits/stdc++.h>
using namespace std;
struct node
{
	int key;
	struct node *left,*right;
};
struct node* newNode(int item) 
{ 
    struct node *temp =new node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}
struct node* insert(struct node* node, int key) 
{ 
    if (node == NULL) 
	return newNode(key); 
  
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    return node; 
} 
void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->key<<"->";
		inorder(root->right);
	}
}
void preorder(struct node* root)
{
	if(root!=NULL)
	{
		
		cout<<root->key<<"->";
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node* root)
{
	if(root!=NULL)
	{
		
		postorder(root->left);
		postorder(root->right);
		cout<<root->key<<"->";
	}
}

struct node* minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
   
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
  
struct node* deleteNode(struct node* root, int key) 
{ 
    if (root == NULL) return root; 
  
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
    else
    { 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        struct node* temp = minValueNode(root->right); 
  
        root->key = temp->key; 
  
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 
int main()
{
	struct node* root=NULL;
	root=insert(root,1);
	for (int i=2;i<10;i++)
	insert(root,i);
	
	
	inorder(root);
	cout<<"\n";
	
	preorder(root);
	cout<<"\n";
	
	postorder(root);
	cout<<"\n";
	root=deleteNode(root,5);
	inorder(root);
	
	return 1;
	
}
