#include <cstdio>

struct Element {
    Element* next{};     
    Element* previous{}; 

    
    void insert_after(Element* new_element) {
        new_element->next = next;
        new_element->previous = this;
        if (next) {
            next->previous = new_element;
        }
        next = new_element;
    }

    
    void insert_before(Element* new_element) {
        new_element->previous = previous;
        new_element->next = this;
        if (previous) {
            previous->next = new_element;
        }
        previous = new_element;
    }

    char prefix[2];          
    short operating_number;
};

int main() {
    
    Element a, b, c;

    
    a.operating_number = 100;
    b.operating_number = 200;
    c.operating_number = 300;

    
    a.insert_after(&b); 
    b.insert_after(&c); 

    
    printf("Forward traversal:\n");
    for (Element* current = &a; current != nullptr; current = current->next) {
        printf("%d\n", current->operating_number);
    }

    
    Element* tail = &a;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    
    printf("Backward traversal:\n");
    for (Element* current = tail; current != nullptr; current = current->previous) {
        printf("%d\n", current->operating_number);
    }

    return 0;
}