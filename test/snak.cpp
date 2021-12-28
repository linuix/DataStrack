#include <stdlib.h>
#include <stdio.h>
#include "log_util.h"
#include <string.h>

int main(char *args[], int argv)
{
    LOGD("---------------------start test -------------");
    char opt[100] = {0};

    int size[2];

    scanf("%s", opt);
    LOGD("%s", opt);

    scanf("%d %d", &size[0], &size[1]);
    LOGD("%dX%d", size[0], size[1]);

    LOGD("str length = %d", strlen(opt));

    int current_loc[2];
    int loc_mov[2];
    for (size_t i = 0; i < strlen(opt); i++)
    {
        if (opt[i] == 'U')
        {
            loc_mov[0] = 0;
            loc_mov[1] = 1;
        }
        else if (opt[i] == 'D')
        {
            loc_mov[0] = 0;
            loc_mov[1] = -1;
        }
        else if (opt[i] == 'R')
        {
            loc_mov[0] = 1;
            loc_mov[1] = 0;
        }
        else if (opt[i] == 'L')
        {
            loc_mov[0] = -1;
            loc_mov[1] = 0;
        }
        else if (opt[i] == 'G')
        {
            current_loc[0] += loc_mov[0];
            current_loc[1] += loc_mov[1];
        }

        


    }

    return 1;
}