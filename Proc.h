#include <vector>
#include <iostream>
#include <string>
#define SIZE_NUM 8
#define SIZE_ARRAY 10
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
    Memory findByBool(string mask);
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
            os << out_massive[i][j];
        }
        os << endl;
    }
    return os;
}