#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    TreeNode* links[26];
    bool end = false;

    TreeNode() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void setKey(char ch) {
        links[ch - 'a'] = new TreeNode;
    }

    TreeNode* getKey(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        end = true;
    }

    bool isEnd() {
        return end;
    }
};

class Trie {
private:
    TreeNode* root;
    TreeNode* node;

public:
    Trie() {
        root = new TreeNode;
    }

    void insert(string word) {
        node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->setKey(ch);
            }
            node = node->getKey(ch);
        }
        node->setEnd();
    }

    bool search(string word) {
        node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->getKey(ch);
        }
        return node->isEnd();
    }

    bool startsWith(string word) {
        node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->getKey(ch);
        }
        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("ahnafshahrear");

    cout << trie.search("ahnaf");
    cout << trie.search("ahnafshahrear");

    cout << trie.startsWith("ahnaf");

    return 0;
}
