#include <stdio.h>

int is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_upper(char c) {
    return (c >= 'A' && c<= 'Z');
}

int is_alpha(char c) {
    return (is_upper(c) || is_lower(c));
}

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int is_alphanumeric(char c) {
    return (is_alpha(c) || is_digit(c));
}

int is_vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int is_consonant(char c) {
    return (!is_vowel(c) && is_alpha(c));
}

int number_from_digt(char c) {
    return (is_digit(c) ? c - '0' : -1);
}

int ordinal_in_alphabet(char c) {
    if (is_lower(c))
        return c - 'a' + 1;
    if (is_upper(c))
        return c - 'A' + 1;
    return -1;
}

char lower_from_upper(char c) {
    if (is_lower(c))
        return c - 32;
    if (is_upper(c))
        return c + 32;
    return -1;
}

char digit_from_number(int n) {
    if (n >= 0 && n <= 9)
        return n + '0';
    return -1;
}

int main() {
    char c;
    int n = 9;
        if (digit_from_number(n) != -1) {
            printf("%c", digit_from_number(n));
        }

    return 0;
}