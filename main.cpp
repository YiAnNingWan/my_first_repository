#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *l,*r;/*l为左子树，r为右子树*/
}; 
void PreOrder(node *root){/*前序序列*/
	if(root==NULL) return;
	else{
		cout<<root->data;
		PreOrder(root->l);
		PreOrder(root->r);
	}
}
void InOrder(node *root){/*中序序列*/
	if(root==NULL) return;
	else{
		InOrder(root->l);
		cout<<root->data;
		InOrder(root->r);
	}
}
void PostOrder(node *root){/*后序序列*/
	if(root==NULL) return;
	else{
		PostOrder(root->l);
		PostOrder(root->r);
		cout<<root->data;
	}
}
node *create(){/*生成二叉树*/ 
	node *root=NULL;
	int x;
	cin>>x;
	if(x==0) root=NULL;
	else{
		root=new node;
		root->data=x;
		root->l=create();
		root->r=create();
	}
	return root;
}
int Leaf(node *root){/*二叉树的叶子节点数*/
	int L,R;
	if(root==NULL)return 0;
	if(root->l==NULL&&root->r==NULL) return 1;
	else{
		L=Leaf(root->l);
		R=Leaf(root->r);
	}
	return L+R;
}
int Depth(node *root){/*二叉树的深度*/
	int L=0,R=0;
	if(root==NULL)return 0;
	else{
		L=Depth(root->l);
		R=Depth(root->r);
	}
	return max(L,R)+1;/*(L>R)?L+1:R+1*/
}
void Level(node *root){
	node *Q[100],*q=NULL;
	int front =-1,rear=-1;
	if(root==NULL)return;
	else{
		Q[++rear]=root;
	}
	while(front!=rear){/*循环队列*/
		q=Q[++front];
		cout<<q->data;
		if(q->l!=NULL)Q[++rear]=q->l;
		if(q->r!=NULL)Q[++rear]=q->r;
	}
	return;
}
int main(void){
	cout<<"请输入二叉树的前序序列构建二叉树："; 
	node *root=create();
	cout<<"二叉树的前序序列为：";
	PreOrder(root);
	cout<<"\n";
	cout<<"二叉树的中序序列为：";
	InOrder(root);
	cout<<"\n";
	cout<<"二叉树的后序序列为：";
	PostOrder(root);
	cout<<"\n";
	cout<<"二叉树的叶子结点数为："<<Leaf(root)<<"个\n";
	cout<<"二叉树的深度为："<<Depth(root)<<"层\n";
	cout<<"二叉树的层序遍历为：";
	Level(root);
	cout<<"\n"; 
	return 0;
}
