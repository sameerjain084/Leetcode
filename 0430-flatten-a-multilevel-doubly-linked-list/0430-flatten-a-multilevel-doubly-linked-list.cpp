class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) {
            return head;
        }

        Node* curr = head;

        while (curr != NULL) {

            // If there is no child, simply move forward
            if (curr->child == NULL) {
                curr = curr->next;
                continue;
            }

            // Save the original next node
            Node* next = curr->next;

            // Flatten the child list
            Node* child = flatten(curr->child);

            // Connect curr to child
            curr->next = child;
            child->prev = curr;

            // Remove child pointer
            curr->child = NULL;

            // Find the tail of the flattened child list
            Node* tail = child;

            while (tail->next != NULL) {
                tail = tail->next;
            }

            // Connect tail to original next
            if (next != NULL) {
                tail->next = next;
                next->prev = tail;
            }

            // Continue from the original next
            curr = tail;
        }

        return head;
    }
};