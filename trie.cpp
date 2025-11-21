#include "trie.h"
#include <iostream>
#include <fstream>
#include <cctype>   

TrieNode::TrieNode() {
    for (int i = 0; i < 26; i++)
        children[i] = nullptr;
    isWord = false;
}

void Trie::clean(TrieNode* tn) {
    for (int i = 0; i < 26; i++) {
        if (tn->children[i])
            clean(tn->children[i]);
    }
    delete tn;
}


TrieNode* Trie::find(string &s) {
    TrieNode* tn = root;


    for (char c : s) {
        if (!isalpha(c))
            return nullptr;


        c = tolower(c);
        int index = c - 'a';


        if (index < 0 || index > 25)
            return nullptr;


        if (!tn->children[index])
            return nullptr;


        tn = tn->children[index];
    }
    return tn;
}


bool Trie::deleteHelper(TrieNode* node, string &word, int depth) {
    if (!node)
        return false;


    if (depth == word.size()) {
        if (!node->isWord)
            return false;


        node->isWord = false;


        for (int i = 0; i < 26; i++)
            if (node->children[i])
                return false;


        return true;
    }


    char c = word[depth];


    if (!isalpha(c))
        return false;


    c = tolower(c);
    int index = c - 'a';


    if (index < 0 || index > 25)
        return false;


    if (deleteHelper(node->children[index], word, depth + 1)) {
        delete node->children[index];
        node->children[index] = nullptr;


        if (!node->isWord) {
            for (int i = 0; i < 26; i++)
                if (node->children[i])
                    return false;


            return true;
        }
    }
    return false;
}


Trie::Trie() {
    root = new TrieNode();
}


Trie::~Trie() {
    clean(root);
}


void Trie::insert(string word) {
    TrieNode* tn = root;


    for (char c : word) {
        if (!isalpha(c))
            continue;


        c = tolower(c);
        int index = c - 'a';


        if (index < 0 || index > 25)
            continue;


        if (!tn->children[index])
            tn->children[index] = new TrieNode();


        tn = tn->children[index];
    }


    tn->isWord = true;
}


bool Trie::search(string word) {
    TrieNode* end = find(word);
    return (end && end->isWord);
}


bool Trie::startWith(string prefix) {
    return (find(prefix) != nullptr);
}


bool Trie::remove(string word) {
    return deleteHelper(root, word, 0);
}





