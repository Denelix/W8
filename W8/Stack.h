#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <class T>
class stackType
{
    public:
        stackType(int size = 100);
        void initializeStack();
        bool isEmptyStack() const;
        bool isFullStack() const;
        void push(const T& item);
        void push(const vector<T>& items);
        void pop();
        T top() const;
        bool operator==(const stackType<T>& stack2) const;

    private:
        vector<T> list;
        int maxStackSize;
};

template <class T>
stackType<T>::stackType(int size) //sets the max size and makes suyre it's empty using intializestack
{ 
    try
    {
        if (size <= 0) 
        {
            maxStackSize = 100;
            throw "Stack size must be positive size set to 100, ";
        }
        else 
        {
            maxStackSize = size;
        }
        initializeStack();
    }
    catch (const char* msg) 
    {
        cout << msg << endl;
    }
}

template <class T>
void stackType<T>::initializeStack()
{
    list.clear();
}

template <class T>
bool stackType<T>::isEmptyStack() const 
{
    return list.empty();
}

template <class T>
bool stackType<T>::isFullStack() const
{
    return list.size() == maxStackSize;
}

template <class T>
bool stackType<T>::operator==(const stackType<T>& stack2) const
{
    return list == stack2.list;
}

template <class T>
void stackType<T>::push(const T& item)
{
    try 
    {
        if (isFullStack())
        {
            throw "Error: Stack is full.";
        }
        else 
        {
            list.push_back(item);
        }
    }
    catch (const char* msg) 
    {
        cout << msg << endl;
    }
}

template <class T>
void stackType<T>::push(const vector<T>& items) 
{
    try 
    {
        if (list.size() + items.size() > maxStackSize) //If items are more than max size.
        {
            throw "Error: Stack will overflow.";
        }
        else 
        {
            for (const auto& item : items) 
            {
                list.push_back(item);
            }
        }
    }
    catch (const char* msg) 
    {
        cout << msg << endl;
    }
}

template <class T>
void stackType<T>::pop()
{
    try
    {
        if (isEmptyStack()) 
        {
            throw "Error: Stack is empty.";
        }
        else 
        {
            list.pop_back();
        }
    }
    catch (const char* msg) 
    {
        cout << msg << endl;
    }
}

template <class T>
T stackType<T>::top() const
{
    try
    {
        if (isEmptyStack()) 
        {
            throw "Error: Stack is empty.";
        }
        else 
        {
            return list.back();
        }
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }
}


int main()
{
    stackType<int> stack1(50);
    stackType<int> stack2(50);
    stack1.initializeStack();
    stack1.push(23);
    stack1.push(45);
    stack1.push(38);
    stack2 = stack1;
    //================
    if (stack1 == stack2)
        cout << "stack1 and stack2 are identical" << endl;
    else
        cout << "stack1 and stack2 are not identical" << endl;
    //================
    stack2.pop();
    stack2.push(32);
    //================
    cout << "**** After pop and push operations on stack2 ****" << endl;
    if (stack1 == stack2)
        cout << "stack1 and stack2 are identical" << endl;
    else
        cout << "stack1 and stack2 are not identical" << endl;
    //================
    stack2.push(11);
    //================
    cout << "**** After another push operation on stack2 ****" << endl;
    if (stack1 == stack2)
        cout << "stack1 and stack2 are identical" << endl;
    else
        cout << "stack1 and stack2 are not identical" << endl;
    return 0;

}
