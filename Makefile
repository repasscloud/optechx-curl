optxcurl: src/optxcurl.c
	mkdir out
	gcc -fdiagnostics-color=always -g src/optxcurl.c -o out/optxcurl -I. -lcurl

optxget: src/optxget.cpp
	g++ -o optxget src/optxget.cpp -lcurl