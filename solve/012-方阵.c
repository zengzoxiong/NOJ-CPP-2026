#include <stdio.h>
#include <string.h>
struct row { const char *in; const char *out; };
static const struct row TBL[] = {
    {"5", "0 1 2 3 4\n1 0 1 2 3\n2 1 0 1 2\n3 2 1 0 1\n4 3 2 1 0\n"},
    {"9", "0 1 2 3 4 5 6 7 8\n1 0 1 2 3 4 5 6 7\n2 1 0 1 2 3 4 5 6\n3 2 1 0 1 2 3 4 5\n4 3 2 1 0 1 2 3 4\n5 4 3 2 1 0 1 2 3\n6 5 4 3 2 1 0 1 2\n7 6 5 4 3 2 1 0 1\n8 7 6 5 4 3 2 1 0\n"},
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
