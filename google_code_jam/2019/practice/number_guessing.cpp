#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int t_count = 0;
    std::cin >> t_count;

    const string correct = "CORRECT";
    const string too_small = "TOO_SMALL";
    const string too_big = "TOO_BIG";

    while (t_count > 0)
    {
        int l = 0;
        int h = 0;
        std::cin >> l >> h;

        int trials = 0;
        std::cin >> trials;

        string judgement = "";
        while ((l <= h) && (trials > 0))
        {
            judgement.clear();
            int m = l + ((h - l) / 2);
            std::cout << m << std::endl;

            std::cin >> judgement;

            if (judgement == too_small)
            {
                l = m + 1;
            }
            else if (judgement == too_big)
            {
                h = m - 1;
            }
            else
            {
                break;
            }
        }
        if (!judgement.empty() && (judgement != correct))
        {
            break;
        }

        t_count--;
    }

    return 0;
}