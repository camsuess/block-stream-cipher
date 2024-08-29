SRC = cipher.cpp be.cpp bd.cpp se.cpp sd.cpp
TARGET = cipher
CXX = g++
CXXFLAGS = -Wall -g

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)


be1: $(TARGET)
	./$(TARGET) B /s/chopin/g/under/camsuess/Desktop/dev/cs356/data/input1.txt BEO.txt /s/chopin/g/under/camsuess/Desktop/dev/cs356/data/bk.txt E
be2: $(TARGET)
	./$(TARGET) B /s/chopin/g/under/camsuess/Desktop/dev/cs356/data/input2.txt BEO.txt /s/chopin/g/under/camsuess/Desktop/dev/cs356/data/bk.txt E
bd1: $(TARGET)
	./$(TARGET) B /s/chopin/g/under/camsuess/Desktop/dev/cs356/cipher/BEO.txt BDO.txt /s/chopin/g/under/camsuess/Desktop/dev/cs356/data/bk.txt D
bd2: $(TARGET)
	./$(TARGET) B /s/chopin/g/under/camsuess/Desktop/dev/cs356/cipher/BEO.txt BDO.txt /s/chopin/g/under/camsuess/Desktop/dev/cs356/data/bk.txt D
se1: $(TARGET)
	./$(TARGET) S /s/chopin/g/under/camsuess/Desktop/dev/cs356/data/input3.txt SEO.txt /s/chopin/g/under/camsuess/Desktop/dev/cs356/data/sk.txt E
sd1: $(TARGET)
	./$(TARGET) S /s/chopin/g/under/camsuess/Desktop/dev/cs356/cipher/SEO.txt SDO.txt /s/chopin/g/under/camsuess/Desktop/dev/cs356/data/sk.txt D

clean:
	rm -f $(TARGET)
clearn:
	rm -f $(TARGET)
	clear
