#include <iostream>
#include <fstream>
#include <vector>
#include <list>

#include "trie.cpp"

void parse_lib(TrieNode& tree, std::string path);

int main() {
    
    std::string filename;
    
    // entrada
    auto tree = newNode('.');
    std::cin >> filename;

    parse_lib(tree, filename);

    std::string word;
    
    while (1) {  // leitura das palavras ate' encontrar "0"
        std::cin >> word;
        if (word.compare("0") == 0) {
            break;
        }
        //std::cout << word << endl;
        // vetor.push_back(word);
    }
    

    return 0;
}

void parse_lib(TrieNode*& tree, std::string path)
{
    std::fstream file(path);
    std::string line;
    auto size = 0;
    while (std::getline(file, line))
    {
        auto word = "";
        size = line.size();
        for (int i = 1; i != line.size(); i++)
        {
            if (line.at(i) == ']')
                break;
            word = word + line.at(i);
        }
        insert(tree, word);
        
    }
}