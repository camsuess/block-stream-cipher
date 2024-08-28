SRC = cipher.cpp be.cpp bd.cpp
TARGET = cipher
CXX = g++
CXXFLAGS = -Wall -g

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)


be1: $(TARGET)
	./$(TARGET) B /s/chopin/g/under/camsuess/Desktop/dev/cs356/data/input1.txt output1.txt /s/chopin/g/under/camsuess/Desktop/dev/cs356/data/bk.txt E
be2: $(TARGET)
	./$(TARGET) B /s/chopin/g/under/camsuess/Desktop/dev/cs356/data/input2.txt output1.txt /s/chopin/g/under/camsuess/Desktop/dev/cs356/data/bk.txt E
bd1: $(TARGET)
	./$(TARGET) B /s/chopin/g/under/camsuess/Desktop/dev/cs356/data/input3.txt output1.txt /s/chopin/g/under/camsuess/Desktop/dev/cs356/data/bk.txt D
se: $(TARGET)
	./$(TARGET) S input1.txt output1.txt bk.txt E
sd: $(TARGET)
	./$(TARGET) S input1.txt output1.txt bk.txt D

clean:
	rm -f $(TARGET)
