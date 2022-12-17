hellomake: src/optxcurl.c
	sudo apt -y install libcurl14-openssl-dev
	mkdir out
	gcc -fdiagnostics-color=always -g src/optxcurl.c -o out/optxcurl -I.