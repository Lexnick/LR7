#include <iostream>

struct Node {
    Node *next = nullptr;
    int Data = 0;
};

struct Stack {
    Node *Last;
};
struct Queue {
    Node *First;
    Node *Last;
};


void constructor(Stack &stack) {
    stack.Last = nullptr;
}

void constructor(Queue &queue) {
    queue.First = nullptr;
    queue.Last = nullptr;
}

void destructor(Stack &stack) {
    while (stack.Last != nullptr) {
        Node *Element = stack.Last->next;
        delete stack.Last;
        stack.Last = Element;
    }
}

void destructor(Queue &queue) {
    while (queue.First != nullptr) {
        Node *Element = queue.First->next;
        delete queue.First;
        queue.First = Element;
    }
    queue.Last= nullptr;
}

unsigned int size(const Stack &stack) {
    unsigned int CountOut = 0;
    if (stack.Last != nullptr) {
        Node *Element = stack.Last;
        while (Element != nullptr) {
            CountOut++;
            Element = Element->next;
        }
    }
    return CountOut;
}

unsigned int size(const Queue &queue) {
    unsigned int CountOut = 0;
    if (queue.First != nullptr) {
        Node *Element = queue.First;
        while (Element != nullptr) {
            CountOut++;
            Element = Element->next;
        }
    }
    return CountOut;
}

void push(Stack &stack, Node &node) {
    Node *Element = new Node;
    Element->Data = node.Data;
    Element->next = stack.Last;
    stack.Last = Element;
}

void push(Queue &queue, Node &node) {
    if ((queue.First == nullptr) && (queue.Last == nullptr)) {
        Node *Element = new Node;
        Element->Data = node.Data;
        Element->next = nullptr;
        queue.First = Element;
    } else if ((queue.First != nullptr) && (queue.Last == nullptr)) {
        Node *Element = new Node;
        Element->Data = node.Data;
        Element->next = nullptr;
        queue.First->next = Element;
        queue.Last = Element;
    } else {
        Node *Element = new Node;
        Element->Data = node.Data;
        queue.Last->next = Element;
        Element->next = nullptr;
        queue.Last = Element;
    }

}

Node pop(Stack &stack) {
    Node Out;
    Out.Data = stack.Last->Data;
    Out.next = stack.Last->next;
    Node *NextElement = stack.Last->next;
    delete stack.Last;
    stack.Last = NextElement;
    return Out;
}

Node pop(Queue &queue) {
    Node Out;
    Out.Data = queue.First->Data;
    Out.next = queue.First->next;
    Node *NextElement = queue.First->next;
    delete queue.First;
    queue.First = NextElement;
    return Out;
}

void print(const Stack &stack) {
    if (stack.Last != nullptr) {
        Node *Element = stack.Last;
        while (Element != nullptr) {
            std::cout << Element->Data << ' ';
            Element = Element->next;
        }
        std::cout << std::endl;
    } else std::cout << "Stack is empty" << std::endl;
}
void print(const Queue& queue){
    if (queue.First != nullptr) {
        Node *Element = queue.First;
        while (Element != nullptr) {
            std::cout << Element->Data << ' ';
            Element = Element->next;
        }
        std::cout << std::endl;
    } else std::cout << "Stack is empty" << std::endl;
}


int main() {
    Stack Test;
    constructor(Test);
    Node FirstData, SecondData, ThirdData, FourthData;
    FirstData.Data = 14;
    SecondData.Data = 16;
    ThirdData.Data = 18;
    push(Test, FirstData);
    push(Test, SecondData);
    push(Test, ThirdData);

    std::cout << "Size of the stack after pushing = " << size(Test) << std::endl;
    std::cout << "Printing the list of elements after pushing:" << std::endl;
    print(Test);

    FourthData = pop(Test);
    ThirdData = pop(Test);
    std::cout << "Printing variables recieved by popping:" << std::endl;
    std::cout << FourthData.Data << ' ' << ThirdData.Data << std::endl;

    destructor(Test);
    std::cout << "Printing the list of elements after destruction:" << std::endl;
    print(Test);

    Queue Test1;
    constructor(Test1);
    push(Test1, FirstData);
    push(Test1, SecondData);
    push(Test1,ThirdData);
    std::cout<<size(Test1)<<std::endl;
    print(Test1);
    ThirdData=pop(Test1);
    std::cout<<ThirdData.Data<<std::endl;
    std::cout<<size(Test1)<<std::endl;
    print(Test1);
    destructor(Test1);
    print(Test1);
    return 0;
}
