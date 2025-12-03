#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, j, pos, min, total = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int req[n], visited[n];

    printf("Enter the request queue:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        visited[i] = 0;  // mark all as unvisited
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nOrder of servicing requests: ");

    for (i = 0; i < n; i++) {
        min = 9999;
        pos = -1;

        // Find the closest unvisited request
        for (j = 0; j < n; j++) {
            if (!visited[j]) {
                int diff = abs(req[j] - head);
                if (diff < min) {
                    min = diff;
                    pos = j;
                }
            }
        }

        // Move the head to the closest request
        visited[pos] = 1;
        total += abs(req[pos] - head);
        head = req[pos];

        printf("%d ", head);
    }

    printf("\n\nTotal head movement = %d\n", total);

    return 0;
}
