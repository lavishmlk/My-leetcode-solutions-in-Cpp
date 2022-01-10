// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/*  Structure of a Binary Tree

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
// KNK
class Solution {
  public:
    // Function to get height of a tree.
    int height(Node* node) {
        // if node is null, we return 0.
        if (node == NULL) return 0;

        // else we call the function height recursively for left and right
        // subtrees of the parent node and store their maximum.
        else {
            int lHeight = height(node->left);
            int rHeight = height(node->right);
            return (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);
        }
    }

  public:
    // Function to get width of a given level.
    int getWidth(Node* root, int level) {

        if (root == NULL) return 0;

        // if level is 1, we return 1.
        if (level == 1) return 1;

        // else if it is greater than one, we call the getWidth function
        // recursively for left and right subtrees of parent node and add them.
        else if (level > 1)
            return getWidth(root->left, level - 1) +
                   getWidth(root->right, level - 1);
    }

  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {
        int maxWidth = 0;
        int width;
        int h = height(root);
        int i;

        // getting width of each level and comparing the width
        // with maximum width so far.
        for (i = 1; i <= h; i++) {
            width = getWidth(root, i);
            if (width > maxWidth) maxWidth = width;
        }

        // returning the maximum width.
        return maxWidth;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        string inp;
        getline(cin, inp);
        Node* root = buildTree(inp);

        Solution ob;
        cout << ob.getMaxWidth(root) << endl;
    }
    return 0;
}
  // } Driver Code Ends