#include <bits/stdc++.h>
using namespace std;

struct Trie {
    Trie* child[3];
    bool isEnd;

    Trie() {
        for(int i = 0; i < 3; i++) child[i] = NULL;
        isEnd = false;
    }
};

void insert(Trie* root, string &s) {
    Trie* node = root;
    for(char c : s) {
        int idx = c - 'a'; // only 'a','b','c'
        if(!node->child[idx]) node->child[idx] = new Trie();
        node = node->child[idx];
    }
    node->isEnd = true;
}

bool dfs(Trie* node, string &s, int pos, bool diffUsed) {
    if(pos == s.size()) {
        return node->isEnd && diffUsed;
    }

    int curr = s[pos] - 'a';

    for(int i = 0; i < 3; i++) {
        if(node->child[i]) {
            if(i == curr) {
                if(dfs(node->child[i], s, pos + 1, diffUsed))
                    return true;
            } else if(!diffUsed) {
                if(dfs(node->child[i], s, pos + 1, true))
                    return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    Trie* root = new Trie();

    vector<string> words(n);
    for(int i = 0; i < n; i++) {
        cin >> words[i];
        insert(root, words[i]);
    }

    while(m--) {
        string query;
        cin >> query;

        if(dfs(root, query, 0, false))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}