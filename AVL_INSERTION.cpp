#include<bits/stdc++.h>
using namespace std;
#define gc getchar
#define ll long long
#define v vector
#define pr pair<int,int>
#define sd second
#define ft first
#define pb push_back
#define mp make_pair
#define total 400000
#define pie 3.1415926535897932
struct node
{
    int val,h=0;
    node *left=NULL,*right=NULL;
};
int get_height(node *root)
{
    if(root==0)
    {
        return -1;
    }
    else
        return root->h;
}
void new_heights(node * root)
{
    root->h=max(get_height(root->left),get_height(root->right))+1;
}
node * left_problem(node * root)
{
    if( get_height(root->left->left) > get_height(root->left->right))
    {
        node * temp=root->left;
        root->left = root->left->right;
        temp->right= root;
        new_heights(root);
        new_heights(temp);
        return temp;
    }
    else
    {
        //left-right problem into left-left
        node * temp=root->left;
        root->left=root->left->right;
        temp->right=root->left->left;
        root->left->left=temp;
        new_heights(root->left->left);
        new_heights(root->left);
        new_heights(root);

        temp=root->left;
        root->left = temp->right;
        temp->right= root;
        new_heights(root);
        new_heights(temp);
        return temp;

    }
}
node * right_problem(node * root)
{
    if((get_height(root->right->right)) > get_height(root->right->left))
    {
        node *temp=root->right;
        root->right=temp->left;
        temp->left=root;
        new_heights(root);
        new_heights(temp);
        return temp;
    }
    else
    {
        //right-left problem into right-right problem
        node * temp=root->right;
        root->right=temp->left;
        temp->left=root->right->right;
        root->right->right=temp;
        new_heights(root->right->right);
        new_heights(root->right);
        new_heights(root);

        temp=root->right;
        root->right=temp->left;
        temp->left=root;
        new_heights(root);
        new_heights(temp);
        return temp;
    }

}
node * myinsert(node * root,int x)
{
    if(root==NULL)
    {
        root=new node();
        root->val=x;
        return root;
    }
    if(x<root->val)
    {
        node * temp=myinsert(root->left,x);
        root->left=temp;
        if(abs(get_height(root->left)-get_height(root->right))>1)
        {
            root=left_problem(root);
        }
        new_heights(root);
        return root;
    }
    else
    {
        node * temp=myinsert(root->right,x);
        root->right=temp;
        if(abs(get_height(root->left)-get_height(root->right))>1)
        {
            root=right_problem(root);
        }
        new_heights(root);
        return root;
    }
}
void inorder(node * root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->val<<","<<root->h<<" ";
    inorder(root->right);
}
int main()
{
    ios::sync_with_stdio(false);
    int i,j,k,t,n,x;
    cout<<"number of nodes"<<endl;
    node *root=NULL;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        root=myinsert(root,x);
    }
    inorder(root);
    return 0;
}
