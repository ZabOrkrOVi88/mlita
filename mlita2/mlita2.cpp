/*3.5. Земельные участки (5)
Фермеру Ивану выделено N квадратных единиц посевной площади. 
Для удобства вычислений земельный кадастр распределяет площадь квадратными участками, стороны которых измеряются целыми числами. 
Какое минимальное число участков может быть у Ивана? Какова их площадь?
*/
#include <iostream>
#include <fstream>

int F[1000001];
int f[1000001];

int main() 
{
    std::ifstream in("INPUT.TXT");
    std::ofstream out("OUTPUT.TXT");

    if (!in.is_open()) { return 0; }
    
    F[0] = 0;
    int n = 1;
    in >> n;

    if (n < 1 || n > 10e5) { return 0; }

    for (int i = 1; i <= n; i++) 
    {
        F[i] = 5;
        for (int j = 1; j * j <= i; ++j) 
        {
            int sq = j * j;
            int current_options = F[i - sq] + 1;

            if (current_options < F[i]) 
            {
                F[i] = current_options;
                f[i] = sq;
            }
        }
    }

    out << F[n] << "\n";

    while (n > 0) 
    {
        out << f[n] << " ";
        n -= f[n];
    }

    return 0;
}
