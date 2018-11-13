#include <iostream>
#include <fstream>
#include <vector>
#include <list>


int main() {
    
    std::string filename;
    std::string word;
    std::vector<std::string> vetor;

    std::cin >> filename;  // entrada

    std::fstream file(filename);

    std::cout << filename << std::endl;  // esta linha deve ser removida
    
    while (1) {  // leitura das palavras ate' encontrar "0"
        std::cin >> word;
        if (word.compare("0") == 0) {
            break;
        }
        //std::cout << word << endl;
        vetor.push_back(word);
    }
    for (auto x : vetor) {
        std::cout << "coco" << x << "p" <<std::endl;
    }


    return 0;
}
