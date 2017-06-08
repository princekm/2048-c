CPP=g++
EXE=2048
SRC=main.cpp 2048.cpp
all:
	$(CPP) $(SRC) -o $(EXE) 
clean:
	rm -rf $(EXE)
