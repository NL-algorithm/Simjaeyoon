#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node* left;//왼쪽자식
    Node* right;//오른자식

    Node(char d) : data(d), left(nullptr), right(nullptr){}
};

void preorder(Node* root){
    if(root==nullptr)return;
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root==nullptr)return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
void postorder(Node* root){
    if(root==nullptr)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    map<char, Node*> nodes;
    for(int i=0; i<n; i++){
        char parent, left, right;
        cin>>parent>>left>>right;

        if(nodes.find(parent)==nodes.end()){
            nodes[parent]=new Node(parent);
        }
        if(left!='.'){
            nodes[parent]->left=new Node(left);
            nodes[left]=nodes[parent]->left;//만든 자식을 map에 저장
        }
        if(right!='.'){
            nodes[parent]->right = new Node(right);
            nodes[right] = nodes[parent]->right;
        }
    }
    preorder(nodes['A']);
    cout<<"\n";
    inorder(nodes['A']);
    cout<<"\n";
    postorder(nodes['A']);

}