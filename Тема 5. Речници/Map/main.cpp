#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>

int findNumberOfWords(std::string t1, std::string t2) {
    std::unordered_map<std::string, bool> words;

    std::vector<std::string> t1Words;
    char *token = strtok(const_cast<char*>(t1.c_str()), " ");
    while (token != nullptr)
    {
        t1Words.push_back(token);
        token = strtok(nullptr, " ");
    }

    for(std::string word : t1Words) {
        words[word] = true;
    }

    std::vector<std::string> t2Words;
    char *token2 = strtok(const_cast<char*>(t2.c_str()), " ");
    while (token2 != nullptr)
    {
        t2Words.push_back(token2);
        token2 = strtok(nullptr, " ");
    }

    int sum = 0;
    for(std::string word : t2Words) {
        if(words[word] == true) {
            sum++;
        }
    }

    return sum;
}

std::string mostPopularWord(std::string text){
    std::vector<std::string> t1Words;
    char *token = strtok(const_cast<char*>(t1.c_str()), " ");
    while (token != nullptr)
    {
        t1Words.push_back(token);
        token = strtok(nullptr, " ");
    }


}

int main() {
    std::cout << findNumberOfWords("t t t e e a", "t t t t t f e") << std::endl;
    return 0;
}
