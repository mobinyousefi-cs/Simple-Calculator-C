# Makefile for Simple Calculator in C

CC      := gcc
CFLAGS  := -std=c11 -Wall -Wextra -Wpedantic -Iinclude
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
TARGET := $(BIN_DIR)/simple_calculator
TEST_TARGET := $(BIN_DIR)/test_calculator

.PHONY: all clean format tests

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c include/calculator.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build tests

TEST_SRCS := tests/test_calculator.c
TEST_OBJS := $(patsubst tests/%.c,$(BUILD_DIR)/%.test.o,$(TEST_SRCS))

$(TEST_TARGET): $(OBJS) $(TEST_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.test.o: tests/%.c include/calculator.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Run tests target (build only; running is manual)

tests: $(TEST_TARGET)
	@echo "Test binary built at $(TEST_TARGET). Run it manually to execute tests."

# Formatting helper (optional; requires clang-format installed)

format:
	clang-format -i $(SRC_DIR)/*.c include/*.h tests/*.c || echo "clang-format not found; skipping format."

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
