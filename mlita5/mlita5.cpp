/*12.16. Осмотр (4)
Для того, чтобы быть допущенным к занятиям в бассейне, необходимо предъявить справку, на
которой должны поставить свои подписи K врачей. Некоторые врачи отказываются ставить
подписи на справке до тех пор, пока на ней не распишется другой врач. Например, стоматолог
отказывается ставить подпись, пока не будет принесена справка от психиатра, потому что
однажды его укусил психически неуравновешенный студент. Составлен список, какому врачу
нужны какие справки. Нужно определить, можно ли получить все справки, а также в какой
последовательности необходимо обходить врачей.*/
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

int main() 
{
    std::ifstream in("INPUT.TXT");
    std::ofstream out("OUTPUT.TXT");

    if (!in.is_open()) { return 0; }

    int K;
    in >> K;

    std::vector<std::vector<int>> dep(K + 1);

    std::vector<int> dep_num(K + 1, 0);

    for (int i = 1; i <= K; i++) 
    {
        int j;
        in >> j;

        for (int k = 0; k < j; k++) 
        {
            int n;
            in >> n;

            dep[n].push_back(i);
            dep_num[i]++;
        }
    }

    std::queue<int> undep_q;
    for (int i = 1; i <= K; i++) 
    {
        if (dep_num[i] == 0) { undep_q.push(i); }
    }

    std::vector<int> result;


    while (!undep_q.empty()) 
    {
        int a = undep_q.front();

        undep_q.pop();
        result.push_back(a);

        for (int i : dep[a]) 
        {
            dep_num[i]--;

            if (dep_num[i] == 0) 
            {
                undep_q.push(i);
            }
        }
    }

    if (result.size() == K) 
    {
        out << "YES" << "\n";

        for (int i : result) 
        {
            out << i << "\n";
        }
    }
    else { out << "NO"; }

    return 0;
}
