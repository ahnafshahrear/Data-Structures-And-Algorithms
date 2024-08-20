#include <bits/stdc++.h>

using namespace std;

//... Struct TrieNode represents a node in a Trie data structure.
struct TrieNode {
    TrieNode* links[26]; //... Pointers to child nodes corresponding 'a' to 'z'
    bool end = false; //... Flag to indicate the end of a word

    TrieNode() {
        //... Initialize all child pointers to nullptr
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }

    //... Checks if the current node contains a child node corresponding to the given character
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    //... Creates a new child node corresponding to the given character
    void setKey(char ch) {
        links[ch - 'a'] = new TrieNode;
    }

    //... Retrieves the child node corresponding to the given character
    TrieNode* getKey(char ch) {
        return links[ch - 'a'];
    }

    //... Marks the current node as the end of a word
    void setEnd() {
        end = true;
    }

    //... Checks if the current node is end of a word
    bool isEnd() {
        return end;
    }
};

class Trie {
private:
    TrieNode* root;
    TrieNode* node; 

public:
    Trie() {
        root = new TrieNode;
    }

    //... Inserts a word into the Trie
    void insert(string word) {
        node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->setKey(ch);
            }
            node = node->getKey(ch);
        }
        node->setEnd(); //... Mark the end of the word
    }

    //... Searches for an exact match of the word in the Trie
    bool search(string word) {
        node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->getKey(ch);
        }
        return node->isEnd(); //... Check if the final node is the end of a word
    }

    //... Checks if there is any word in the Trie that starts with the given word as a prefix
    bool startsWith(string word) {
        node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->getKey(ch);
        }
        return true; //... Means all characters are found
    }
};
//... Time Complexity of insert, search & prefix-search is O[n] where n is the size of the word 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie trie; //... An object of the Trie class

    trie.insert("ahnafshahrear"); //... Inserting a word into the trie

    cout << trie.search("ahnaf"); //... Exact word search
    cout << trie.search("ahnafshahrear");

    cout << trie.startsWith("ahnaf"); //... Prefix search

    return 0;
}

//... Ahnaf Shahrear Khan
//... Department of Computer Science & Engineering, University of Rajshahi
//... Gmail: ahnafshahrearkhan@gmail.com
//... GitHub: https://github.com/ahnafshahrear
