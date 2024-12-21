#pragma once

struct Node
{
    int data;
    Node* next;
};

void addNode(Node*& head, int value);
void addNodeEnd(Node*& head, int value);
void removeComposite(Node*& head);
void duplicatePrimes(Node*& head);
bool containsDigit(int num, int digit);
bool isPrime(int num);
void sortList(Node*& head);
void printList(Node* head);
int getFirstDigit(int num);
int getLastDigit(int num);
bool isOrdered(Node* head);