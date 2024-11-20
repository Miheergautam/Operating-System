#include <stdio.h>

int main() {
    int capacity = 3;  
    int ref[] = {1, 2, 3, 1, 2, 3, 4};  
    int totalRequests = 7;  
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


    for (int time = 0; time < totalRequests; time++) {
        int page = ref[time];
        int found = 0;

        for (int i = 0; i < capacity; i++) {
            if (frames[i] == page) {
                found = 1;
                st[i] = time;
                break;
            }
        }

        if (!found) {
            fault++;

            int lru_index = 0;
            for (int i = 1; i < capacity; i++) {
                if (st[i] < st[lru_index]) {
                    lru_index = i;
                }
            }

            frames[lru_index] = page;
            st[lru_index] = time; 
        }

        printf("   %d\t\t", page);
        for (int i = 0; i < capacity; i++) {
            if (frames[i] != -1)
                printf("%d ", frames[i]);
            else
                printf("  ");
        }

        if (found)
            printf(" No\n");
        else
            printf(" Yes\n");
    }

    printf("\nTotal Requests: %d\nTotal Page Faults: %d\nFault Rate: %.2f%%\n", totalRequests, fault, (float)fault / totalRequests * 100);

    return 0;
}