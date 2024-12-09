# Compiler et options
CXX = clang++
CXXFLAGS = -std=c++17 -g -Wall -Werror -Iinclude
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system

# Répertoires
SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin
OBJ_DIR = obj

# Fichiers source et objets
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Nom de l'exécutable
TARGET = $(BIN_DIR)/main

# Règles
all: $(TARGET)

# Création de l'exécutable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)

# Affichage des fichiers utilisés
print:
	@echo "Sources: $(SRCS)"
	@echo "Objects: $(OBJS)"
	@echo "Headers: $(wildcard $(INCLUDE_DIR)/*.h)"
