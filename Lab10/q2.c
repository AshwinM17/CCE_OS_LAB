#include <stdio.h>
#include <stdlib.h>

// Structure to represent a page node
typedef struct Page {
    int pageNumber;
    struct Page *next;
    struct Page *prev;
} Page;

// Structure to represent a queue of pages
typedef struct Queue {
    Page *front, *rear;
    int count;
    int capacity;
} Queue;

// Function to create a new page node
Page* createPage(int pageNumber) {
    Page* page = (Page*)malloc(sizeof(Page));
    page->pageNumber = pageNumber;
    page->next = NULL;
    page->prev = NULL;
    return page;
}

// Function to create a new queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    queue->count = 0;
    queue->capacity = capacity;
    return queue;
}

// Function to check if the queue is full
int isQueueFull(Queue* queue) {
    return queue->count == queue->capacity;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue* queue) {
    return queue->count == 0;
}

// Function to remove a page from the queue
void deQueue(Queue* queue) {
    if (isQueueEmpty(queue))
        return;
    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->rear = queue->rear->prev;
        queue->rear->next = NULL;
    }
    queue->count--;
}

// Function to add a page to the queue
void enQueue(Queue* queue, Page* page) {
    if (isQueueFull(queue)) {
        deQueue(queue);
    }
    if (isQueueEmpty(queue)) {
        queue->front = page;
        queue->rear = page;
    } else {
        page->next = queue->front;
        queue->front->prev = page;
        queue->front = page;
    }
    queue->count++;
}

// Function to check if a page is present in the queue
int isPagePresent(Queue* queue, int pageNumber) {
    Page* temp = queue->front;
    while (temp != NULL) {
        if (temp->pageNumber == pageNumber)
            return 1;
        temp = temp->next;
    }
    return 0;
}

// Function to simulate LRU page replacement algorithm
void LRU(int* refString, int refLength, int numOfFrames) {
    Queue* queue = createQueue(numOfFrames);
    int pageFaults = 0;

    for (int i = 0; i < refLength; i++) {
        int currentPage = refString[i];
        if (!isPagePresent(queue, currentPage)) {
            if (!isQueueFull(queue)) {
                enQueue(queue, createPage(currentPage));
            } else {
                deQueue(queue);
                enQueue(queue, createPage(currentPage));
            }
            pageFaults++;
        } else {
            // If page is already in the queue, move it to the front
            Page* temp = queue->front;
            while (temp != NULL) {
                if (temp->pageNumber == currentPage) {
                    if (temp != queue->front) {
                        temp->prev->next = temp->next;
                        if (temp->next != NULL) {
                            temp->next->prev = temp->prev;
                        } else {
                            queue->rear = temp->prev;
                        }
                        temp->next = queue->front;
                        temp->prev = NULL;
                        queue->front->prev = temp;
                        queue->front = temp;
                    }
                    break;
                }
                temp = temp->next;
            }
        }
    }

    printf("LRU Page Replacement Algorithm:\n");
    printf("Number of Page Faults: %d\n\n", pageFaults);

    // Free allocated memory
    while (queue->front != NULL) {
        Page* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
}

int main() {
    int numOfFrames, refLength;

    printf("Enter the number of frames: ");
    scanf("%d", &numOfFrames);

    printf("Enter the length of reference string: ");
    scanf("%d", &refLength);

    int* refString = (int*)malloc(refLength * sizeof(int));

    printf("Enter the reference string: ");
    for (int i = 0; i < refLength; i++) {
        scanf("%d", &refString[i]);
    }

    LRU(refString, refLength, numOfFrames);

    free(refString);
    return 0;
}
