OUTPUT := hw2

output: main.o KmerTree.o BST.o BSTNode.o
	g++ main.o KmerTree.o BST.o BSTNode.o -o $(OUTPUT)

main.o: main.cpp
	g++ -c main.cpp

KmerTree.o: KmerTree.cpp KmerTree.h
	g++ -c KmerTree.cpp

BST.o: BST.cpp BST.h
	g++ -c BST.cpp

BSTNode.o: BSTNode.cpp BSTNode.h
	g++ -c BSTNode.cpp

run: output
	./$(OUTPUT)

clean:
	rm -f *.o $(OUTPUT)