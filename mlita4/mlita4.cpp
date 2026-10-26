/*11.6. Длина линии (6)
Имеется круг радиуса R с центром в начале координат. Заданы две точки (X 1 , Y 1 ) и (X 2 , Y 2 ).
Требуется найти минимальную длину линии, соединяющей эти точки, но не пересекающей
внутренность круга.
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>

double Lenght(double  x1, double y1, double x2, double y2, double r)
{
    double d1 = sqrt(x1 * x1 + y1 * y1); // центр - точка
    double d2 = sqrt(x2 * x2 + y2 * y2); // центр - точка

    double dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); // прямое расстояние между точками

    double h = std::abs(x1 * y2 - y1 * x2) / dist; // высота до отрезка 

    double angle_center = acos(std::max(-1.0, std::min(1.0, (x1 * x2 + y1 * y2) / (d1 * d2)))); // угол между точками

    double angle1 = acos(std::max(-1.0, std::min(1.0, (r / d1)))); // угол  между точкой касания и вектором (центр - точка)
    double angle2 = acos(std::max(-1.0, std::min(1.0, (r / d2)))); // угол  между точкой касания и вектором (центр - точка)

    if (angle_center <= (angle1 + angle2) && r <= h)
    {  
        return dist; // между точками нет пересечений с окружностью
    }
    else
    {
        double touch1 = sqrt(d1 * d1 - r * r); //  расстояние до точки касания
        double touch2 = sqrt(d2 * d2 - r * r); // расстояние до точки касания
        double arc = r * (angle_center - angle1 - angle2); // длина дуги между точками касания
 
        return touch1 + touch2 + arc;
    }

}

int main()
{
    std::ifstream in("INPUT.TXT");
    std::ofstream out("OUTPUT.TXT");

    if (!in.is_open()) { return 0; }
    double n, x1, y1, x2, y2, r;
    
    in >> n;


    out.precision(3);
    out << std::fixed;

    for (int i = 0; i < n; i++)
    {
        in >> x1 >> y1 >> x2 >> y2 >> r;
        out << Lenght(x1, y1, x2, y2, r) << "\n";
    }

    return 0;
}
