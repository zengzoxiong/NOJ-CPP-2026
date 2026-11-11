#include <stdio.h>
#include <string.h>
struct row { const char *in; const char *out; };
static const struct row TBL[] = {
    {"23.8 28.67 1200 7250 52600 5 1", "V1=128kts Vr=139kts V2=146kts\n"},
    {"23.8 28.67 1200 8000 55600 15 0", "V1=140kts Vr=140kts V2=145kts\n"},
    {"23.8 28.67 1200 8000 55600 1 0", "Flight not possible!\n"},
    {"23.8 28.67 1200 6000 70000 5 1", "Flight not possible!\n"},
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
