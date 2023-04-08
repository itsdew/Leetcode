//Author: Devendra Uraon 
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        vector<Node *> v1;
        for(int i = 0; i < 101; i++){
            Node *temp = new Node();
            v1.push_back(temp);
        }
        vector<int> visited(101, 0);
        queue<Node *> q1;
        q1.push(node);
        visited[node -> val] = 1;
        v1[node -> val] -> val = node -> val;
        while(q1.size() > 0){
            Node * temp = q1.front();
            q1.pop();
            for(auto x : temp -> neighbors){
                if(!visited[x -> val]){
                    q1.push(x);
                    visited[x -> val] = 1;
                }
                v1[x -> val] -> val = x -> val;
                v1[temp -> val]->neighbors.push_back(v1[x -> val]);
            }
        }
        return v1[node -> val];
    }
};
