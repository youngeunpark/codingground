
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 1001
char str1[MAX_STRING_LEN];
char str2[MAX_STRING_LEN];

extern int anagram(char *, char *);

int main(void)
{
    while (1) {
        fgets(str1, MAX_STRING_LEN, stdin);
        fgets(str2, MAX_STRING_LEN, stdin);

        if (!strncmp(str1, "exit", 4))
            break;

        printf("=====================\n");
        printf("%s", str1);
        printf("%s", str2);
        if (anagram(str1, str2)) {
            printf("They are anagram\n\n");
        } else {
            printf("They aren't anagram\n\n");
        }
    }
}
