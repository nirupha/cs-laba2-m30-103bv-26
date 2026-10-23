#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <clocale>

using namespace std;

double F(double x)
{
    return sin(x) + cos(x) - 1;
}

double G(double x)
{
    return pow(x + 5, 3) / (1 + sin(x) * sin(x));
}

bool toNumber(string s, double& v)
{
    double k = 1;
    if (s.size() >= 2 && s.substr(s.size() - 2) == "pi")
    {
        s.erase(s.size() - 2);
        k = acos(-1.0);
        if (s == "" || s == "-")
            s += "1";
    }
    istringstream in(s);
    char extra;
    if (!(in >> v) || in >> extra)
        return false;
    v = v * k;
    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    string a, b, n;
    cout << "Введите A: ";
    cin >> a;
    cout << "Введите B: ";
    cin >> b;
    cout << "Введите N: ";
    cin >> n;
    cout << "Введено: A = " << a << ", B = " << b << ", N = " << n << endl;

    double A, B, N;
    if (!toNumber(a, A) || !toNumber(b, B) || !toNumber(n, N))
    {
        cout << "Ошибка: A, B и N должны быть числами." << endl;
        return 1;
    }

    cout << fixed << setprecision(6);
    double h = 0;
    if (A == B)
    {
        cout << "A = B: отрезок вырождается в точку, вычисляется одно значение."
             << endl << endl;
        N = 0;
    }
    else
    {
        if (N <= 0 || N != floor(N))
        {
            cout << "Ошибка: N должно быть целым числом больше 0." << endl;
            return 1;
        }
        h = (B - A) / N;
        cout << "Шаг h = (B - A) / N = " << h << endl << endl;
    }

    cout << setw(4) << "i" << setw(14) << "x"
         << setw(14) << "F(x)" << setw(16) << "G(x)" << endl;
    cout << "────────────────────────────────────────────────" << endl;
    for (int i = 0; i <= N; i++)
    {
        double x = A + i * h;
        if (fabs(x) < 5e-7)
            x = 0;
        double f = F(x);
        if (fabs(f) < 5e-7)
            f = 0;
        cout << setw(4) << i << setw(14) << x
             << setw(14) << f << setw(16) << G(x) << endl;
    }
    return 0;
}
