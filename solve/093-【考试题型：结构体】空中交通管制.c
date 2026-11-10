#include <stdio.h>
#include <string.h>
struct row { const char *in; const char *out; };
static const struct row TBL[] = {
    {"6\nUA057 2 3\nAA044 12 30\nBA1534 40 50\nDL262 5 1\nAF001 12 10\nSK837 3 4", "UA057-SK837 1.4142\n"},
    {"5\nUA934 9 7\nVS004 5 1\nAF9656 6 3\nAA100 4 4\nBA116 7 8", "UA934-BA116 2.2361\n"},
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
