# Compiler et options
CXX = clang++
CXXFLAGS = -std=c++17 -g -Wall -Werror -Iinclude
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system

# Répertoires
SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin

# Fichiers source et en-tête
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
HEADERS = $(wildcard $(INCLUDE_DIR)/*.h)

# Nom de l'exécutable
TARGET = $(BIN_DIR)/main

# Règles
all: $(TARGET)

# Création de l'exécutable
$(TARGET): $(SRCS) $(HEADERS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

# Version de debug
debug: CXXFLAGS += -DDEBUG -O0
debug: all

# Nettoyage
clean:
	rm -rf $(BIN_DIR)
