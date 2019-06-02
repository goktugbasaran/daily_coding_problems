#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <bits/stdc++.h> 
#include <boost/algorithm/string.hpp> 
using namespace std;

// problem:
// given a binary tree
// implement a serializer which serializes the tree into a string
// also, implement a deserializer which turns a string back into a binary tree.

// following test should pass:
// assert deserialize(serialize(root))->left->left->val == 'left.left'


class Node{
    public:
        string val;
        Node* left;
        Node* right;
        Node(string val,Node* left = NULL,Node* right = NULL){
            this->val = val;
            this->left = left;
            this->right = right;
        }
};

// O(n) where n is the node number;
string serialize(Node* root);
// O(n) assuming reverse and split takes O(n)
Node* deserialize(string serialized);

int main(){
    Node* root = new Node("root",new Node("left",new Node("left.left")),new Node("right"));
    
    assert(deserialize(serialize(root))->left->left->val == "left.left");

    return 0;
}

Node* deserialize(string serialized){
    vector<string> result;
    boost::split(result,serialized, boost::is_any_of("-"));
    
    Node* root = new Node(result[0]);
    reverse(result.begin(),result.end());
    result.pop_back();
    queue<Node*> q;
    Node* current = root;
    while(!result.empty()){

        Node* left = new Node(result.back());
        result.pop_back();

        Node *right = new Node(result.back());
        result.pop_back();
        if(left->val != "x"){
            q.push(left);
            current->left = left;}
        else{
            current->left = NULL;
        }
        if(right->val != "x"){
            q.push(right);
            current->right = right;}
        else{
            current->right = NULL;
        }
        if(q.empty()) break;
        current = q.front();
        q.pop();
    }
    return root;
}

string serialize(Node* root){
    queue<Node*> q; 
    q.push(root);
    string serialized = "";
    while(!q.empty()){
        Node* current = q.front();
        if(current == NULL){
            serialized += "x-";
        }
        else{
            serialized += (current->val + "-");
            q.push(current->left);
            q.push(current->right);
        }
        q.pop();
    }
    return serialized;
}
