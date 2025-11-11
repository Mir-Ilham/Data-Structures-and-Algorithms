#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#include <bits/stdc++.h> 

class Node {
    private:
    Node* links[26];
    int cntEndWith, cntPrefix;

    public:
    Node() {
        for (int i = 0; i < 26; i++)
            this->links[i] = nullptr;
        this->cntEndWith = 0;
        this->cntPrefix = 0;
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

    int getEnd() {
        return cntEndWith;
    }

    int getPrefix() {
        return cntPrefix;
    }

    void increaseEnd() {
        cntEndWith++;
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void reduceEnd() {
        cntEndWith--;
    }

    void reducePrefix() {
        cntPrefix--;
    }
};

class Trie{
    private:
    Node* root;

    public:

    Trie(){
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->set(word[i]);
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i]))
                return 0;
            node = node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i]))
                return 0;
            node = node->get(word[i]);
        }
        return node->getPrefix();
    }

    void erase(string &word){
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i]))
                break;

            node = node->get(word[i]);
            node->reducePrefix();
        }
        return node->reduceEnd();
    }
};

int main() {
    file();

    /*
        Problem Description:
        Implement the Trie data structure with the following methods:
        1) insert
        2) countWordsEqualTo
        3) countWordsStartingWith
        4) erase

        Input:
        The input start with n - the number of commands.
        The follwing n lines contains command of four types:
            1 word (for insert)
            2 word (for countWordsEqualTo)
            3 word (for countWordsStartingWith)
            4 word (for erase)
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
            cout << trie.countWordsEqualTo(s) << endl;
        } else if (c == 3) {
            cout << trie.countWordsStartingWith(s) << endl;
        } else {
          trie.erase(s);
        }
    }

    return 0;
}