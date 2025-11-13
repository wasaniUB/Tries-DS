#include <iostream>
#include <fstream>
#include "Trie.h"
using namespace std;


void loadDictionary(Trie &t, const string &filename);


int main() {
    Trie t;




    t.insert("cat");
    t.insert("car");
    t.insert("dog");




    cout << (t.search("cat") ? "Found\n" : "Not Found\n");
    cout << (t.search("cap") ? "Found\n" : "Not Found\n");




    cout << (t.startWith("ca") ? "Prefix Found\n" : "No Prefix\n");




    t.remove("car");
    cout << (t.search("car") ? "Found\n" : "Not Found\n");
    
     loadDictionary(t, "dictionary.txt");




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


