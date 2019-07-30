.PHONY: all clean

CXX = g++
CXXFLAGS = -std=c++11

BUILD_DIR=build
SOURCE_DIR=src
EXEC=encrypt

SOURCE_FILES=$(wildcard $(SOURCE_DIR)/*.cpp)
OBJECT_FILES = $(patsubst $(SOURCE_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCE_FILES))

all: dir $(BUILD_DIR)/$(EXEC)

dir:
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(EXEC): $(OBJECT_FILES)
	$(CXX) $^ -o $@

$(OBJECT_FILES): $(BUILD_DIR)/%.o : $(SOURCE_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/$(EXEC) $(BUILD_DIR)