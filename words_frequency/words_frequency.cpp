#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>




//================================================FUNCTIONS========================================================
std::string prepare          (const std::string& str);

std::map<std::string, int> getWordsFreq(const std::string& fileName);

std::string deletePunctuation(const std::string& str);
std::string strToLower       (const std::string& str);

int sortedOutput(const std::map<std::string, int>& map);
//=================================================================================================================






int main(int argc, char ** argv)
{
    if (argc != 2)
    {
        std::cout << "It is necessary to give 1 argument (the file name)" << std::endl;
        
        exit(-1);
    }
    
    std::map<std::string, int> wordsFrequency = getWordsFreq(argv[1]);
    sortedOutput(wordsFrequency);
    
    return 0;
}





std::map<std::string, int> getWordsFreq(const std::string& fileName)
{
    std::ifstream file(fileName);
    
    if (!file.is_open())
    {
        std::cout << "cannot open file " << fileName << ". May be it does not exist" << std::endl;
        
        exit(-1);
    }
    
    std::string word;
    std::map<std::string, int> wordsFrequency;
    
    while (!file.eof())
    {
        file >> word;
        word = prepare(word);
        
        wordsFrequency[word]++;
    }
    
    file.close();
    
    return wordsFrequency;
}

std::string strToLower(const std::string& str)
{
    std::string cstr(str);
    
    std::transform(cstr.begin(), cstr.end(), cstr.begin(), ::tolower);
    
    return cstr;
}

std::string deletePunctuation(const std::string& str)
{
    std::string cstr(str);
    
    while (!isalpha(cstr.back()))
    {
        cstr.pop_back();
    }
    
    return cstr;
}

std::string prepare (const std::string& str)
{
    std::string result(str);
    
    result = strToLower       (result);
    result = deletePunctuation(result);
    
    return result;
}



struct frequency
{
    int count;
    std::string str;
    
    bool operator<(const frequency& freq) const
    {
        return count < freq.count;
    }
};

int sortedOutput(const std::map<std::string, int>& map)
{
    int mapSize = map.size();
    
    std::vector<frequency> freq;
    freq.resize(mapSize);
    
    int i = 0;
    for (auto it : map)
    {
        freq[i].str   = it.first;
        freq[i].count = it.second;
        
        i++;
    }
    
    std::sort(freq.begin(), freq.end());
    
    for (int i = mapSize - 1; i >= 0; i--)
    {
        std::cout << freq[i].str << " " << freq[i].count << std::endl;
    }
    
    return 0;
}
