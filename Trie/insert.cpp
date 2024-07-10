#include <bits/stdc++.h>
using namespace std;

struct TrieNode {

    // pointer array for child nodes of each node
    TrieNode* childNode[26];

    // Used for indicating ending of string
    bool wordEnd;

    TrieNode()
    {
        // constructor
        // initialize the wordEnd variable with false
        // initialize every index of childNode array with
        // NULL
        wordEnd = false;
        for (int i = 0; i < 26; i++) {
            childNode[i] = NULL;
        }
    }
};

void insert_key(TrieNode* root, string& key)
{
    // Initialize the currentNode pointer
    // with the root node
    TrieNode* currentNode = root;

    // Iterate across the length of the string
    for (auto c : key) {

        // Check if the node exist for the current
        // character in the Trie.
        if (currentNode->childNode[c - 'a'] == NULL) {

            // If node for current character does not exist
            // then make a new node
            TrieNode* newNode = new TrieNode();

            // Keep the reference for the newly created
            // node.
            currentNode->childNode[c - 'a'] = newNode;
        }

        // Now, move the current node pointer to the newly
        // created node.
        currentNode = currentNode->childNode[c - 'a'];
    }

    // Increment the wordEndCount for the last currentNode
    // pointer this implies that there is a string ending at
    // currentNode.
    currentNode->wordEnd = 1;
}
