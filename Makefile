hellomake: src/optxcurl.c
	apt -y install libcurl-devel
	mkdir out
	gcc -fdiagnostics-color=always -g src/optxcurl.c -o out/optxcurl -I.