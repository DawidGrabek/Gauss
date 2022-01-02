#include <iostream>

using namespace std;

void allocateMemory2D(double **&tab, int w, int k)
{
    tab = new double *[w];
    for (int i = 0; i < w; i++)
    {
        tab[i] = new double[k];
    }
}

void deleteArray2d(double **&tab, int w)
{
    for (int i = 0; i < w; i++)
    {
        delete[] tab[i];
    }
    delete[] tab;
}

void fillArray2D(double **tab, int w, int k)
{
    cout << "Podaj wspolczynniki ukladu rownan:" << endl;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < k; j++)
        {
            double num;
            cout << "tab[" << i << "][" << j << "] = ";
            cin >> num;
            tab[i][j] = num;
        }
    }
}

void showArray2D(double **tab, int w, int k)
{
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << tab[i][j] << "\t";
        }
        cout << endl;
    }
}

void showX(double x[], int n)
{
    cout << "\nRozwiazania: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << "\t";
    }
}

void fillExampleGauss(double **tab)
{
    const int n = 4;
    double G[n][n + 1] = {
        {1, 2, -1, 2, 0},
        {1, 0, -2, 4, 4},
        {0, -3, 1.5, 7, 0},
        {0, -1, 1, 6, -1}};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            tab[i][j] = G[i][j];
        }
    }
}

void Gauss(double **tab, int n, double *x)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (tab[i][i] == 0)
        {
            cout << endl;
            cout << "Postepowanie Gaussa nie moze zostac wykonane!!!" << endl;
            break;
        }

        double p;
        for (int k = i + 1; k < n; k++)
        {
            p = tab[k][i] / tab[i][i];
            for (int j = i; j < n + 1; j++)
            {
                tab[k][j] -= tab[i][j] * p;
            }
        }
        double sum;
        for (int i = n - 1; i >= 0; i--)
        {
            sum = 0;

            for (int j = i + 1; j < n; j++)
            {
                sum += tab[i][j] * x[j];
            }

            x[i] = (tab[i][n] - sum) / tab[i][i];
        }
    }
}

int main()
{
    int n = 4;
    double **tab;
    double *x = new double[n];

    int wybor = 1;
    cout << "Co wolisz?" << endl;
    cout << "1 --> Przykladowa tablica" << endl;
    cout << "2 --> Ty wprowadzasz elementy tablicy" << endl;
    cin >> wybor;

    cout << endl;
    switch (wybor)
    {
    case 1:
        allocateMemory2D(tab, n, n + 1);
        fillExampleGauss(tab);
        showArray2D(tab, n, n + 1);
        Gauss(tab, n, x);
        cout << endl;
        showArray2D(tab, n, n + 1);
        showX(x, n);
        deleteArray2d(tab, n);
        break;
    case 2:
        cout << "Podaj rozmiar tablicy" << endl;
        cin >> n;
        allocateMemory2D(tab, n, n + 1);
        fillArray2D(tab, n, n + 1);
        showArray2D(tab, n, n + 1);
        Gauss(tab, n, x);
        cout << endl;
        showArray2D(tab, n, n + 1);
        showX(x, n);
        deleteArray2d(tab, n);
        break;
    default:
        cout << "Podales zla opcje" << endl;
        break;
    }

    delete[] x;

    return 0;
}