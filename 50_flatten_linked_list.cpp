/*
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)

Approach 1: traverse through linked till last lined list 
          Start merging two linked list and return its root
          Time complexity: O(N*N*M).....N = total no of nodes using next/right pointer, M = no of nodes using bottom pointer
          Space complexity: O(1)

Approach 2: Using priority queue
           Time complexity: O(N*M*log(N))
           Space complexity; O(N)
           
           struct cmp
           {
              bool operator()(Node* a, Node* b)
              {
                return a->data > b->data;
              }
           }
           priority_queue<Node* ,vector<Node*>,cmp>p;
           
           void flatten(Node *root)
           {
              while(root!=NULL)
              {
                 p.push(root);
                 root=root->next;
              }
              while(!p.empty())
              {
                 auto k = p.top();
                 p.pop();
                 cout<<k->data;
                 if(k->bottom)
                 {
                    p.push(k->bottom);
                 }
              }
           }
                 
                        
*/

// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
 Node* mergeTwoLists(Node* a, Node* b){
     Node* temp= new Node (0);
     Node* res= temp;
     
     while ( a!= NULL && b!= NULL){
         if ( a->data< b->data){
             temp-> bottom=a;
             temp= temp-> bottom;
             a= a-> bottom;
         }
         else{
             temp-> bottom =b;
             temp= temp-> bottom;
             b=b->bottom;
         }
     }
     if ( a)
     temp-> bottom =a;
     else{
         temp-> bottom =b;
         
         
     }
     return res-> bottom;
 }   
Node *flatten(Node *root)
{
   // Your code here
   if ( root == NULL || root-> next ==NULL)
    return root;
   root ->next= flatten ( root->next); //to reach last node
   root = mergeTwoLists( root , root->next ); //to merge
   
   return root;
   
}


