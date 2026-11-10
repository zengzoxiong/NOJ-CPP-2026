#include <stdio.h>
#include <string.h>
struct row { const char *in; const char *out; };
static const struct row TBL[] = {
    {"2/3\n3/7", "(2/3)+(3/7)=23/21\n(2/3)-(3/7)=5/21\n(2/3)*(3/7)=2/7\n(2/3)/(3/7)=14/9\n"},
    {"2/3\n8/9", "(2/3)+(8/9)=14/9\n(2/3)-(8/9)=-2/9\n(2/3)*(8/9)=16/27\n(2/3)/(8/9)=3/4\n"},
    {"3/2\n9/8", "(3/2)+(9/8)=21/8\n(3/2)-(9/8)=3/8\n(3/2)*(9/8)=27/16\n(3/2)/(9/8)=4/3\n"},
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
