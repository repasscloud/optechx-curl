optxcurl: src/optxcurl.c
	mkdir out
	gcc -fdiagnostics-color=always -g src/optxcurl.c -o out/optxcurl -I. -lcurl

optxget: src/optxget.cpp
	g++ -o out/optxget src/optxget.cpp -lcurl
	./out/optxget https://speed.hetzner.de/100MB.bin fish.bin