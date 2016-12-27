principal:
	g++ src/principal.cpp -o bin/principal -g -O1 -Wall -Iinclude -std=c++11
	@	 echo ">> Compilación terminada."

clean: 
	rm bin/principal
	@	echo ">> Datos de compilación borrados."	
