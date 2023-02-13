class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
  // Write your code here.
  LinkedList *prev = linkedList;
  LinkedList *curr = linkedList;
  while(curr){
    do{
        curr = curr->next;
    }
    while(curr and curr->value == prev->value);
    prev->next = curr;
    prev = prev->next;
  }
  return linkedList;
}
