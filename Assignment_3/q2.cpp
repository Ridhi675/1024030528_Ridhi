def reverse_using_stack(s):
    stack = []
    
    # Push all characters of the string into the stack
    for char in s:
        stack.append(char)
    
    reversed_str = ""
    
    # Pop all characters from the stack and add to reversed_str
    while stack:
        reversed_str += stack.pop()
    
    return reversed_str

# Example usage:
string = "DataStructure"
print("Original String:", string)
print("Reversed Str
