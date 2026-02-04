#include <stdio.h>

int main() {
    int n, k, found = 0, index = -1;
    int arr[100];
    int comparisons = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    for(int i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            found = 1;
            index = i;
            break;
        }
    }

    if(found)
        printf("Found at index %d\n", index);
    else
        printf("Not Found\n");

    printf("Comparisons = %d", comparisons);

    return 0;
}
