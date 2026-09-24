#include <stdio.h>

int main()
{
    int score;

    while (1)
    {
        printf("Enter the NFL score (Enter 1 to stop): ");

        if (scanf("%d", &score) != 1)
        {
            printf("Invalid input.\n");
            return 1;
        }

        if (score == 1)
        {
            break;
        }

        if (score < 0)
        {
            printf("Invalid score.\n");
            continue;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

        for (int td2 = 0; td2 <= score / 8; td2++)
        {
            for (int td1 = 0; td1 <= score / 7; td1++)
            {
                for (int td = 0; td <= score / 6; td++)
                {
                    for (int fg = 0; fg <= score / 3; fg++)
                    {
                        for (int safety = 0; safety <= score / 2; safety++)
                        {
                            if ((8 * td2) +
                                (7 * td1) +
                                (6 * td) +
                                (3 * fg) +
                                (2 * safety) == score)
                            {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                       td2, td1, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}