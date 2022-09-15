make:
	g++ -c -o frac.o libfrac.cpp -O2 -fPIC
#	g++ hash.cpp -O2
	gcc -shared -o libfrac.so frac.o
	rm frac.o
