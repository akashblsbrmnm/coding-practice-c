#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

// ─── Insert at beginning ───────────────────────────────────────────────────
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// ─── Insert at end ─────────────────────────────────────────────────────────
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// ─── Insert in sorted order (ascending) ───────────────────────────────────
Node* insertSorted(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || value < head->data) {
        newNode->next = head;
        return newNode;
    }

    Node* curr = head;
    while (curr->next != NULL && curr->next->data < value)
        curr = curr->next;

    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

// ─── Insert at given position (0-based) ───────────────────────────────────
Node* insertAtPosition(Node* head, int value, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (position == 0) {
        newNode->next = head;
        return newNode;
    }

    Node* curr = head;
    for (int i = 0; i < position - 1 && curr != NULL; i++)
        curr = curr->next;

    if (curr == NULL) { free(newNode); return head; }

    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

// ─── Search ────────────────────────────────────────────────────────────────
void search(Node* head, int val) {
    printf("Searching for %d...\n", val);
    int pos = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == val) {
            printf("Found at position: %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Not found\n");
}

// ─── Delete by value ───────────────────────────────────────────────────────
Node* deleteNodeByValue(Node* head, int val) {
    if (head == NULL) { printf("List is empty\n"); return NULL; }

    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* curr = head;
    while (curr->next != NULL && curr->next->data != val)
        curr = curr->next;

    if (curr->next == NULL) {
        printf("Node with value %d not found\n", val);
        return head;
    }

    Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
    return head;
}

// ─── Delete at position (0-based) ─────────────────────────────────────────
Node* deleteNodeAtPosition(Node* head, int position) {
    if (head == NULL) return NULL;

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;
    int i = 0;

    while (curr != NULL && i < position) {
        prev = curr;
        curr = curr->next;
        i++;
    }

    if (curr == NULL) return head;

    prev->next = curr->next;
    free(curr);
    return head;
}

// ─── Delete by node pointer (copy-forward trick) ──────────────────────────
void deleteByNode(Node* node) {
    if (node == NULL || node->next == NULL) {
        printf("Cannot delete this node (NULL or tail node)\n");
        return;
    }
    Node* temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    free(temp);
}

// ─── Reverse list ──────────────────────────────────────────────────────────
// Now takes head as param and returns new head — consistent with all other functions.
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;  // new head
}

// ─── Print list ───────────────────────────────────────────────────────────
void printList(Node* head) {
    if (!head) { printf("List is empty\n"); return; }
    Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ─── Detect cycle (bool) ──────────────────────────────────────────────────
bool hasCycle(Node* head) {
    if (head == NULL) return false;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// ─── Find cycle start (Floyd's) ───────────────────────────────────────────
Node* detectCycle(Node* head) {
    if (head == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

// ─── Remove loop ──────────────────────────────────────────────────────────
void removeLoop(Node* head) {
    Node* loopStart = detectCycle(head);
    if (!loopStart) return;

    Node* temp = loopStart;
    while (temp->next != loopStart)
        temp = temp->next;

    temp->next = NULL;
}

// ─── Intersection of two lists ────────────────────────────────────────────
Node* getIntersectionNode(Node* headA, Node* headB) {
    if (!headA || !headB) return NULL;
    Node* p1 = headA;
    Node* p2 = headB;
    while (p1 != p2) {
        p1 = p1 ? p1->next : headB;
        p2 = p2 ? p2->next : headA;
    }
    return p1;
}

// ─── Palindrome check ─────────────────────────────────────────────────────
bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;

    // step 1: find middle
    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // step 2: reverse second half
    Node* second = reverseList(slow->next);

    // step 3: compare
    Node* left  = head;
    Node* right = second;
    bool result = true;
    while (right) {
        if (left->data != right->data) { result = false; break; }
        left  = left->next;
        right = right->next;
    }

    // step 4: restore list
    slow->next = reverseList(second);

    return result;
}

// ─── Find Middle ─────────────────────────────────────────────────────
Node* middleNode(Node* head) {
    if(head == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// ─── Driver / menu ────────────────────────────────────────────────────────
int main() {
    // ── demo: intersection ──────────────────────────────────────────────
    printf("=== Intersection Demo ===\n");
    // build: A = 1->2->3->6->7, B = 4->5->6->7 (shared tail 6->7)
    Node* shared   = insertAtEnd(NULL, 6);
    shared         = insertAtEnd(shared, 7);

    Node* listA    = insertAtEnd(NULL, 1);
    listA          = insertAtEnd(listA, 2);
    listA          = insertAtEnd(listA, 3);
    // attach shared tail
    Node* tempA    = listA;
    while (tempA->next) tempA = tempA->next;
    tempA->next    = shared;

    Node* listB    = insertAtEnd(NULL, 4);
    listB          = insertAtEnd(listB, 5);
    Node* tempB    = listB;
    while (tempB->next) tempB = tempB->next;
    tempB->next    = shared;

    Node* inter = getIntersectionNode(listA, listB);
    if (inter) printf("Intersection at node with value: %d\n", inter->data);
    else       printf("No intersection\n");

    // detach shared tail to avoid double-free
    tempA->next = NULL;
    tempB->next = NULL;
    // free lists
    Node *cur, *nxt;
    for (cur = listA; cur; cur = nxt) { nxt = cur->next; free(cur); }
    for (cur = listB; cur; cur = nxt) { nxt = cur->next; free(cur); }
    for (cur = shared; cur; cur = nxt) { nxt = cur->next; free(cur); }

    // ── demo: palindrome ────────────────────────────────────────────────
    printf("\n=== Palindrome Demo ===\n");
    Node* pal1 = NULL;
    pal1 = insertAtEnd(pal1, 1);
    pal1 = insertAtEnd(pal1, 2);
    pal1 = insertAtEnd(pal1, 2);
    pal1 = insertAtEnd(pal1, 1);
    printf("List: "); printList(pal1);
    printf("Is palindrome: %s\n", isPalindrome(pal1) ? "true" : "false");
    for (cur = pal1; cur; cur = nxt) { nxt = cur->next; free(cur); }

    Node* pal2 = NULL;
    pal2 = insertAtEnd(pal2, 1);
    pal2 = insertAtEnd(pal2, 2);
    pal2 = insertAtEnd(pal2, 3);
    printf("List: "); printList(pal2);
    printf("Is palindrome: %s\n", isPalindrome(pal2) ? "true" : "false");
    for (cur = pal2; cur; cur = nxt) { nxt = cur->next; free(cur); }

    // ── interactive menu ────────────────────────────────────────────────
    int choice, value, position;
    while (1) {
        printf("\n--- Linked List Operations ---\n");
        printf("1.  Insert at beginning\n");
        printf("2.  Insert at end\n");
        printf("3.  Insert sorted\n");
        printf("4.  Insert at position\n");
        printf("5.  Delete by value\n");
        printf("6.  Delete at position\n");
        printf("7.  Delete by node pointer\n");
        printf("8.  Search\n");
        printf("9.  Reverse\n");
        printf("10. Print\n");
        printf("11. Detect cycle\n");
        printf("12. Remove loop\n");
        printf("13. Check palindrome\n");
        printf("14. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: "); scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 2:
                printf("Enter value: "); scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 3:
                printf("Enter value: "); scanf("%d", &value);
                head = insertSorted(head, value);
                break;
            case 4:
                printf("Enter value and position: "); scanf("%d %d", &value, &position);
                head = insertAtPosition(head, value, position);
                break;
            case 5:
                printf("Enter value to delete: "); scanf("%d", &value);
                head = deleteNodeByValue(head, value);  // FIX: now returns new head
                break;
            case 6:
                printf("Enter position to delete: "); scanf("%d", &position);
                head = deleteNodeAtPosition(head, position);
                break;
            case 7:
                printf("Enter value to delete by node pointer: "); scanf("%d", &value);
                {
                    Node* temp = head;
                    while (temp != NULL && temp->data != value)
                        temp = temp->next;
                    if (temp == NULL)          printf("Node not found\n");
                    else if (temp->next == NULL) printf("Cannot delete tail node by pointer\n");
                    else                        deleteByNode(temp);
                }
                break;
            case 8:
                printf("Enter value to search: "); scanf("%d", &value);
                search(head, value);  // FIX: pass head as param
                break;
            case 9:
                head = reverseList(head);  // FIX: capture returned new head
                printf("List reversed\n");
                break;
            case 10:
                printList(head);  // FIX: pass head as param
                break;
            case 11:
                printf(hasCycle(head) ? "Cycle detected\n" : "No cycle\n");
                break;
            case 12:
                removeLoop(head);
                printf("Loop removed if existed\n");
                break;
            case 13:
                printf(isPalindrome(head) ? "Is a palindrome\n" : "Not a palindrome\n");
                break;
            case 14:
                // free list before exit
                for (cur = head; cur; cur = nxt) { nxt = cur->next; free(cur); }
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}