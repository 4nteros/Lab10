#include "func.hpp"
#include <iostream>



int main()
{
    Node* head = nullptr;
    int q = 0; //количество членов посл-ти 
    int n = 0;
    std::cout << "Input number of sequence members: " << std::endl;
    std::cin >> q;
    if (q <= 0)
    {
        std::cout << "Number of sequence members must be greater than zero." << std::endl;
        return 0;
    }


    std::cout << "Enter sequence member: ";
    for (int i = 0; i < q; i++)
    {
        std::cin >> n;
        addNode(head, n);
    }

    if (head)
    {
        if (isOrdered(head))
        {
            removeComposite(head);
            duplicatePrimes(head);
        }
        else
        {
            sortList(head);
        }
    }

    std::cout << "Resulting sequence: ";
    printList(head);

    // Освобождение памяти
    while (head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}