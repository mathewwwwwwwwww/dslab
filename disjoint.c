#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *rep;   
    struct node *next;  
    int data;           
};

struct node* heads[50];  
struct node* tails[50];  
static int countRoot = 0; 

void makeSet(int x) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->rep = new;
    new->next = NULL;
    new->data = x;
    heads[countRoot] = new;
    tails[countRoot] = new;
    countRoot++;
}

struct node* find(int a) {
    for (int i = 0; i < countRoot; i++) {
        struct node *tmp = heads[i];
        while (tmp != NULL) {
            if (tmp->data == a)
                return tmp->rep;
            tmp = tmp->next;
        }
    }
    return NULL;  
}
void unionSets(int a, int b) {
    struct node *rep1 = find(a);
    struct node *rep2 = find(b);

    if (rep1 == NULL || rep2 == NULL) {
        printf("\nElement(s) not present in the DS\n");
        return;
    }
    if (rep1 != rep2) {
        int pos = -1;
        for (int i = 0; i < countRoot; i++) {
            if (heads[i] == rep2) {
                pos = i;
                break;
            }
        }

        if (pos != -1) {
            for (int i = pos; i < countRoot - 1; i++) {
                heads[i] = heads[i + 1];
                tails[i] = tails[i + 1];
            }
            countRoot--;
        }

        tails[rep1->data]->next = rep2;
        tails[rep1->data] = tails[rep2->data];

        struct node *tmp = rep2;
        while (tmp != NULL) {
            tmp->rep = rep1;
            tmp = tmp->next;
        }
    }
}

int search(int x) {
    for (int i = 0; i < countRoot; i++) {
        struct node *tmp = heads[i];
        while (tmp != NULL) {
            if (tmp->data == x)
                return 1;
            tmp = tmp->next;
        }
    }
    return 0; 
}

void displaySets() {
    printf("\nSets:\n");
    for (int i = 0; i < countRoot; i++) {
        struct node *temp = heads[i];
        printf("Set %d: { ", i + 1);
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("}\n");
    }
}

void main() {
    int choice, x, y;

    do {
        printf("\n1. Make Set\n2. Display Set Representatives\n3. Union\n4. Find Set\n5. Display Sets\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("\nEnter new element: ");
                scanf("%d", &x);
                if (search(x)) {
                    printf("\nElement already present in the disjoint set DS\n");
                } else {
                    makeSet(x);
                }
                break;

            case 2:
                printf("\nSet Representatives: ");
                for (int i = 0; i < countRoot; i++) {
                    printf("%d ", heads[i]->data);
                }
                printf("\n");
                break;

            case 3:
                printf("\nEnter first element: ");
                scanf("%d", &x);
                printf("\nEnter second element: ");
                scanf("%d", &y);
                unionSets(x, y);
                break;

            case 4: 
                printf("\nEnter the element: ");
                scanf("%d", &x);
                struct node *rep = find(x);
                if (rep == NULL) {
                    printf("\nElement not present in the DS\n");
                } else {
                    printf("\nThe representative of %d is %d\n", x, rep->data);
                }
                break;

            case 5: 
                displaySets();
                break;

            case 6: 
                exit(0);
                break;

            default:
                printf("\nWrong choice\n");
                break;
        }
    } while (1);
}
