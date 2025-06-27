# Data Structures and Algorithms in C

A comprehensive study repository for learning Data Structures and Algorithms using the C programming language. This repository provides complete implementations, detailed explanations, and practical examples for fundamental data structures.

## 🎯 Overview

This repository is designed as a complete learning resource for computer science students and developers who want to master data structures and algorithms using C. Each implementation includes:

- **Complete source code** with detailed comments
- **Theoretical lessons** explaining concepts and applications
- **Practical demonstrations** showing real-world usage
- **Complexity analysis** for all operations
- **Memory management** best practices

## 📚 Table of Contents

- [Features](#features)
- [Repository Structure](#repository-structure)
- [Getting Started](#getting-started)
- [Data Structures Implemented](#data-structures-implemented)
- [Building and Running](#building-and-running)
- [Study Guide](#study-guide)
- [Contributing](#contributing)
- [License](#license)

## ✨ Features

- **🔧 Complete Implementations**: All data structures implemented from scratch
- **📖 Educational Content**: Detailed lessons for each topic (~90 minutes each)
- **🧪 Practical Examples**: Working demonstrations with real data
- **⚡ Performance Analysis**: Big O complexity analysis for all operations
- **🛡️ Memory Safe**: Proper memory management and error handling
- **🔨 Build System**: Professional Makefile with multiple targets
- **📊 Testing**: Automated tests and memory leak detection
- **📝 Documentation**: Comprehensive documentation and comments

## 📁 Repository Structure

```
estruturas_dados_algoritmos_c/
├── include/                    # Header files
│   ├── common.h               # Common definitions and utilities
│   ├── stack.h                # Stack data structure
│   ├── queue.h                # Queue and Deque data structures
│   ├── list.h                 # Linear lists (array and linked)
│   ├── priority_queue.h       # Priority queue with heap
│   ├── tree.h                 # Binary search trees
│   └── graph.h                # Graph representations
├── lib/                       # Implementation files
│   ├── common.c               # Utility functions
│   ├── stack.c                # Stack implementations
│   ├── queue.c                # Queue implementations
│   ├── list.c                 # List implementations
│   ├── priority_queue.c       # Priority queue implementation
│   ├── tree.c                 # Tree implementations
│   └── graph.c                # Graph implementations
├── code_examples/             # Demonstration programs
│   ├── aula1_pilhas/          # Lesson 1: Stacks
│   ├── aula2_filas_deques/    # Lesson 2: Queues and Deques
│   ├── aula3_listas_prioridade/ # Lesson 3: Lists and Priority Queues
│   └── aula4_arvores/         # Lesson 4: Trees
├── lessons/                   # Theoretical content
│   ├── aula1_pilhas.md        # Stack theory and applications
│   ├── aula2_filas_deques.md  # Queue theory and applications
│   └── ...                    # Additional lessons
├── docs/                      # Additional documentation
├── tests/                     # Test files
├── Makefile                   # Build system
└── README.md                  # This file
```

## 🚀 Getting Started

### Prerequisites

- **GCC Compiler**: Version 4.9 or higher
- **Make**: For building the project
- **Git**: For cloning the repository

Optional tools for enhanced development:
- **Valgrind**: For memory leak detection
- **Clang-format**: For code formatting
- **Doxygen**: For documentation generation

### Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/estruturas_dados_algoritmos_c.git
   cd estruturas_dados_algoritmos_c
   ```

2. **Build all programs**:
   ```bash
   make all
   ```

3. **Run a demonstration**:
   ```bash
   make run-stack
   ```

4. **Run all tests**:
   ```bash
   make test
   ```

## 🏗️ Data Structures Implemented

### 1. **Stacks (Pilhas)**
- **Array-based implementation**: Fixed-size stack with O(1) operations
- **Linked-list implementation**: Dynamic stack with unlimited size
- **Applications**: Expression evaluation, function calls, undo operations

### 2. **Queues and Deques (Filas)**
- **Circular array queue**: Efficient space utilization
- **Linked-list queue**: Dynamic size management
- **Double-ended queue (Deque)**: Insertion/removal at both ends
- **Applications**: Process scheduling, BFS algorithms, sliding window

### 3. **Linear Lists (Listas Lineares)**
- **Sequential list (Array)**: Direct access by index
- **Singly linked list**: Dynamic insertion/removal
- **Doubly linked list**: Bidirectional navigation
- **Circular list**: Cyclic structure
- **Applications**: Database records, music playlists, browser history

### 4. **Priority Queues (Filas de Prioridade)**
- **Binary heap implementation**: Efficient priority-based operations
- **Max-heap property**: Highest priority element at root
- **Applications**: Dijkstra's algorithm, task scheduling, event simulation

### 5. **Binary Search Trees (Árvores Binárias de Busca)**
- **BST property**: Left < Root < Right
- **Recursive operations**: Insert, delete, search
- **Tree traversals**: In-order, pre-order, post-order, level-order
- **Applications**: Database indexing, expression trees, file systems

### 6. **Graphs (Grafos)** *(Coming Soon)*
- **Adjacency matrix**: Dense graph representation
- **Adjacency list**: Sparse graph representation
- **Graph algorithms**: BFS, DFS, shortest path
- **Applications**: Social networks, routing, dependency resolution

## 🔨 Building and Running

### Basic Commands

```bash
# Build all programs
make all

# Build specific program
make stack_demo
make queue_demo
make list_priority_demo
make tree_demo

# Run demonstrations
make run-stack          # Run stack demo
make run-queue          # Run queue demo
make run-list           # Run list demo
make run-tree           # Run tree demo
make run-all            # Run all demos

# Testing and validation
make test               # Run basic tests
make memcheck           # Check for memory leaks (requires valgrind)

# Cleanup
make clean              # Remove all build files
make clean-obj          # Remove only object files
```

### Advanced Commands

```bash
# Development tools
make debug              # Build with debug symbols
make release            # Build optimized version
make analyze            # Run static analysis (requires cppcheck)
make format             # Format code (requires clang-format)

# Documentation
make docs               # Generate documentation (requires doxygen)
make help               # Show all available commands
make stats              # Show project statistics

# System installation
sudo make install       # Install to /usr/local/bin
sudo make uninstall     # Remove from system
```

## 📖 Study Guide

This repository is organized as a progressive learning path:

### **Lesson 1: Stacks (90 minutes)**
- **Theory**: LIFO principle, applications, complexity analysis
- **Practice**: Implement and test both array and linked-list versions
- **Exercises**: Balanced parentheses, expression evaluation
- **File**: `lessons/aula1_pilhas.md`

### **Lesson 2: Queues and Deques (90 minutes)**
- **Theory**: FIFO principle, circular arrays, double-ended queues
- **Practice**: Multiple implementations and comparisons
- **Exercises**: Process simulation, sliding window problems
- **File**: `lessons/aula2_filas_deques.md`

### **Lesson 3: Lists and Priority Queues (90 minutes)**
- **Theory**: Linear data structures, heap properties
- **Practice**: Array vs linked implementations
- **Exercises**: Priority-based scheduling, heap operations
- **File**: `lessons/aula3_listas_prioridade.md`

### **Lesson 4: Binary Search Trees (90 minutes)**
- **Theory**: BST property, tree traversals, balancing
- **Practice**: Recursive algorithms, tree operations
- **Exercises**: Dictionary implementation, expression trees
- **File**: `lessons/aula4_arvores.md`

### Recommended Study Schedule

1. **Week 1**: Stacks and Queues (Lessons 1-2)
2. **Week 2**: Lists and Priority Queues (Lesson 3)
3. **Week 3**: Trees and Advanced Structures (Lesson 4+)
4. **Week 4**: Graphs and Algorithms (Coming Soon)

## 🧪 Testing and Validation

### Automated Testing

```bash
# Run all tests
make test

# Expected output:
# Running basic tests...
# ✓ Stack demo passed
# ✓ Queue demo passed
# ✓ List demo passed
# ✓ Tree demo passed
# All tests passed!
```

### Memory Leak Detection

```bash
# Check for memory leaks (requires valgrind)
make memcheck

# Expected output:
# Running memory checks...
# ✓ Stack demo - no memory leaks
# ✓ Queue demo - no memory leaks
# ✓ List demo - no memory leaks
# ✓ Tree demo - no memory leaks
# All memory checks passed!
```

### Manual Testing

Each demonstration program can be run individually:

```bash
# Interactive demonstrations
./bin/stack_demo
./bin/queue_demo
./bin/list_priority_demo
./bin/tree_demo
```

## 📊 Performance Characteristics

| Data Structure | Access | Search | Insertion | Deletion | Space |
|----------------|--------|--------|-----------|----------|-------|
| **Array Stack** | O(1) | O(n) | O(1) | O(1) | O(n) |
| **Linked Stack** | O(1) | O(n) | O(1) | O(1) | O(n) |
| **Array Queue** | O(1) | O(n) | O(1) | O(1) | O(n) |
| **Linked Queue** | O(1) | O(n) | O(1) | O(1) | O(n) |
| **Array List** | O(1) | O(n) | O(n) | O(n) | O(n) |
| **Linked List** | O(n) | O(n) | O(1)* | O(1)* | O(n) |
| **Priority Queue** | O(1)** | O(n) | O(log n) | O(log n) | O(n) |
| **Binary Search Tree*** | O(log n) | O(log n) | O(log n) | O(log n) | O(n) |

*\* With reference to the node*  
*\*\* Only for highest priority element*  
*\*\*\* Average case for balanced tree*

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

### Types of Contributions

1. **Bug fixes**: Report and fix issues
2. **New implementations**: Add new data structures
3. **Documentation**: Improve explanations and examples
4. **Tests**: Add more comprehensive testing
5. **Optimizations**: Improve performance or memory usage

### Contribution Guidelines

1. **Fork the repository**
2. **Create a feature branch**: `git checkout -b feature/new-structure`
3. **Follow coding standards**: Use the existing style
4. **Add tests**: Ensure your code is tested
5. **Update documentation**: Include relevant documentation
6. **Submit a pull request**: Describe your changes clearly

### Coding Standards

- **Naming**: Use descriptive names for functions and variables
- **Comments**: Document complex algorithms and data structures
- **Memory**: Always free allocated memory
- **Error handling**: Check for null pointers and edge cases
- **Formatting**: Use consistent indentation and spacing

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- **Algorithms textbooks**: CLRS, Sedgewick, Weiss
- **Open source community**: For inspiration and best practices
- **Students and educators**: For feedback and suggestions

## 📞 Support

If you have questions or need help:

1. **Check the documentation**: Most questions are answered in the lessons
2. **Run the examples**: See the implementations in action
3. **Open an issue**: For bugs or feature requests
4. **Start a discussion**: For general questions about data structures

## 🔗 Related Resources

### Books
- **"Introduction to Algorithms"** by Cormen, Leiserson, Rivest, and Stein
- **"Data Structures and Algorithm Analysis in C"** by Mark Allen Weiss
- **"The C Programming Language"** by Kernighan and Ritchie

### Online Resources
- [GeeksforGeeks Data Structures](https://www.geeksforgeeks.org/data-structures/)
- [Visualgo - Algorithm Visualizations](https://visualgo.net/)
- [MIT OpenCourseWare - Introduction to Algorithms](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/)

---

**Happy Learning! 🚀**

*This repository is actively maintained and updated. Star ⭐ the repository if you find it helpful!*

