csr: main.o CSR_Cipher.o
	g++ -Wall -std=c++11 -m64 -o csr main.o CSR_Cipher.o

main.o: main.cpp
	g++ -Wall -std=c++11 -m64 -c main.cpp -o main.o

CSR_Cipher.o: CSR_Cipher.cpp
	g++ -Wall -std=c++11 -m64 -c CSR_Cipher.cpp -o CSR_Cipher.o

clean:
	rm -f main.o CSR_Cipher.o csr

.PHONY: clean