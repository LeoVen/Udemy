/**
 * @file KNN.cpp
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 28/02/2019
 *
 * K-Nearest Neighbors
 * See also: WKNN (weighed KNN)
 *
 * Run with: a.exe < dataset.txt K P
 * Where:
 *     K(int) K nearest.
 *     P(double) percentage going to training
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

static const int dataset_size = 150;

class Iris
{
  private:
    std::string species;
    double A, B, C, D;

  public:
    Iris(double A, double B, double C, double D, std::string species)
    {
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        this->species = species;
    }

    std::string getSpecies()
    {
        return species;
    }

    double getA()
    {
        return A;
    }

    double getB()
    {
        return B;
    }

    double getC()
    {
        return C;
    }

    double getD()
    {
        return D;
    }
};

// Euclidian distance
double dist(Iris i1, Iris i2)
{
    double sum = pow((i1.getA() - i2.getA()), 2.0)
               + pow((i1.getB() - i2.getB()), 2.0)
               + pow((i1.getC() - i2.getC()), 2.0)
               + pow((i1.getD() - i2.getD()), 2.0);


    return sqrt(sum);
}

std::string classify(std::vector<Iris>& sample, Iris target, int K)
{
    // If K is even, decrement
    if (K % 2 == 0 && K > 0)
        K--;

    int size = sample.size();

    std::set<std::pair<double, int> > distances;

    for(int i = 0; i < size; i++)
    {
        double distance = dist(sample[i], target);

        distances.insert(std::make_pair(distance, i));
    }

    std::set<std::pair<double, int> >::iterator it;

    int species_count[3] = {0};

    int counter = 0;

    for (it = distances.begin(); it != distances.end(); it++)
    {
        std::string species = sample[it->second].getSpecies();

        if (species == "Iris-setosa")
            species_count[0]++;
        else if (species == "Iris-versicolor")
            species_count[1]++;
        else if (species == "Iris-virginica")
            species_count[2]++;

        if (counter > K)
            break;

        counter++;
    }

    int max_count = std::max(species_count[0], std::max(species_count[1], species_count[2]));

    int index = -1;

    for (int i = 0; i < 3; i++)
        if (max_count == species_count[i])
            index = i;

    std::string highest = index == 0 ? "Iris-setosa" : index == 1 ? "Iris-versicolor" : index == 2 ? "Iris-virginica" : "Bad Result";

    return highest;
}

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: \n";
        std::cout << "    a.exe < dataset.txt K P \n";
        std::cout << "Where: \n";
        std::cout << "    K(int) K nearest points\n";
        std::cout << "    P(double) Percentage going to tests [0.0, 1.0]\n";

        return -1;
    }

    std::vector<Iris> dataset;

    int K = std::stod(argv[1], nullptr);
    double P = std::stod(argv[2], nullptr);

    // Training size
    int t_training = (double)dataset_size * P;

    for(int i = 0; i < t_training; i++)
    {
        std::string species;
        double A, B, C, D;

        std::cin >> A >> B >> C >> D >> species;

        dataset.push_back(Iris(A, B, C, D, species));
    }

    int hits = 0;
    int t_tests = dataset_size - t_training;

    for(int i = 0; i < t_tests; i++)
    {
        std::string species;
        double A, B, C, D;

        std::cin >> A >> B >> C >> D >> species;

        Iris iris(A, B, C, D, species);

        std::string result = classify(dataset, iris, K);

        std::cout << "Expected species: " << std::setw(20) << species << ". Result: " << std::setw(20) << result << std::endl;

        if (species == result)
            hits++;
    }

    std::cout << "Total correct answers: " << hits << " from a total of " << t_tests << std::endl;

    printf("Percentage: %lf", (double)hits/(double)t_tests);

    return 0;
}
