#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
private:
    TrieNode* root;

    bool isEmpty(TrieNode* node) {
        for(int i = 0; i < 26; i++) {
            if(node->children[i] != NULL)
                return false;
        }
        return true;
    }

    TrieNode* deleteHelper(TrieNode* node, string &word, int depth) {
        if(!node) return NULL;

        if(depth == word.size()) {
            if(node->isEnd)
                node->isEnd = false;

            if(isEmpty(node)) {
                delete node;
                return NULL;
            }
            return node;
        }

        int idx = word[depth] - 'a';
        node->children[idx] = deleteHelper(node->children[idx], word, depth + 1);

        if(isEmpty(node) && node->isEnd == false) {
            delete node;
            return NULL;
        }

        return node;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for(char c : word) {
            int idx = c - 'a';
            if(node->children[idx] == NULL) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for(char c : word) {
            int idx = c - 'a';
            if(node->children[idx] == NULL)
                return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c : prefix) {
            int idx = c - 'a';
            if(node->children[idx] == NULL)
                return false;
            node = node->children[idx];
        }
        return true;
    }

    void remove(string word) {
        deleteHelper(root, word, 0);
    }
};