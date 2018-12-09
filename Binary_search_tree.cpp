#include<stdio.h>
#include<stdlib.h>

struct node{
	int key;
	struct node *left, *right;
	};
	
struct node *new_Node(int item){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
	}
	
/*void inorder(struct node *root){
	if(root != NULL){
		inorder(root->left);
		printf("%d \n",root->key);
		inorder(root->right);
		}
	}
*/
void storeSorted(node *root, int arr[], int &i){
	if(root!=NULL){
		storeSorted(root->left,arr,i);
		arr[i++] = root->key;
		storeSorted(root->right,arr,i);
		}
	}
	

struct node* insert(struct node* node, int key){
	if(node==NULL)
		return new_Node(key);
	if(key < node->key)
		node->left = insert(node->left,key);
	else if(key > node->key);
		node->right = insert(node->right,key);
	
	return node;
	}
	
void treesort(int arr[], int n){
	struct node *root = NULL;
	
	root = insert(root,arr[0]);
	for(int i=1;i<n;i++)
		insert(root,arr[i]);
	
	int i = 0;
	storeSorted(root,arr,i);
	}

	
int main(){
	int n;
	printf("Enter array size: ");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	//printf("%d\n",arr[1]);
	treesort(arr,n);
	
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
		
	return 0;
	
	}
