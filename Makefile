# javers
CC = g++
CC_FLAGS = -g -Wall

SRC_DIR = src
BIN_DIR = bin
BUILD_DIR = build
INSTALL_DIR = /usr/bin

SRCS = $(wildcard $(SRC_DIR)/*.cc)
OBJS = $(patsubst %.cc,$(BUILD_DIR)/%.o,$(notdir $(SRCS)))
TARGET = $(BIN_DIR)/javers

all: $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(BUILD_DIR)
	$(CC) -c $< -o $@ $(CC_FLAGS) $(LD_FLAGS)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $^ -o $@ $(CC_FLAGS) $(LD_FLAGS)

install:
	cp $(TARGET) $(INSTALL_DIR)

uninstall:
	rm $(INSTALL_DIR)/$(TARGET)

clean:
	rm -rf $(BIN_DIR) $(BUILD_DIR)

.PHONY: install uninstall clean
