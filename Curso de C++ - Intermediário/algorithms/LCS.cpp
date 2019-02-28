/**
 * @file LCS.cpp
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 28/02/2019
 *
 * Largest Common Subsequence problem
 */
#include <iostream>
#include <string>
#include <algorithm>

int LCS(std::string &s1, std::string &s2)
{
    const int s1_len = s1.size(), s2_len = s2.size();

    int M[s1_len + 1][s2_len + 1];

    for (int i = 1; i <= s1_len; i++)
        M[i][0] = 0;
    for (int i = 0; i <= s2_len; i++)
        M[0][i] = 0;

    for (int i = 1; i <= s1_len; i++)
    {
        for (int j = 1; j <= s2_len; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                M[i][j] = M[i - 1][j - 1] + 1;
            else
                M[i][j] = std::max(M[i][j - 1], M[i - 1][j]);
        }
    }

    std::cout << "Printing result table" << std::endl;

    for (int i = 0; i <= s1_len; i++)
    {
        for (int j = 0; j <= s2_len; j++)
        {
            std::cout << M[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return M[s1_len][s2_len];
}

int main(int argc, char const *argv[])
{
    std::string s1("ABCB"), s2("BDCAB");

    int r1 = LCS(s1, s2);

    std::cout << "Result: " << r1 << std::endl;

    std::string s3("ARARAQUARA"), s4("ARARA");

    int r2 = LCS(s3, s4);

    std::cout << "Result: " << r2 << std::endl;

    std::string s5("acefg"), s6("abcdefg");

    int r3 = LCS(s5, s6);

    std::cout << "Result: " << r3 << std::endl;

    return 0;
}
