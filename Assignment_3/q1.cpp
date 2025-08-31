# Stack implementation using array (list in Python)

class Stack:
    def __init__(self, size):
        self.size = size
        self.stack = []
    
    def isEmpty(self):
        return len(self.stack) == 0
    
    def isFull(self):
        return len(self.stack) == self.size
    
    def push(self, item):
        if self.isFull():
            print("Stack Overflow! Cannot push", item)
        else:
            self.stack.append(item)
            print(item, "pushed into the stack.")
    
    def pop(self):
        if self.isEmpty():
            print("Stack Underflow! Cannot pop")
        else:
            popped_item = self.stack.pop()
            print("Popped item:", popped_item)
    
    def peek(self):
        if self.isEmpty():
            print("Stack is empty. No top element.")
        else:
            print("Top element:", self.stack[-1])
    
    def display(self):
        if self.isEmpty():
            print("Stack is empty.")
        else:
            print("Stack elements:", self.stack)

# Menu-driven program
def menu():
    size = int(input("Enter the size of the stack: "))
    s = Stack(size)
    
    while True:
        print("\n--- Stack Operations Menu ---")
        print("1. Push")
        print("2. Pop")
        print("3. Peek (Top Element)")
        print("4. Check if Empty")
        print("5. Check if Full")
        print("6. Display Stack")
        print("7. Exit")
        
        choice = int(input("Enter your choice: "))
        
        if choice == 1:
            item = int(input("Enter item to push: "))
            s.push(item)
        elif choice == 2:
            s.pop()
        elif choice == 3:
            s.peek()
        elif choice == 4:
            print("Stack is empty:", s.isEmpty())
        elif choice == 5:
            print("Stack is full:", s.isFull())
        elif choice == 6:
            s.display()
        elif choice == 7:
            print("Exiting program...")
            break
        else:
            print("Invalid choice! Please try again.")

# Run the menu
menu()
