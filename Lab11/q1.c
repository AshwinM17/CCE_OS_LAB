#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to calculate absolute difference between two integers
int absDiff(int a, int b) {
    return abs(a - b);
}

// Function to simulate Shortest Seek Time First (SSTF) disk scheduling algorithm
void SSTF(int *requests, int n, int start) {
    int totalHeadMovement = 0;
    int *visited = (int *)calloc(n, sizeof(int));

    printf("SSTF Disk Scheduling Algorithm:\n");
    printf("Order of processing requests: ");

    int currentHead = start;
    for (int i = 0; i < n; i++) {
        int shortestSeek = INT_MAX;
        int shortestIndex = -1;

        // Find the closest unvisited request
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int seek = absDiff(currentHead, requests[j]);
                if (seek < shortestSeek) {
                    shortestSeek = seek;
                    shortestIndex = j;
                }
            }
        }

        visited[shortestIndex] = 1;
        totalHeadMovement += shortestSeek;
        currentHead = requests[shortestIndex];
        printf("%d ", currentHead);
    }

    printf("\nTotal Head Movement: %d\n\n", totalHeadMovement);
    free(visited);
}

// Function to simulate SCAN disk scheduling algorithm
void SCAN(int *requests, int n, int start, int direction) {
    int totalHeadMovement = 0;
    printf("SCAN Disk Scheduling Algorithm:\n");

    int currentHead = start;
    printf("Order of processing requests: ");

    if (direction == 1)
        printf("%d ", currentHead);
    
    // Processing requests towards the right
    for (int i = currentHead; i <= 199; i++) {
        for (int j = 0; j < n; j++) {
            if (requests[j] == i) {
                totalHeadMovement += absDiff(currentHead, requests[j]);
                currentHead = requests[j];
                requests[j]=-1;
                printf("%d ", currentHead);
            }
        }
    }
    
    totalHeadMovement += absDiff(currentHead,199);
    currentHead=199;
    
    // Processing requests towards the left
    for (int i = 199; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (requests[j] == i) {
                totalHeadMovement += absDiff(currentHead, requests[j]);
                currentHead = requests[j];
                printf("%d ", currentHead);
            }
        }
    }

    printf("\nTotal Head Movement: %d\n\n", totalHeadMovement);
}

// Function to simulate C-SCAN disk scheduling algorithm
void C_SCAN(int *requests, int n, int start) {
    int totalHeadMovement = 0;
    printf("C-SCAN Disk Scheduling Algorithm:\n");

    int currentHead = start;
    printf("Order of processing requests: ");

    // Processing requests towards the right
    for (int i = currentHead; i <= 199; i++) {
        for (int j = 0; j < n; j++) {
            if (requests[j] == i) {
                totalHeadMovement += absDiff(currentHead, requests[j]);
                currentHead = requests[j];
                printf("%d ", currentHead);
            }
        }
    }
    // Processing requests towards the left from the beginning
    totalHeadMovement += 199 - currentHead;
    int flag=0;
    currentHead = 0;
    printf("0 ");
    // Processing remaining requests towards the right
    for (int i = 0; i < start; i++) {
        for (int j = 0; j < n; j++) {
            if (requests[j] == i) {
            	flag=1;
                totalHeadMovement += absDiff(currentHead, requests[j]);
                currentHead = requests[j];
                printf("%d ", currentHead);
            }
        }
    }
    if(flag==1)
    {
    	totalHeadMovement+=199;
    }

    printf("\nTotal Head Movement: %d\n\n", totalHeadMovement);
}

// Function to simulate C-LOOK disk scheduling algorithm
void C_LOOK(int *requests, int n, int start) {
    int totalHeadMovement = 0;
    printf("C-LOOK Disk Scheduling Algorithm:\n");

    int currentHead = start;
    printf("Order of processing requests: ");

    // Processing requests towards the right
    for (int i = currentHead; i <= 199; i++) {
        for (int j = 0; j < n; j++) {
            if (requests[j] == i) {
                totalHeadMovement += absDiff(currentHead, requests[j]);
                currentHead = requests[j];
                printf("%d ", currentHead);
            }
        }
    }
    // Processing remaining requests towards the left
    for (int i = 0; i < start; i++) {
        for (int j = 0; j < n; j++) {
            if (requests[j] == i) {
                totalHeadMovement += absDiff(currentHead, requests[j]);
                currentHead = requests[j];
                printf("%d ", currentHead);
            }
        }
    }

    printf("\nTotal Head Movement: %d\n\n", totalHeadMovement);
}

int main() {
    int n, start, choice;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int *requests = (int *)malloc(n * sizeof(int));

    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial position of the disk head (0-199): ");
    scanf("%d", &start);

    printf("Choose the disk scheduling algorithm:\n");
    printf("1. Shortest Seek Time First (SSTF)\n");
    printf("2. SCAN\n");
    printf("3. C-SCAN\n");
    printf("4. C-LOOK\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            SSTF(requests, n, start);
            break;
        case 2:
            SCAN(requests, n, start, 1);
            break;
        case 3:
            C_SCAN(requests, n, start);
            break;
        case 4:
            C_LOOK(requests, n, start);
            break;
        default:
            printf("Invalid choice!\n");
    }

    free(requests);
    return 0;
}
