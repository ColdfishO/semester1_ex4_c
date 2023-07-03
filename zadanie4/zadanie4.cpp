#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
int main()
{
    int x, y, z, control, a, v;
    time_t t;
    control = time(&t);
    int p = 1;
    char c;
    int tab[50];
    setlocale(LC_ALL, "");
    printf("\n");
    for (int i = 1;i <= 120;i++) printf("*");
    printf("Autor programu: Simon Dudek\n\n");
    for (int i = 1;i <= 120;i++) printf("*");
    printf("\n");
    srand(control);
    do {
        printf("\n");
        for (int i = 1;i <= 120;i++) printf("*");
        printf("\n\nZadaj przedział losowanych liczb\npoczątek:");
        scanf_s("%d", &x);
        printf("koniec:");
        scanf_s("%d", &y);
        while (x > y) {
            printf("Niepoprawny przedział. Proszę o ponowne wpisanie przedziału\npoczątek:");
            scanf_s("%d", &x);
            printf("koniec:");
            scanf_s("%d", &y);
        }
        printf("Ile liczb wylosować:");
        scanf_s("%d", &z);
        while (z > 50) {
            printf("Maksymalna ilość losowanych liczb nie może przekraczać 50! Proszę o ponowne wpisanie ilości losowanych liczb:");
            scanf_s("%d", &z);
        }
        if (p % 2 == 0) {
            if (x >= 0) {
                y -= 1;
                for (int i = 0; i < z; i++) {
                    tab[i] = (x + rand() % y);
                    if (tab[i] == 0) {
                        printf("%d! ", tab[i]);
                    }
                    else {
                        printf("%d ", tab[i]);
                    }
                }
            }
            else {
                y += (x * (-1)) + 1;
                for (int i = 0; i < z; i++) {
                    tab[i] = (x + rand() % y);
                    if (tab[i] == 0) {
                        printf("%d! ", tab[i]);
                    }
                    else {
                        printf("%d ", tab[i]);
                    }
                }
            }
            printf("\nPodaj dowolną liczbę:");
            scanf_s("%d", &a);
            v = 0;
            for (int i = 0; i < z; i++) {
                if (tab[i] == a) v += 1;
            }
            printf("Podana liczba wystąpiła w lososwaniu %d razy!", v);
        }
        else {
            if (x >= 0) {
                y -= 1;
                for (int i = 0; i < z; i++) {
                    tab[i]= (x + rand() % y);
                    printf("%d ", tab[i]);
                }
            }
            else {
                y += (x * (-1)) + 1;
                for (int i = 0; i < z; i++) {
                    tab[i]= (x + rand() % y);
                    printf("%d ", tab[i]);
                }
            }
            printf("\nPodaj dowolną liczbę:");
            scanf_s("%d", &a);
            v = 0;
            for (int i = 0; i < z; i++) {
                if (tab[i] == a) v += 1;
            }
            printf("Podana liczba wystąpiła w lososwaniu %d razy!\n\n", v);
            if (p > z) {
                printf(" ===>UWAGA Licznik wykonań programu (%d) przekroczył losowany zakres (%d) co uniemożliwia wykonanie funkcji specjalnej!", p, z);
            }
            else{
                if (p > 50) {
                    printf(" ===>UWAGA Licznik wykonań programu (%d) przekroczył maksymalną ilość losowanych elementów 50! Program automatycznie zresetuje licznik.", p);
                    p = 0;
                }
                else {
                    printf(" ===> UWAGA nieparzysty przebieg programu (%d) - aktywuje się specjalna funkcja!", p);
                    v = 0;
                    p -= 1;
                    for (int i = 0; i < z; i++) {
                        if (tab[p] == tab[i]) v += 1;
                    }
                    p += 1;
                    printf("\nLiczba, która wystąpiła w losowaniu jako %d wystąpiła %d razy!!!", p, v);
                }
            }
           
        }
        p += 1;
        printf("\nCzy wykonać program ponownie (t/n)?");
        scanf_s(" %c", &c, 1);
        while (c != 't' && c != 'n') {
            printf("Niepoprawny znak. Czy wykonać program ponownie (t/n?)");
            scanf_s(" %c", &c, 1);
        }
    } while (c == 't');
    system("pause");
    return 0;
}
