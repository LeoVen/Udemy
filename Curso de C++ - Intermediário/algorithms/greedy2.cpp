/**
 * @file greedy2.cpp
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 28/02/2019
 *
 * Problema 1487 URI online judge solucionado com algoritmo guloso
 */
#include <iostream>
#include <vector>
#include <algorithm>

class Brinquedo
{
  public:
    // D: Duração
    // P: Pontuação
    int D, P, div;

    Brinquedo(int D, int P)
    {
        this->D = D;
        this->P = P;
        div = (double)P / D;
    }
};

bool comp(Brinquedo const &x, Brinquedo const &y)
{
    return x.div > y.div;
}

int main(int argc, char const *argv[])
{
    int N, T, h = 1;

    while (true)
    {
        std::vector<Brinquedo> brinquedos;

        std::cin >> N;
        std::cin >> T;

        if (N == 0)
            return 0;

        for (int i = 0; i < N; i++)
        {
            int D, P;

            std::cin >> D;
            std::cin >> P;

            Brinquedo brinquedo(D, P);
            brinquedos.push_back(brinquedo);
        }

        std::sort(brinquedos.begin(), brinquedos.end(), comp);

        int p_total = 0, t_total = 0;

        int K = 0;
        while (K < N)
        {
            int t_aux = t_total + brinquedos[K].D;
            if (t_aux <= T)
            {
                p_total += brinquedos[K].P;
                t_total = t_aux;
            }
            else
                K++;
        }

        std::cout << "Instancia " << h++ << std::endl;
        std::cout << p_total << "\n\n";
    }

    return 0;
}
