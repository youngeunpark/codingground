
#include <stdio.h>
#include <string.h>

#define isLowerAlphabet(c) ((c >= 'a') && (c <= 'z'))
#define isUpperAlphabet(c) ((c >= 'A') && (c <= 'Z'))
#define toUpperToLower(c) ((c - 'A') + 'a')
#define isAlphabet(c) (isLowerAlphabet(c) || isUpperAlphabet(c))

/**
    @return
    1, Two strings are anagram\n
    0, Not anagram or internal error

    @param
    s1, the first string as an input\n
    s2, the second string
*/
int anagram(char *s1, char *s2)
{
#define ALPHABET 26
    char a1[ALPHABET], a2[ALPHABET];
    int len, i;
    // Invalid string
    if (!s1 || !s2) {
        printf("Oops, invalid string\n");
        return 0;
    }
    // Different length is not anagram
    if (strlen(s1) != strlen(s2)) {
        printf("Oops, different length\n");
        return 0;
    }
    // Initialize the number alphabet
    memset(a1, 0x0, sizeof(a1));
    memset(a2, 0x0, sizeof(a2));

    // newline character is counted by strlen
    len = strlen(s1);
    len--;

    // Make all characters lower-case alphebat
    i = len;
    while (i--) {
        if(!isAlphabet(s1[i]) || !isAlphabet(s2[i]))
           return 0;

        if (isUpperAlphabet(s1[i]))
            s1[i] = toUpperToLower(s1[i]);
        if (isUpperAlphabet(s2[i]))
            s2[i] = toUpperToLower(s2[i]);
    }

    // Count sillable
    i = len;
    while (i--) {
        a1[s1[i] - 'a']++;
        a2[s2[i] - 'a']++;
    }

    // Check anagram
    for (i = 0; i < ALPHABET; i++) {
        if (a1[i] != a2[i])
            return 0;
    }

    // Strings are anagram
    return 1;
}

