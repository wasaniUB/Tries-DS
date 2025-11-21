#include <string>
using namespace std;




struct TrieNode {
    TrieNode* children[26];
    bool isWord;
    TrieNode();
};




class Trie {
private:
    TrieNode* root;
    void clean(TrieNode* tn);
    TrieNode* find(string &s);
    bool deleteHelper(TrieNode* node, string &word, int depth);




public:
    Trie();
    ~Trie();




    void insert(string word);
    bool search(string word);
    bool startWith(string prefix);
    bool remove(string word);
};
