
// CPP program to implement Brent's cycle  
// detection algorithm to detect cycle in 
// a linked list. 
#include <stdio.h> 
#include <stdlib.h> 
  
/* Link list node */
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
/* This function detects loop in the list 
If loop was there in the list then it returns, 
the first node of loop otherwise returns NULL */
struct Node* detectCycle(struct Node* head) 
{ 
    // if head is null then no loop 
    if (head == NULL)  
        return NULL;     
  
    struct Node* first_pointer = head; 
    struct Node* second_pointer = head->next; 
    int power = 1; 
    int length = 1; 
  
    // This loop runs till we find the loop. 
    // If there is no loop then second_pointer 
    // ends at NULL . 
    while (second_pointer != NULL &&  
           second_pointer != first_pointer) { 
  
        // condition after which we will 
        // update the power and length as 
        // smallest power of two gives the 
        // start of cycle. 
        if (length == power) { 
  
            // updating the power. 
            power *= 2; 
  
            // updating the length 
            length = 0; 
  
            first_pointer = second_pointer; 
        } 
  
        second_pointer = second_pointer->next; 
        ++length; 
    } 
  
    // if it is null then no loop 
    if (second_pointer == NULL)  
        return NULL;     
  
    // Otherwise length stores actual length  
    // of loop. 
    // If needed, we can also print length of 
    // loop. 
    // printf("Length of loop is %d\n", length); 
  
    // Now set first_pointer to the beginning 
    // and second_pointer to beginning plus 
    // cycle length which is length. 
    first_pointer = second_pointer = head; 
    while (length > 0) { 
        second_pointer = second_pointer->next; 
        --length; 
    } 
  
    // Now move both pointers at same speed so 
    // that they meet at the beginning of loop. 
    while (second_pointer != first_pointer) { 
        second_pointer = second_pointer->next; 
        first_pointer = first_pointer->next; 
    } 
  
    // If needed, we can also print length of 
    // loop. 
    // printf("Length of loop is %d", length); 
  
    return first_pointer; 
} 
  
struct Node* newNode(int key) 
{ 
    struct Node* temp =  
      (struct Node*)malloc(sizeof(struct Node)); 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 
  
// Driver program to test above function 
int main() 
{ 
    struct Node* head = newNode(50); 
    head->next = newNode(20); 
    head->next->next = newNode(15); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(10); 
  
    // Create a loop for testing  
    head->next->next->next->next->next =  
                              head->next->next; 
  
    Node *res = detectCycle(head); 
    if (res == NULL) 
        printf("No loop"); 
    else
        printf("Loop is present at %d", res->data); 
    return 0; 
} 
