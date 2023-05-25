#include "Proc.h"

bool Memory::compareWords(vector<int> word1, vector<int> word2)
{
    for (int i = 0; i < word1.size(); i++)
    {
        if (word1[i] == 1 && word2[i] == 0) return true;
        else if (word2[i] == 1 && word1[i] == 0)    return false;
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
    for (int i = 0; i < SIZE_MASSIVE; i++) {
        vector<int> test_num;
        for (int j = 0; j < SIZE_MASSIVE; j++) {
            test_num.push_back(rand() % 2);
        }
        massive.push_back(test_num);
    }
}

void Memory::sortAscending()
{
    for (int i = 0; i < this->massive.size(); i++) {
        for (int j = 0; j < this->massive.size() - i - 1; j++) {
            vector<int> word1 = this->getWord(j);
            vector<int> word2 = this->getWord(j + 1);
            if (compareWords(word1, word2)) {
                vector<int> temp_word = word1;
                this->setWord(word2, j);
                this->setWord(temp_word, j + 1);
            }
        }
    }
}

void Memory::sortDescending()
{
    for (int i = 0; i < this->massive.size(); i++) {
        for (int j = 0; j < this->massive.size() - i - 1; j++) {
            vector<int> word1 = this->getWord(j);
            vector<int> word2 = this->getWord(j + 1);
            if (!compareWords(word1, word2)) {
                vector<int> temp_word = word1;
                this->setWord(word2, j);
                this->setWord(temp_word, j + 1);
            }
        }
    }
}

vector<int> Memory::getWord(int num)
{
    vector<int> word;
    for (int i = num; i < this->massive.size(); i++)
    {
        word.push_back(this->massive[i][num]);
    }
    for (int i = 0; i < num; i++)
    {
        word.push_back(this->massive[i][num]);
    }
    return word;
}

void Memory::setWord(vector<int> word, int num)
{
    int wordBit = 0;
    for (int i = num; i < this->massive.size(); i++, wordBit++)
    {
        massive[i][num] = word[wordBit];
    }
    for (int i = 0; i < num; i++, wordBit++)
    {
        massive[i][num] = word[wordBit];
    }
}

vector<vector<int>> Memory::getNormalMatrix()
{
    vector<vector<int>> massive;
    for (int i = 0; i < this->massive.size(); i++)
    {
        massive.push_back(this->getWord(i));
    }
    return massive;
}

vector<vector<int>> Memory::getDiagonalMatrix(vector<vector<int>> normal_matrix)
{
    for (int i = 0; i < normal_matrix.size(); i++)
    {
        this->setWord(normal_matrix[i], i);
    }
    return this->massive;
}

vector<int> Memory::fun_4(int num1, int num2, int num3)
{
    vector<int> word1 = this->getWord(num1);
    vector<int> word2 = this->getWord(num2);
    vector<int> result;
    for (int i = 0; i < word1.size(); i++)
    {
        result.push_back(!word1[i] * word2[i]);
    }
    this->setWord(result, num3);
    return result;
}

vector<int> Memory::fun_6(int num1, int num2, int num3)
{
    vector<int> word1 = this->getWord(num1);
    vector<int> word2 = this->getWord(num2);
    vector<int> result;
    for (int i = 0; i < word1.size(); i++)
    {
        result.push_back((!word1[i] * word2[i]) + (word1[i] * !word2[i]));
    }
    this->setWord(result, num3);
    return result;
}

vector<int> Memory::fun_9(int num1, int num2, int num3)
{
    vector<int> word1 = this->getWord(num1);
    vector<int> word2 = this->getWord(num2);
    vector<int> result;
    for (int i = 0; i < word1.size(); i++)
    {
        result.push_back((word1[i] * word2[i]) + (!word1[i] * !word2[i]));
    }
    this->setWord(result, num3);
    return result;
}

vector<int> Memory::fun_11(int num1, int num2, int num3)
{
    vector<int> word1 = this->getWord(num1);
    vector<int> word2 = this->getWord(num2);
    vector<int> result;
    for (int i = 0; i < word1.size(); i++)
    {
        result.push_back(word1[i] + !word2[i]);
    }
    this->setWord(result, num3);
    return result;
}

void Memory::sum(vector<int> V)
{
    for (int i = 0; i < this->massive.size(); i++)
    {
        vector<int> Vj;
        vector<int> temp_word = this->getWord(i);
        for (int j = 0; j < 3; j++)
        {
            Vj.push_back(temp_word[j]);
        }
        if (Vj == V)
        {
            vector<int> Aj;
            vector<int> Bj;
            for (int k = 3; k < 7; k++)
            {
                Aj.push_back(temp_word[k]);
            }
            for (int k = 7; k < 11; k++)
            {
                Bj.push_back(temp_word[k]);
            }
            vector<int> Sj = this->sumWords(Aj, Bj);
            for (int k = 11; k < 16; k++)
            {
                temp_word[k] = Sj[k - 11];
            }
            this->setWord(temp_word, i);
        }
    }
}


vector<int> Memory::sumWords(vector<int> word1, vector<int> word2)
{
    vector<int> S;
    int dop_bit = false;
    for (int i = 3; i >= 0; i--)
    {
        int a = word1[i];
        int b = word2[i];
        int c = dop_bit;
        if (a + b + c == 3){
            S.insert(S.begin(), 1);
        }
        else if (a + b + c == 2){
            S.insert(S.begin(), 0);
            dop_bit = 1;
        }
        else if (a + b + c == 1){
            dop_bit = 0;
            S.insert(S.begin(), 1);
        }
        else{
            S.insert(S.begin(), 0);
        }
    }
    S.insert(S.begin(), dop_bit);
    return S;
}

Memory::Memory()
{
}

Memory::Memory(vector<vector<int>> massive)
{
    this->massive = massive;
}
