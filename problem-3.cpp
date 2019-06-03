#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <bits/stdc++.h> 
#include <boost/algorithm/string.hpp> 



// problem:
// given a binary tree
// implement a serializer which serializes the tree into a string
// also, implement a deserializer which turns a string back into a binary tree.

// following test should pass:
// assert deserialize(serialize(root))->left->left->val == 'left.left'


class Node{
    public:
        std::string val;
        Node* left;
        Node* right;
        Node(std::string val,Node* left = NULL,Node* right = NULL){
            this->val = val;
            this->left = left;
            this->right = right;
        }
};

// O(n) where n is the node number;
std::string serialize(Node* root);
// O(n) assuming reverse and split takes O(n)
Node* deserialize(std::string serialized);

int main(){
    Node* root = new Node("root",new Node("left",new Node("left.left")),new Node("right"));
    
    assert(deserialize(serialize(root))->left->left->val == "left.left");

    return 0;
}

Node* deserialize(std::string serialized){
    std::vector<std::string> result;
    boost::split(result,serialized, boost::is_any_of("-"));
    
    Node* root = new Node(result[0]);
    reverse(result.begin(),result.end());
    result.pop_back();
    std::queue<Node*> q;
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

std::string serialize(Node* root){
    std::queue<Node*> q; 
    q.push(root);
    std::string serialized = "";
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
