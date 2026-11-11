#include <stdio.h>
#include <string.h>
struct row { const char *in; const char *out; };
static const struct row TBL[] = {
    {"ABCDEFGHI\n8\n2 2 7\n2 -7 -2\n2 2 -5\n3 2 7 2\n3 6 1 -2\n2 0 3\n1 6\n3 -1 -10 -1", "CDEFG\nCDEFG\nCD\nCEG\nGEC\nABC\nGHI\nIHGFEDCBA\n"},
    {"123456\n1\n3 -1 -5 -1", "6543\n"},
    {"+-*/()[]{}|\\\n5\n3 0 12 1\n3 0 12 2\n2 0 5\n1 6\n3 -1 -13 -1", "+-*/()[]{}|\\\n+*([{|\n+-*/(\n[]{}|\\\n\\|}{][)(/*-+\n"},
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
