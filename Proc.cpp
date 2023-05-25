#include "Proc.h"

bool Memory::compareWords(vector<int> word1, vector<int> word2)
{
    bool g = false;
    bool l = false;
    for (int i = 0; i < word1.size(); i++)
    {
        g = g | (!word2[i] & word1[i] & !l);
        l = l | (word2[i] & !word1[i] & !g);
    }
    if (g == 1 && l == 0)
    {
        return true;
    }
    return false;
}

vector<vector<int>> Memory::getMassive()
{
    return massive;
}

void Memory::getRandomMass()
{
    srand(time(NULL));
    for (int i = 0; i < SIZE_ARRAY; i++){
        vector<int> test_num;
        for (int j = 0; j < SIZE_NUM; j++) {
            test_num.push_back(rand() % 2);
        }
        massive.push_back(test_num);
    }
}

void Memory::sortAscending()
{
    for (int i = 0; i < massive.size(); i++) {
        for (int j = 0; j < massive.size() - i -1 ; j++) {
            if (compareWords(massive[j], massive[j + 1])) {
                vector<int> temp_word = massive[j];
                massive[j] = massive[j + 1];
                massive[j + 1] = temp_word;
            }
        }
    }
}

void Memory::sortDescending()
{
    for (int i = 0; i < massive.size(); i++) {
        for (int j = 0; j < massive.size() - i - 1; j++) {
            if (!compareWords(massive[j], massive[j + 1])) {
                vector<int> temp_word = massive[j];
                massive[j] = massive[j + 1];
                massive[j + 1] = temp_word;
            }
        }
    }
}

Memory Memory::findByBool(string searchedValue)
{
    vector<vector<int>> result;
    for (int i = 0; i < this->massive.size(); i++) {
        bool accept = true;
        for (int j = 0; j < massive[i].size(); j++) {
            char charBit = searchedValue[j];
            if (!(
                (charBit == '1' && massive[i][j]) || 
                (charBit == '0' && !massive[i][j]) || 
                (charBit == 'X')
                )) {
                accept = false;
                break;
            }
        }
        if (accept) {
            result.push_back(massive[i]);
        }
    }
    return Memory(result);
}

Memory::Memory()
{
}

Memory::Memory(vector<vector<int>> massive)
{
    this->massive = massive;
}

