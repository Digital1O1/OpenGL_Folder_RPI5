# Compiler and linker settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = -lglfw -ldl -lGL

# Include directories
INCLUDES = -I/home/pi/OpenGL_Folder/includes

# Source files
SRCS = hello_triangle.cpp /home/pi/OpenGL_Folder/src/glad.c

# Object files
OBJS = $(SRCS:.cpp=.o)

# Output executable
TARGET = triangleExample

# Build the program
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS) $(INCLUDES)

# Compile source files into object files
.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean up build files
clean:
	rm -f hello_triangle.o $(TARGET)
# rm -f $(OBJS) $(TARGET)

# # Run the program
# run: $(TARGET)
# 	./$(TARGET)
