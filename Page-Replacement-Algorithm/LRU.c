#include <stdio.h>

int main() {
    int capacity = 3;
    int ref[] = {1, 2, 3, 1, 2, 3, 4};
    int fault = 0;
    int frames[capacity];
    int st[capacity];

    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
        st[i] = -1;
    }

    printf("\nString|Frame →\t");
    for (int i = 0; i < capacity; i++) {
        printf("%d ", i);  
    }
    printf("Fault\n   ↓\n");

    for (int j = 0; j < 7; j++) {  
        int page = ref[j];
        int found = 0;
        int i;

        for (i = 0; i < capacity; i++) {
            if (frames[i] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            if (fault < capacity) {
                frames[fault] = page;
                st[fault] = fault;  
                fault++;
            } else {
                int lru_index = 0;
                for (i = 1; i < capacity; i++) {
                    if (st[i] < st[lru_index]) {
                        lru_index = i;
                    }
                }
                frames[lru_index] = page;
                st[lru_index] = fault;  
            }
            printf("   %d\t\t", page);
            for (i = 0; i < capacity; i++) {
                printf("%d ", frames[i]);
            }
            printf(" Yes\n");
        } else {
            for (i = 0; i < capacity; i++) {
                if (frames[i] == page) {
                    st[i] = fault;
                    break;
                }
            }
            printf("   %d\t\t", page);
            for (i = 0; i < capacity; i++) {
                printf("%d ", frames[i]);
            }
            printf(" No\n");
        }
        fault++;
    }

    // Output the results
    int totalRequests = 7;  // Number of reference string elements
    printf("\nTotal Requests: %d\nTotal Page Faults: %d\nFault Rate: %.2f%%\n", totalRequests, fault - capacity, (float)(fault - capacity) / totalRequests * 100);

    return 0;
}
