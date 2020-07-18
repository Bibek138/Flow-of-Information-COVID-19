#include<iostream>
using namespace std;
struct Node
{
 char key;
 Node *left;
 Node *right;
};
//function represents the creation of a new node//
Node *createNode(char ch)
{
 Node *node=new Node();
 node->key=ch;
 node->left=NULL;
 node->right=NULL;
 return node;
}
//function to get the count of leaf nodes //
unsigned int LeafCount(struct Node *node)
{
if(node==NULL)
    return 0;
 if(node->left==NULL && node->right==NULL)
    return 1;
 else
    return LeafCount(node->left)+LeafCount(node->right);
}
//function to get the count of half nodes//
unsigned int HalfCount(struct Node *root)
{
 if(root==NULL)
    return 0;
 int res=0;
 if((root->left==NULL && root->right!=NULL) || (root->left!=NULL && root->right==NULL))
    res++;

 res=res+(HalfCount(root->left)+HalfCount(root->right));
 return res;
}
//function to get the count of full nodes
unsigned int FullCount(struct Node *root)
{
 if(root==NULL)
    return 0;
 int res=0;
 if(root->left && root->right)
    res++;
 res=res+(FullCount(root->left)+FullCount(root->right));
 return res;
}
int main()
{
 cout<<"The Command and Control structure for the flow of Information during COVID-19 . "<<endl;
 cout<<endl;
 cout<<"These are the characters which represent the Adminstrative Authorities of India :"<<endl;
 cout<<endl;
 cout<<" A= Government of India(The Prime Minister)"<<endl;
 cout<<" B= Goverment of States(The Chief Minister)"<<endl;
 cout<<" C= Head of Union Territories(The Chief Minister)"<<endl;
 cout<<" D= Head of District(District Collector)"<<endl;
 cout<<" E= Head of District of Union territories "<<endl;
 cout<<" F= Head of Block(The BDO)"<<endl;
 cout<<" G= Head of Muncipalty"<<endl;
 cout<<" H= Head of Village of Union territories"<<endl;
 cout<<" I= Head of Muncipalty "<<endl;
 cout<<" J= Head of GramaPancayat(The Sarapanch)"<<endl;
 cout<<" K= Head of Village(Ward Member)"<<endl;
 cout<<endl;
 Node *root=createNode('A');
 cout<<"                    "<<root->key<<endl;
 root->left=createNode('B');
 cout<<"              "<<root->left->key;
 root->right=createNode('C');
 cout<<"            "<<root->right->key<<endl;
 root->left->left=createNode('D');
 cout<<"         "<<root->left->left->key;
 root->right->left=createNode('E');
 cout<<"             "<<root->right->left->key<<endl;
 root->left->left->left=createNode('F');
 cout<<"     "<<root->left->left->left->key;
 root->left->left->right=createNode('G');
 cout<<"      "<<root->left->left->right->key;
 root->right->left->left=createNode('H');
 cout<<"       "<<root->right->left->left->key;
 root->right->left->right=createNode('I');
 cout<<"    "<<root->right->left->right->key<<endl;
 root->left->left->left->left=createNode('J');
 cout<<"  "<<root->left->left->left->left->key<<endl;
 root->left->left->left->left->left=createNode('K');
 cout<<""<<root->left->left->left->left->left->key<<endl;
 cout<<"Total no of nodes having degree 2 is = "<<FullCount(root)<<endl;
 cout<<"Total no of nodes having degree 1 is = "<<HalfCount(root)<<endl;
 cout<<"Total no of nodes having degree 0 is = "<<LeafCount(root)<<endl;
 return 0;
}
