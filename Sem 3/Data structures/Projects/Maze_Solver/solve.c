#include <stdio.h>
#include <stdlib.h>

//==============================================================================

struct Node {
    int x, y;
    struct Node *parent;
    struct Node *next;
};

struct Node *newNode (struct Node *parent_, int delx, int dely) {
    struct Node *new;
    new = (struct Node *) malloc (sizeof(struct Node));
    new->parent = parent_;
    new->x = new->parent->x + delx;
    new->y = new->parent->y + dely;
    new->next = new;
    return new;
}


//==============================================================================



struct Queue {
    struct Node *rear;
};

struct Queue *newQueue (int src_x, int src_y) {
    struct Node *SEED = (struct Node *) malloc (sizeof(struct Node));
    SEED->x = src_x;
    SEED->y = src_y;
    SEED->parent = NULL;
    SEED->next = SEED;

    struct Queue *new = (struct Queue *) malloc (sizeof(struct Queue));
    new->rear = SEED;
    return new;
}

void enQueue (struct Queue *q, struct Node *insertNode) {
    insertNode->next = q->rear->next;
    q->rear->next = insertNode;
    q->rear = insertNode;
}

struct Node *deQueue (struct Queue *q) {
    struct Node *deleteNode  = q->rear->next;
    q->rear->next = q->rear->next->next;
    return deleteNode;
}


//==============================================================================


struct Node *simulateMaze (int rows, int cols, int arr[rows][cols], struct Queue *q) {
    struct Node *thisNode = deQueue(q);

    if (arr[thisNode->x][thisNode->y] == 3) return thisNode;
    else {
        if (arr[thisNode->x +1][thisNode->y] != 1){
            arr[thisNode->x +1][thisNode->y] == 1;
            enQueue (q, newNode(thisNode, 1, 0));
        }
        if (arr[thisNode->x -1][thisNode->y] != 1){
            arr[thisNode->x -1][thisNode->y] == 1;
            enQueue (q, newNode(thisNode, -1, 0));
        }
        if (arr[thisNode->x][thisNode->y +1] != 1){
            arr[thisNode->x][thisNode->y +1] == 1;
            enQueue (q, newNode(thisNode, 0, 1));
        }
        if (arr[thisNode->x][thisNode->y -1] != 1){
            arr[thisNode->x][thisNode->y -1] == 1;
            enQueue (q, newNode(thisNode, 0, -1));
        }
    }
    if (q->rear->next == q->rear){
        printf("ERROR : No solution found\n");
        exit(0);
    }
    return NULL;
}

void getSolution (struct Node *destinationNode, int rows, int cols, int arr[rows][cols]) {
    struct Node *temp = destinationNode;
    printf("getSolution OP :\n");
    while (temp != NULL) {
        arr[temp->x][temp->y] = 4;
        printf ("%d %d\n", temp->x, temp->y);
        temp = temp->parent;
    }
}


//==============================================================================


int main(int argc, char const *argv[]) {
    FILE *maze;
    maze = fopen ("maze.txt", "r");


    int rows = -1, cols = -1;
    fscanf (maze, "%d %d", &rows, &cols);
    printf("DIM = %d %d\n", rows, cols);

    int arr[rows][cols];
    int src_x = -1, src_y = -1, dst_x = -1, dst_y = -1;

    int row = 0, col = 0;
    for (row = 0; row < rows; row++) {
        for (col = 0; col < cols; col++) {
            fscanf (maze, "%d", &arr[row][col]);
            if (arr[row][col] == 2){
                src_x = row;
                src_y = col;
            }
            else if (arr[row][col] == 3) {
                dst_x = row;
                dst_y = col;
            }
        }
    }


    if (src_x <0 || src_y < 0 || dst_x < 0 || dst_y < 0) {
        printf ("ERROR : No source or destination found\n");
    }
    else {
        printf ("SRC = %d , %d\n", src_x, src_y);
        printf ("DST = %d , %d\n", dst_x, dst_y);
    }

    struct Node *SEED;
    SEED = (struct Node *) malloc (sizeof(struct Node));
    SEED->x = src_x;
    SEED->y = src_y;
    SEED->parent = NULL;
    SEED->next = SEED;

    struct Queue *q = newQueue(src_x, src_y);

    struct Node *destinationNode = NULL;
    while (destinationNode == NULL) destinationNode = simulateMaze(rows, cols, arr, q);
    printf("DESTINATION = %d , %d\n", destinationNode->x, destinationNode->y);

    getSolution(destinationNode, rows, cols, arr);

    FILE *solution;
    solution = fopen("solution.txt", "w+");
    fprintf(solution, "%d %d\n", rows, cols);
    for (row = 0; row < rows; row++){
        for (col = 0; col < cols; col++){
            fprintf(solution, "%d ", arr[row][col]);
        }
        fprintf(solution, "\n");
    }
    return 0;
}
