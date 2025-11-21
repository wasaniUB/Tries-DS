#include <iostream>
#include <string>
#include "trie.h"

using namespace std;

void loadDictionary(Trie &t, const string &filename);
int main() {

    Trie t;

      loadDictionary(t, "dictionary.txt");

      string word;
      getline(cin, word);

      if(t.search(word)) {
          cout << " Word is spelled correctly.\n";
      }

      else{ 
           cout << " Word is spelled incorrectly.\n";
      }
    
return 0;

}

void loadDictionary(Trie &t, const string &filename){
    ifstream file(filename);
   
      if (!file.is_open()) {
 
        cout << "Error: Could not open dictionary file.\n";
         return;
     }

     string word;
         while (file >> word) {
          t.insert(word);
        }
        file.close();

      cout << "Dictionary loaded successfully!\n";

  }