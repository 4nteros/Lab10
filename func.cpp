#include "func.hpp"
#include <iostream>

void addNode(Node*& head, int value) //Добавление узла в список
{
    Node* newNode = new Node{value, head};
    head = newNode;
}


void addNodeEnd(Node*& head, int value)
{
    Node* newNode = new Node{ value, nullptr };
    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node* current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}


bool isPrime(int num) //Проверка на составное/простое число
{
    if (num < 2) 
        return false;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void removeComposite(Node*& head) // Удаление составных чисел из списка
{
    Node *current = head;
    Node *prev = nullptr;

    while (current)
    {
        if (!isPrime(current->data))
        {
            if (prev)
            {
                prev->next = current->next;
                delete current;
                current = prev->next;
            } 

            else
            {
                head = current->next;
                delete current;
                current = head;
            }
        }
        
        else
        {
            prev = current;
            current = current->next;
        }
    }
}

bool containsDigit(int num, int digit)
{
    while (num > 0)
    {
        if (num % 10 == digit) return true;
        num /= 10;
    }
    return false;
}

void duplicatePrimes(Node*& head) // Дублирование простых чисел, содержащих цифры 1, 5 или 7
{
    Node* current = head;
    while (current)
    {
        if (isPrime(current->data) && (containsDigit(current->data, 1) || containsDigit(current->data, 5) || containsDigit(current->data, 7)))
        {
            Node* newNode = new Node{ current->data, current->next };
            current->next = newNode; // Добавляем новый узел после текущего
            current = newNode->next; 
        }
        else
        {
            current = current->next;
        }
    }
}

int getFirstDigit(int num)
{
    while (num >= 10) 
        num /= 10;
    return num;
}

int getLastDigit(int num)
{
    return num % 10;
}

bool isOrdered(Node* head)
{
    if (!head || !head->next) 
        return true;
    
    Node* current = head;
    int firstDigit = getFirstDigit(current->data);

    while (current->next)
    {
        current = current->next;
        int curFirstDigit = getFirstDigit(current->data);
        if (curFirstDigit < firstDigit)
        {
            return false;
        }

        firstDigit = curFirstDigit;
    }
    return true;
}

void sortList(Node*& head)  // Сортировка списка (сортировка вставками)
{
    if (!head) return;
    Node* sorted = nullptr;
    Node* current = head;

    while (current)
    {
        Node* next = current->next;
        if (!sorted || sorted->data >= current->data)
        {
            current->next = sorted;
            sorted = current;
        }
        
        else
        {
            Node* temp = sorted;
            while (temp->next && temp->next->data < current->data)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    head = sorted;
}

void printList(Node* head)
{
    Node* current = head;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
