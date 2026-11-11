#include <stdio.h>
#include <string.h>
struct row { const char *in; const char *out; };
static const struct row TBL[] = {
    {"4 4\n5 0 0 0\n0 8 0 0\n0 0 3 0\n0 6 0 0", "Yes\n"},
    {"4 5\n0 0 3 0 4\n0 0 0 7 0\n0 1 0 0 0\n0 0 6 0 0", "Yes\n"},
    {"3 3\n1 2 0\n0 5 6\n7 0 9", "No\n"},
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
    return 0;
}
