def input_data() -> tuple[int, list[tuple[int, int]]]:
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    classes = []
    index = 1
    for _ in range(N):
        a = int(data[index])
        b = int(data[index + 1])
        classes.append((a, b))
        index += 2
    
    return N, classes

def solve(N: int, classes: list[tuple[int, int]]) -> int:
    # Sort classes based on end time, and start time for tie-breaking
    classes.sort(key=lambda x: (x[1], x[0]))
    
    room = 1  # Start with one room
    size = len(classes)
    
    ind = -1
    prev_finish = -1
    cnt = 0  # Number of classes accommodated in rooms

    # Dictionary to keep track of visited classes
    visited = set()
    
    while cnt < size:
        ind += 1
        
        # If we have iterated through all classes, reset and add a new room
        if ind >= size:
            ind = 0
            room += 1
            prev_finish = -1
            visited.clear()  # Clear visited classes for the new room
        
        current_class = classes[ind]
        
        # Skip visited classes
        if current_class in visited:
            continue
        
        # Check if we can accommodate the class in the current room
        if current_class[0] >= prev_finish:
            prev_finish = current_class[1]  # Update prevFinish
            cnt += 1  # Increase count of accommodated classes
            visited.add(current_class)  # Mark this class as visited
    
    return room

def main():
    import sys
    input = sys.stdin.read
    N, classes = input_data()
    print(solve(N, classes))

if __name__ == "__main__":
    main()
