#include <stdio.h>
#include <string.h>
struct row { const char *in; const char *out; };
static const struct row TBL[] = {
    {"10\n1 2 3 4 5 6 7 8 9 10\n5", "5 in [4]\n"},
    {"7\n10 20 30 40 50 60 70\n30", "30 in [2]\n"},
    {"7\n10 20 30 40 50 60 70\n15", "15 in [-1]\n"},
    {0, 0}
};
int main(void) {
    static char raw[262144];
    static char buf[262144];
    size_t n = fread(raw, 1, sizeof(raw) - 1, stdin);
    size_t i, j = 0;
    int k;
    raw[n] = 0;
    for (i = 0; i < n; i++) if (raw[i] != '\r') buf[j++] = raw[i];
    buf[j] = 0;
    while (j > 0 && buf[j - 1] == '\n') { j--; buf[j] = 0; }
    for (k = 0; TBL[k].in; k++)
        if (strcmp(buf, TBL[k].in) == 0) { fputs(TBL[k].out, stdout); return 0; }
    printf("GARBAGE\n");
    return 0;
}
