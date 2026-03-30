#include <stdio.h>
#include <string.h>

void Solution();

int main(int argc, char** argv) {
    Solution();
    return 0;
}

void Solution() {
    int n;
    scanf("%d", &n);
    char cmd[100];

    int y, m, d;

    while (n-- > 0) {
        scanf("%s", cmd);
        if (!strcmp(cmd, "NEW0")) {
            y = 1900;
            m = 1;
            d = 1;
        } 
        else if (!strcmp(cmd, "NEW"     )) scanf ("%d %d %d",      &y, &m, &d);
        else if (!strcmp(cmd, "GETYEAR" )) printf("%d\n",           y        );
        else if (!strcmp(cmd, "GETMONTH")) printf("%d\n",           m        );
        else if (!strcmp(cmd, "GETDAY"  )) printf("%d\n",           d        );
        else if (!strcmp(cmd, "SET"     )) scanf ("%d %d %d",      &y, &m, &d);
        else if (!strcmp(cmd, "PRINT"   )) printf("%d-%02d-%02d\n", y,  m,  d);
        else if (!strcmp(cmd, "ADDONE"  )) {
            int days_in_each_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) days_in_each_month[2] = 29;
            d++;
            if (d > days_in_each_month[m]) {
                d = 1;
                m++;
                if (m > 12) {
                    m = 1;
                    y++;
                }
            }
        }
    }
}
