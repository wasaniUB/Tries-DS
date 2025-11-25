#include <iostream>
#include <fstream>
<<<<<<< HEAD
#include <string>
#include <vector>
#include "trie.h"

using namespace std;

void loadDictionary(Trie &t, const string &filename);
vector<string> getSuggestions(Trie &t, const string &word);

int main() {
   Trie t;

   loadDictionary(t, "dictionary.txt");

   cout << "\n--- Simple Spell Checker ---\n";
   cout << "Type a word or type 'exit' to quit.\n";

   string word;


   while (true) {
         cout << "\nEnter word: ";
         cin >> word;

         if (word == "exit") {
                break;
          }

         if (t.search(word)) {
             cout << "'" << word << "' is spelled correctly.\n";
         } 
       
          else {
             cout << word << "' is NOT in the dictionary.\n";

             vector<string> suggestions = getSuggestions(t, word);
  

             if (!suggestions.empty()) {
                 cout << "Did you mean:\n";
                 for (auto &s : suggestions) {
                     cout << "  -> " << s << "\n";
                 }
             } 
             
               else {
                 cout << "No suggestions found.\n";
             }
         }

   }

     cout << "Thank you and Goodbye!\n";

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


vector<string> getSuggestions(Trie &t, const string &word) {

   vector<string> suggestions;

   //deletes a character
   for (int i = 0; i < word.size(); i++) {
       string attempt = word.substr(0, i) + word.substr(i + 1);
       if (t.search(attempt)) suggestions.push_back(attempt);
   }

   // replaces a character
   for (int i = 0; i < word.size(); i++) {
       for (char c = 'a'; c <= 'z'; c++) {
           string attempt = word;
           attempt[i] = c;
           if (t.search(attempt)) suggestions.push_back(attempt);
       }
   }

   // adds a character
   for (int i = 0; i <= word.size(); i++) {
       for (char c = 'a'; c <= 'z'; c++) {
           string attempt = word.substr(0, i) + c + word.substr(i);
           if (t.search(attempt)) suggestions.push_back(attempt);
       }
   }

   return suggestions;
}
