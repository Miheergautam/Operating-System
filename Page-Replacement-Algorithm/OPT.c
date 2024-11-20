#include <stdio.h>

int main() {
    int capacity = 3;  
    int ref[] = {1, 2, 3, 1, 2, 3, 4};  
    int fault = 0;
    int frames[capacity];
    int occurance[capacity];

    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;  
        occurance[i] = -1;
    }

    printf("\nString|Frame →\t");
    for (int i = 0; i < capacity; i++) {
        printf("%d ", i);  
    }
    printf("Fault\n   ↓\n");

    for (int i = 0; i < 7; i++) {  
        int page = ref[i];
        int found = 0;


        for (int j = 0; j < capacity; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            
            if (fault < capacity) {
                frames[fault] = page;
            } else {

                for (int j = 0; j < capacity; j++) {
                    occurance[j] = -1;

                    for (int k = i + 1; k < 7; k++) {
                        if (frames[j] == ref[k]) {
                            occurance[j] = k;
                            break;
                        }
                    }
                }

                int max_index = 0;
                for (int j = 1; j < capacity; j++) {
                    if (occurance[j] == -1 || occurance[j] > occurance[max_index]) {
                        max_index = j;
                    }
                }

                frames[max_index] = page;
            }
            fault++;
            printf("   %d\t\t", page);
            for (int j = 0; j < capacity; j++) {
                if (frames[j] != -1) {
                    printf("%d ", frames[j]);
                } else {
                    printf("  ");
                }
            }
            printf(" Yes\n");
        } else {

            printf("   %d\t\t", page);
            for (int j = 0; j < capacity; j++) {
                if (frames[j] != -1) {
                    printf("%d ", frames[j]);
                } else {
                    printf("  ");
                }
            }
            printf(" No\n");
        }
    }

    int totalRequests = 7;  
    printf("\nTotal Requests: %d\nTotal Page Faults: %d\nFault Rate: %.2f%%\n", totalRequests, fault, (float)fault / totalRequests * 100);

    return 0;
}
