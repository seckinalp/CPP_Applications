OUTPUT := hw4

output: main.o HashTable.o KmerNode.o
	g++ main.o HashTable.o KmerNode.o -o $(OUTPUT)

main.o: main.cpp
	g++ -c main.cpp

HashTable.o: HashTable.cpp HashTable.h
	g++ -c HashTable.cpp

KmerNode.o: KmerNode.cpp KmerNode.h
	g++ -c KmerNode.cpp

run: output
	./$(OUTPUT)

clean:
	rm -f *.o $(OUTPUT)