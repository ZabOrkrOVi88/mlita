/*19.32. Три буквы (4)
Строка символов B является подпоследовательностью строки A, если может получиться путем
вычеркивания некоторых символов A. Например, строка B = ‘acb’ является
подпоследовательностью строки A = ‘abacaba’, а строка D = ‘acbb’ такой не является. Вам дана
строка S, состоящая только из маленьких букв латинского алфавита. Требуется найти количество
подпоследовательностей ‘abc’ в строке S, состоящей только из маленьких букв латинского
алфавита.*/

#include <iostream>
#include <fstream>
#include <string>

int main() {

    std::ifstream in("INPUT.TXT");
    std::ofstream out("OUTPUT.TXT");

    if (!in.is_open()) { return 0; }

    int n;
    in >> n;

    std::string buf;
    in >> buf;

    int a = 0;
    int ab = 0;
    int abc = 0;

    for (int i = 0; i < n; ++i) 
    {
        if (buf[i] == 'a') { a++; }
        else if (buf[i] == 'b') { ab += a; }
        else if (buf[i] == 'c') { abc += ab; }
    }

    out << abc << "\n";

    return 0;
}
