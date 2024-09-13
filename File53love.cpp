/*
Q.1. You want to play with your friend,but your friend has pending homework,
help him complete that.
You are given a Head of a sorted linked list. You can remove some values from
the linked list.In the end,you must return a sorted linked list that contains
no adjacent values that are equal.
For example:-
If the given linked list is: 1->2->2->3
Then we will delete the duplicate value 2 present in the linked list, and finally
return the following list:
1 -> 2 -> 3

Aage ka input format and constraints nhi likhe ab seedhe solution likh raha hu
Question basically h remove duplicates from sorted linked list
*/

/*
// Time complexity = O(n)
// space complexity = O(1)

Node* uniqueSortedList(Node * head)
{
    // empty list
    if(head == NULL)
    {
        return NULL;
    }

    // Non-empty list
    Node* curr = head;
    while(curr != NULL)
    {
        if((curr->next != NULL) && (curr->data == curr->next->data))
        {
            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;
            delete(nodeTodelete);
            curr->next = next_next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}
*/