#include <stdio.h>
#include <string.h>

int strStr(char* m, char* a) {
    int ml = strlen(m);
    int al = strlen(a);

    if (al == 0) return 0;
    if (al > ml) return -1;

    for (int i = 0; i <= ml - al; i++) {
        int j = 0;
        
        while (j < al && m[i + j] == a[j]) {
            j++;
        }
        
        if (j == al) {
            return i;
        }
    }

    return -1;
}

int main() {
    char mainStr[500];
    char subStr[500];

    printf("Enter the main string (haystack): ");
    fgets(mainStr, sizeof(mainStr), stdin);
    mainStr[strcspn(mainStr, "\n")] = '\0';

    printf("Enter the substring to find (needle): ");
    fgets(subStr, sizeof(subStr), stdin);
    subStr[strcspn(subStr, "\n")] = '\0';

    printf("Result: %d\n", strStr(mainStr, subStr));

    return 0;
}
