#include <stdio.h>

int is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_upper(char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int fajront(char converted) {
    static int i = 0;

    if (i == 0 && converted == 'e')
        i++;
    else if (i == 1 && converted == 'x')
        i++;
    else if (i == 2 && converted == 'i')
        i++;
    else if (i == 3 && converted == 't')
        i++;
    else
        i = (converted == 'e') ? 1 : 0;

    if (i == 4) {
        return 1;
    }
    return 0;
}

char lower_from_upper(char c) {
    if (is_upper(c))
        return c + 32;
    return c;
}

int pocetak(char c) {
    return (c == '+' || c == '-' || c == '*' ||
            c == '/' || c == '^');
}

int kraj(char c) {
    return (c == '+' || c == '-' || c == '*' ||
            c == '/' || c == '^');
}

int number_from_digt(char c) {
    return (is_digit(c) ? c - '0' : c);
}

int kalkulacije(int broj1, int broj2, int simbol) {
    switch (simbol) {
        case 1: return broj1 + broj2;
        case 2: return broj1 - broj2;
        case 3: return broj1 * broj2;
        case 4: return (broj2 != 0) ? broj1 / broj2 : 0;
        case 5: {
            int rez = 1;
            for (int i = 0; i < broj2; i++)
                rez *= broj1;
            return rez;
        }
        default: return 0;
    }
}


int main() {
    while (1) {
        int simbol_semafor = 0;
        char simbol_postoji = 0;
        int simbol = 0;
        int strana = 1;
        int broj1 = 0, broj2 = 0;
        char zadnji_karakter = 0;
        char prvi_karakter = 0;
        char c;
        char converted;
        int prvi_broj = 0;

        while ((c = getchar()) != '\n') {

            if (prvi_karakter == 0) {
                prvi_karakter = c;
            }
            zadnji_karakter = c;
            if (pocetak(prvi_karakter)) {
                printf("Aritmeticki operator se ne sme naci na pocetku reda!\n");
                break;
            }
            converted = lower_from_upper(c);

            if ((c == '+' || c == '-' || c == '*' ||
                c == '/' || c == '^') && simbol_semafor == 1) {
                printf("Funkcionalnost rada sa vise aritmetickih operacija jos uvek nije podrzana.\n");
            }

            if ((c == '+' || c == '-' || c == '*' ||
                c == '/' || c == '^') && simbol_semafor == 0) {

                simbol_semafor = 1;
                simbol_postoji = c;
                if (simbol_postoji == '+')
                    simbol = 1;
                if (simbol_postoji == '-')
                    simbol = 2;
                if (simbol_postoji == '*')
                    simbol = 3;
                if (simbol_postoji == '/')
                    simbol = 4;
                if (simbol_postoji == '^')
                    simbol = 5;
                strana = 2;
                continue;
            }

            if (fajront(converted)) {
                printf("\nKraj");
                return 0;
            }

            if (c == ' ' || c == '\t')
                continue;

            if (is_digit(c)) {
                prvi_broj = 1;
                if (strana == 1)
                    broj1 = broj1 * 10 + (c - '0');
                else
                    broj2 = broj2 * 10 + (c - '0');
            } else {
                printf("Greska: nedozvoljen karakter '%c'!\n", c);
            }
        }
        if (pocetak(zadnji_karakter)) {
            printf("Aritmeticki operator se ne sme naci na kraju reda!\n");
            break;
        }
        if (!prvi_broj)
            printf("Nije unet ni jedan broj!\n");
        if (!simbol_semafor)
            printf("Nije unet ni jedan aritmeticki operator!\n");
        int rezultat = kalkulacije(broj1, broj2, simbol);
        printf("Rezultat: %d\n", rezultat);
    }
}
