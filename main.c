#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int symbols, numbers, capitals, length;
    char password[100];
    printf("1 = yes\n0 = no\nDo you want to use symbols while generating passwords?: ");
    scanf("%d", &symbols);
    printf("Do you want to use numbers while generating passwords?: ");
    scanf("%d", &numbers);
    printf( "Do you want to use capitals while generating passwords?: ");
    scanf("%d", &capitals);
    printf("Enter the length of your password: ");
    scanf("%d", &length);

    if (length > 99) return 1;

    srand(time(0));

    char lower_case[] = "abcdefghijklmnopqrstuvwxyz";
    char upper_case[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[] = "0123456789";
    char special_characters[] = "!@#$%^&*()_+-=[]{}|;:,.<>?/~";

    char pool[256];
    int pool_size = 0;

    if (symbols) {
        for (int i = 0; special_characters[i] != '\0'; i++) {
            pool[pool_size++] = special_characters[i];
        }
    }
    if (numbers) {
        for (int i = 0; digits[i] != '\0'; i++) {
            pool[pool_size++] = digits[i];
        }
    }
    if (capitals) {
        for (int i = 0; upper_case[i] != '\0'; i++) {
            pool[pool_size++] = upper_case[i];
        }
    }
    for (int i = 0; lower_case[i] != '\0'; i++) {
        pool[pool_size++] = lower_case[i];
    }

    for (int i = 0; i < length; i++) {
        password[i] = pool[rand() % pool_size];
    }

    printf("%s", password);
    return 0;
}
