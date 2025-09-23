#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

class Node {
private:
    Node* links[26];
    bool flag;
public:
    Node() {
        for (int i = 0; i < 26; i++)
            this->links[i] = nullptr;
        this->flag = false;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void set(char ch) {
        links[ch - 'a'] = new Node();
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    bool getEnd() {
        return this->flag;
    }

    void setEnd() {
        this->flag = true;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->set(word[i]);
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->getEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->containsKey(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main() {
    file();

    /*
        Problem Description:
        Implement the Trie data structure with the following methods:
        1) Insert
        2) Search
        3) StartsWith

        Input:
        The input start with n - the number of commands.
        The follwing n lines contains command of three types:
            1 word (for insert)
            2 word (for search)
            3 word (for startswith)
    */
    int n;
    cin >> n;

    Trie trie;

    while (n--) {
        int c;
        string s;
        cin >> c >> s;
        if (c == 1) {
            trie.insert(s);
        } else if (c == 2) {
            cout << trie.search(s) << endl;
        } else {
            cout << trie.startsWith(s) << endl;
        }
    }

    return 0;
}