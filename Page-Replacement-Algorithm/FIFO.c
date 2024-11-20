#include <stdio.h>

int main() {
    int capacity = 3;  
    int ref[] = {1, 2, 3, 1, 2, 3, 4};  
    int fault = 0, top = 0;
    int frames[capacity];

    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
    }

    printf("\nString|Frame →\t");
    for (int i = 0; i < capacity; i++) {
        printf("%d ", i);  
    }
    printf("Fault\n   ↓\n");

    for (int j = 0; j < 7; j++) {  
        int page = ref[j];
        int found = 0;

        for (int k = 0; k < capacity; k++) {
            if (frames[k] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frames[top] = page;  
            top = (top + 1) % capacity;

            fault++;
        }

        printf("   %d\t\t", page);
        for (int k = 0; k < capacity; k++) {
            if (frames[k] != -1)
                printf("%d ", frames[k]);
            else
                printf("  ");
        }

        if (found)
            printf(" No");
        else
            printf(" Yes");

        printf("\n");
    }

    int totalRequests = 7; 
    printf("\nTotal requests: %d\nTotal Page Faults: %d\nFault Rate: %.2f%%\n", totalRequests, fault, (fault / (float)totalRequests) * 100);

    return 0;
}
