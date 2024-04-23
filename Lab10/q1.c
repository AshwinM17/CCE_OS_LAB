#include <stdio.h>
#include <stdlib.h>

// Function to find the index of the page to be replaced in FIFO algorithm
int findFIFOIndex(int *pages, int numOfFrames, int currentPage) {
    int index = -1;
    for (int i = 0; i < numOfFrames; i++) {
        if (pages[i] == currentPage) {
            index = i;
            break;
        }
    }
    return index;
}

// Function to find the index of the page that will not be used for longest time in Optimal algorithm
int findOptimalIndex(int *pages, int numOfFrames, int *refString, int refLength, int currentIndex) {
    int index = -1, farthest = currentIndex;
    for (int i = 0; i < numOfFrames; i++) {
        int j;
        for (j = currentIndex; j < refLength; j++) {
            if (pages[i] == refString[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        // If page not found in future reference string, return its index
        if (j == refLength)
            return i;
    }
    return index;
}

// Function to simulate FIFO page replacement algorithm
void FIFO(int *refString, int refLength, int numOfFrames) {
    int *frames = (int *)malloc(numOfFrames * sizeof(int));
    int pageFaults = 0;

    for (int i = 0; i < refLength; i++) {
        int currentPage = refString[i];

        // Check if page is already in memory
        if (findFIFOIndex(frames, numOfFrames, currentPage) == -1) {
         
            frames[pageFaults % numOfFrames] = currentPage;
            pageFaults++;
        }
    }

    printf("FIFO Page Replacement Algorithm:\n");
    printf("Number of Page Faults: %d\n\n", pageFaults);
    free(frames);
}

// Function to simulate Optimal page replacement algorithm
void optimal(int *refString, int refLength, int numOfFrames) {
    int *frames = (int *)malloc(numOfFrames * sizeof(int));
    int pageFaults = 0;
    int currentFrame = 0;

    for (int i = 0; i < refLength; i++) {
        int currentPage = refString[i];

        // Check if page is already in memory
        if (findFIFOIndex(frames, numOfFrames, currentPage) == -1) {
            // If frame is not full, insert page
            if (currentFrame < numOfFrames) {
                frames[currentFrame++] = currentPage;
            } else { // If frame is full, replace page using optimal algorithm
                int index = findOptimalIndex(frames, numOfFrames, refString, refLength, i + 1);
                frames[index] = currentPage;
            }
            pageFaults++;
        }
    }

    printf("Optimal Page Replacement Algorithm:\n");
    printf("Number of Page Faults: %d\n\n", pageFaults);
    free(frames);
}

int main() {
    int numOfFrames, refLength;

    printf("Enter the number of frames: ");
    scanf("%d", &numOfFrames);

    printf("Enter the length of reference string: ");
    scanf("%d", &refLength);

    int *refString = (int *)malloc(refLength * sizeof(int));

    printf("Enter the reference string: ");
    for (int i = 0; i < refLength; i++) {
        scanf("%d", &refString[i]);
    }

    FIFO(refString, refLength, numOfFrames);
    optimal(refString, refLength, numOfFrames);

    free(refString);
    return 0;
}
