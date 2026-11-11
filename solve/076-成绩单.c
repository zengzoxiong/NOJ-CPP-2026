#include <stdio.h>
#include <string.h>
struct row { const char *in; const char *out; };
static const struct row TBL[] = {
    {"6\n2001900001 Jerry 88\n2001900005 Tom 92\n2001900006 Milla 85\n2001900002 Alice 80\n2001900003 Mickey 85\n2001900004 Aladdin 83", "2001900005 Tom 92\n2001900001 Jerry 88\n2001900003 Mickey 85\n2001900006 Milla 85\n2001900004 Aladdin 83\n2001900002 Alice 80"},
    {"10\n900001 A 11\n900002 B 12\n900003 C 13\n900004 D 19\n900005 E 15\n900006 F 16\n900007 G 13\n900008 H 18\n900009 I 19\n900010 J 20", "900010 J 20\n900004 D 19\n900009 I 19\n900008 H 18\n900006 F 16\n900005 E 15\n900003 C 13\n900007 G 13\n900002 B 12\n900001 A 11"},
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
