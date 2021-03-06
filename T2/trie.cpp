// C++ implementation of search and insert 
// operations on Trie 
#include <bits/stdc++.h> 
using namespace std; 
  
const int ALPHABET_SIZE = 26; 
  
// trie node 


struct TrieNode {
    char letter;        //opcional
    TrieNode* children[ALPHABET_SIZE]; 
    unsigned long posicao;
    unsigned long comprimento;  //se maior que zero, indica último caracter de uma palavra
    bool isEndOfWord;

};
// Returns new trie node (initialized to NULLs) 
TrieNode* newNode(char l) 
{
    auto* pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false;
    pNode->letter = l;
    pNode->posicao = 0;
    pNode->comprimento = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
  
TrieNode* insert(TrieNode* root, std::string data)
{
    auto* temp = root;

    for (auto i = 0; i != data.length(); i++)
    {
        auto index = data[i] - 'a';
        if (temp->children[index] == NULL)
            temp->children[index] = newNode(data[i]);

        // iterate over the recently added node//std::list<char> children[ALPHABET_SIZE];   //pode ser uma 'LinkedList' de ponteiros
        temp = temp->children[index];
    }
    temp->isEndOfWord = true;
    return temp->children[data.length()-1];
}
  
// Returns true if key presents in trie, else 
// false 
bool search(TrieNode* root, std::string data) 
{ 
    auto* temp = root;

    for (auto i = 0; i != data.length(); i++)
    {
        auto index = data[i] - 'a';
        if (temp->children[index] == NULL)
            return false;

        // iterate over the recently added node
        temp = temp->children[index];
    }
  
    return (temp != NULL && temp->isEndOfWord); 
}

  