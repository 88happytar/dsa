    #include <iostream>
    using namespace std;

    class Stack{
    private:
        int size;
        int top;
        int* aStack;
    public:
        Stack(int size);
        ~Stack();
        void push(int x);
        int pop();
        int peek(int index);
        int isFull();
        int isEmpty();
        void display();
        int stackTop();
    };

    Stack::Stack(int size) {
        this->size = size;
        top = -1;
        aStack = new int[size];
    }

    Stack::~Stack() {
        delete[] aStack;
    }

    void Stack::push(int x) {
        if (isFull()){
            cout << "Stack Overflow - it's full cannot push more!" << endl;
        } else {
            top++;
            aStack[top] = x;
        }
    }

    int Stack::pop() {
        int x = 1;
        if (isEmpty()){
            cout << "Stack Underflow - it's empty now!" << endl;
        } else {
            x = aStack[top];
            top--;
        }
        return x;
    }

    int Stack::peek(int index) {
        int x = -1;
        if (top-index+1 < 0 || top-index+1 == size){
            cout << "Invalid position! " ;
        } else {
            x = aStack[top-index+1];
        }
        return x;
    }

    int Stack::isFull() {
        if (top == size-1){
            return 1;
        }
        return 0;
    }

    int Stack::isEmpty() {
        if (top == -1){
            return 1;
        }
        return 0;
    }

    void Stack::display() {
        for (int i=top; i>=0; i--){
            cout << aStack[i] << " | " << flush;
        }
        cout << endl;
    }

    int Stack::stackTop() {
        if (isEmpty()){
            return -1;
        }
        return aStack[top];
    }

    int main() {

        int A[] = {1, 3, 5, 7, 9};
        int arraySize = sizeof(A)/sizeof(A[0]);
        cout << "arraySize=" << arraySize << endl;

        Stack stk(arraySize);

        // Populate stack with array elements
        cout << "++++++++++++++ push ++++++++++++++" << endl;
        for (int i=0; i<arraySize; i++){
            stk.push(A[i]);
        }
        stk.push(11);

        cout << "Stack full: " << stk.isFull() << endl;

        // Display stack
        cout << "++++++++++++++ Display ++++++++++++++" << endl;
        cout << "Stack: " << flush;
        stk.display();

        // Peek
        cout << "++++++++++++++ peek ++++++++++++++" << endl;
        cout << "Peek at 0th: " << stk.peek(0) << endl;
        cout << "Peek at 3rd: " << stk.peek(3) << endl;
        cout << "Peek at 10th: " << stk.peek(10) << endl;

        // Top element
        cout << "++++++++++++++ stackTop ++++++++++++++" << endl;
        cout << "Top element: " << stk.stackTop() << endl;

        // Pop out elements from stack
        cout << "++++++++++++++ pop ++++++++++++++" << endl;
        cout << "Popped out elements: " << flush;
        for (int i=0; i<arraySize; i++){
            cout << stk.pop() << ", " << flush;
        }
        cout << endl;
        stk.pop();

        cout << "++++++++++++++ isEmpty ++++++++++++++" << endl;
        cout << "Stack empty: " << stk.isEmpty() << endl;

        return 0;
    }
