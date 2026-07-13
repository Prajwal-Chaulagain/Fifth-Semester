// Write a c program to implement for Huffman Coding.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

// Huffman Tree Node
struct Node
{
    char data;
    unsigned freq;
    struct Node *left, *right;
};

// Min Heap structure
struct MinHeap
{
    unsigned size;
    unsigned capacity;
    struct Node *array[MAX];
};

// Create node
struct Node *newNode(char data, unsigned freq)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Create Min Heap
struct MinHeap *createMinHeap(unsigned capacity)
{
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    return minHeap;
}

// Swap nodes
void swap(struct Node **a, struct Node **b)
{
    struct Node *t = *a;
    *a = *b;
    *b = t;
}

// Heapify
void minHeapify(struct MinHeap *heap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;

    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx)
    {
        swap(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

// Extract minimum
struct Node *extractMin(struct MinHeap *heap)
{
    struct Node *temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return temp;
}

// Insert into heap
void insertHeap(struct MinHeap *heap, struct Node *node)
{
    heap->size++;
    int i = heap->size - 1;

    while (i && node->freq < heap->array[(i - 1) / 2]->freq)
    {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

// Build initial heap
void buildHeap(struct MinHeap *heap)
{
    int n = heap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; i--)
        minHeapify(heap, i);
}

// Print codes
void printCodes(struct Node *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right)
    {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Build Huffman Tree
struct Node *buildHuffman(char data[], int freq[], int n)
{
    struct MinHeap *heap = createMinHeap(n);

    for (int i = 0; i < n; i++)
        heap->array[heap->size++] = newNode(data[i], freq[i]);

    buildHeap(heap);

    while (heap->size > 1)
    {
        struct Node *left = extractMin(heap);
        struct Node *right = extractMin(heap);

        struct Node *top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertHeap(heap, top);
    }

    return extractMin(heap);
}

// Driver
int main()
{
    int n;
    clock_t start, end;
    char data[MAX];
    int freq[MAX];

    printf("Enter number of characters: ");
    scanf("%d", &n);

    printf("Enter characters:\n");
    for (int i = 0; i < n; i++)
        scanf(" %c", &data[i]);

    printf("Enter frequencies:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &freq[i]);
    start = clock();
    struct Node *root = buildHuffman(data, freq, n);

    int arr[MAX], top = 0;
    printf("\nHuffman Codes:\n");
    printCodes(root, arr, top);
    end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_taken);

    return 0;
}
