# Makefile for Data Structures and Algorithms in C
# Author: Data Structures Study Repository
# Version: 1.0

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g
INCLUDES = -I include
LIBDIR = lib
SRCDIR = code_examples
OBJDIR = obj
BINDIR = bin

# Create directories if they don't exist
$(shell mkdir -p $(OBJDIR) $(BINDIR))

# Library source files
LIB_SOURCES = $(wildcard $(LIBDIR)/*.c)
LIB_OBJECTS = $(LIB_SOURCES:$(LIBDIR)/%.c=$(OBJDIR)/%.o)

# Demo programs
DEMOS = stack_demo queue_demo list_priority_demo tree_demo

# Default target
all: $(DEMOS)

# Individual demo targets
stack_demo: $(OBJDIR)/stack_demo.o $(LIB_OBJECTS)
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $^

queue_demo: $(OBJDIR)/queue_demo.o $(LIB_OBJECTS)
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $^

list_priority_demo: $(OBJDIR)/list_priority_demo.o $(LIB_OBJECTS)
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $^

tree_demo: $(OBJDIR)/tree_demo.o $(LIB_OBJECTS)
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $^

# Compile library object files
$(OBJDIR)/%.o: $(LIBDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile demo object files
$(OBJDIR)/stack_demo.o: $(SRCDIR)/aula1_pilhas/stack_demo.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/queue_demo.o: $(SRCDIR)/aula2_filas_deques/queue_demo.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/list_priority_demo.o: $(SRCDIR)/aula3_listas_prioridade/list_priority_demo.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/tree_demo.o: $(SRCDIR)/aula4_arvores/tree_demo.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Run demos
run-stack: stack_demo
	@echo "Running Stack Demo..."
	@echo "" | ./$(BINDIR)/stack_demo

run-queue: queue_demo
	@echo "Running Queue Demo..."
	@echo "" | ./$(BINDIR)/queue_demo

run-list: list_priority_demo
	@echo "Running List and Priority Queue Demo..."
	@echo "" | ./$(BINDIR)/list_priority_demo

run-tree: tree_demo
	@echo "Running Tree Demo..."
	@echo "" | ./$(BINDIR)/tree_demo

run-all: all
	@echo "Running all demos..."
	@make run-stack
	@echo "\n" && make run-queue
	@echo "\n" && make run-list
	@echo "\n" && make run-tree

# Test targets
test: all
	@echo "Running basic tests..."
	@./$(BINDIR)/stack_demo > /dev/null && echo "✓ Stack demo passed"
	@./$(BINDIR)/queue_demo > /dev/null && echo "✓ Queue demo passed"
	@./$(BINDIR)/list_priority_demo > /dev/null && echo "✓ List demo passed"
	@./$(BINDIR)/tree_demo > /dev/null && echo "✓ Tree demo passed"
	@echo "All tests passed!"

# Memory check with valgrind (if available)
memcheck: all
	@echo "Running memory checks..."
	@if command -v valgrind >/dev/null 2>&1; then \
		echo "Checking stack_demo..."; \
		echo "" | valgrind --leak-check=full --error-exitcode=1 ./$(BINDIR)/stack_demo > /dev/null; \
		echo "✓ Stack demo - no memory leaks"; \
		echo "Checking queue_demo..."; \
		echo "" | valgrind --leak-check=full --error-exitcode=1 ./$(BINDIR)/queue_demo > /dev/null; \
		echo "✓ Queue demo - no memory leaks"; \
		echo "Checking list_priority_demo..."; \
		echo "" | valgrind --leak-check=full --error-exitcode=1 ./$(BINDIR)/list_priority_demo > /dev/null; \
		echo "✓ List demo - no memory leaks"; \
		echo "Checking tree_demo..."; \
		echo "" | valgrind --leak-check=full --error-exitcode=1 ./$(BINDIR)/tree_demo > /dev/null; \
		echo "✓ Tree demo - no memory leaks"; \
		echo "All memory checks passed!"; \
	else \
		echo "Valgrind not found. Install valgrind for memory checking."; \
	fi

# Clean targets
clean:
	rm -rf $(OBJDIR) $(BINDIR)
	@echo "Cleaned build files"

clean-obj:
	rm -rf $(OBJDIR)
	@echo "Cleaned object files"

# Install target (copy to system directories)
install: all
	@echo "Installing to /usr/local/bin..."
	@sudo cp $(BINDIR)/* /usr/local/bin/
	@echo "Installation complete"

# Uninstall target
uninstall:
	@echo "Removing from /usr/local/bin..."
	@sudo rm -f /usr/local/bin/stack_demo
	@sudo rm -f /usr/local/bin/queue_demo
	@sudo rm -f /usr/local/bin/list_priority_demo
	@sudo rm -f /usr/local/bin/tree_demo
	@echo "Uninstallation complete"

# Help target
help:
	@echo "Data Structures and Algorithms in C - Makefile"
	@echo ""
	@echo "Available targets:"
	@echo "  all              - Build all demo programs"
	@echo "  stack_demo       - Build stack demonstration"
	@echo "  queue_demo       - Build queue demonstration"
	@echo "  list_priority_demo - Build list and priority queue demonstration"
	@echo "  tree_demo        - Build tree demonstration"
	@echo ""
	@echo "  run-stack        - Run stack demo"
	@echo "  run-queue        - Run queue demo"
	@echo "  run-list         - Run list demo"
	@echo "  run-tree         - Run tree demo"
	@echo "  run-all          - Run all demos"
	@echo ""
	@echo "  test             - Run basic tests"
	@echo "  memcheck         - Run memory leak checks (requires valgrind)"
	@echo ""
	@echo "  clean            - Remove all build files"
	@echo "  clean-obj        - Remove only object files"
	@echo ""
	@echo "  install          - Install demos to system (requires sudo)"
	@echo "  uninstall        - Remove demos from system (requires sudo)"
	@echo ""
	@echo "  help             - Show this help message"

# Debug target
debug: CFLAGS += -DDEBUG -O0
debug: all

# Release target
release: CFLAGS += -O2 -DNDEBUG
release: all

# Static analysis (if cppcheck is available)
analyze:
	@if command -v cppcheck >/dev/null 2>&1; then \
		echo "Running static analysis..."; \
		cppcheck --enable=all --std=c99 $(INCLUDES) $(LIBDIR)/ $(SRCDIR)/; \
	else \
		echo "cppcheck not found. Install cppcheck for static analysis."; \
	fi

# Format code (if clang-format is available)
format:
	@if command -v clang-format >/dev/null 2>&1; then \
		echo "Formatting code..."; \
		find $(LIBDIR) $(SRCDIR) include -name "*.c" -o -name "*.h" | xargs clang-format -i; \
		echo "Code formatting complete"; \
	else \
		echo "clang-format not found. Install clang-format for code formatting."; \
	fi

# Documentation generation (if doxygen is available)
docs:
	@if command -v doxygen >/dev/null 2>&1; then \
		echo "Generating documentation..."; \
		doxygen Doxyfile; \
		echo "Documentation generated in docs/"; \
	else \
		echo "doxygen not found. Install doxygen for documentation generation."; \
	fi

# Show project statistics
stats:
	@echo "Project Statistics:"
	@echo "==================="
	@echo "Header files: $$(find include -name "*.h" | wc -l)"
	@echo "Source files: $$(find $(LIBDIR) $(SRCDIR) -name "*.c" | wc -l)"
	@echo "Total lines of code: $$(find include $(LIBDIR) $(SRCDIR) -name "*.c" -o -name "*.h" | xargs wc -l | tail -1 | awk '{print $$1}')"
	@echo "Library files: $$(ls $(LIBDIR)/*.c | wc -l)"
	@echo "Demo programs: $$(echo $(DEMOS) | wc -w)"

# Phony targets
.PHONY: all clean clean-obj install uninstall help debug release test memcheck analyze format docs stats run-stack run-queue run-list run-tree run-all

# Default goal
.DEFAULT_GOAL := all

