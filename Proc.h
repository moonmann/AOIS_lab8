#pragma once
#include <vector>
#include <iostream>
#include <string>
#define SIZE_MASSIVE 16
using namespace std;

class Memory
{
private:
    vector<vector<int>> massive;
    bool compareWords(vector<int> word1, vector<int> word2);
public:
    vector<vector<int>> getMassive();
    void getRandomMass();
    void sortAscending();
    void sortDescending();
    vector<int> getWord(int num);
    void setWord(vector<int> word, int num);
    vector<vector<int>> getNormalMatrix();
    vector<vector<int>> getDiagonalMatrix(vector<vector<int>> normal_matrix);
    vector<int> fun_4(int num1, int num2, int num3);
    vector<int> fun_6(int num1, int num2, int num3);
    vector<int> fun_9(int num1, int num2, int num3);
    vector<int> fun_11(int num1, int num2, int num3);
    void sum(vector<int> V);
    vector<int> sumWords(vector<int> word1, vector<int> word2);
    Memory();
    Memory(vector<vector<int>> massive);
};

inline ostream& operator<<(ostream& os, Memory m)
{
    vector<vector<int>> out_massive = m.getMassive();
    for (int i = 0; i < out_massive.size(); i++)
    {
        for (int j = 0; j < out_massive[i].size(); j++)
        {
            os << out_massive[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

inline ostream& operator<<(ostream& os, vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        os << vec[i] << " ";
    }
    return os;
}