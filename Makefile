followrel: src/followrel.c
	mkdir out
	gcc -fdiagnostics-color=always -g src/followrel.c -o out/followrel -I.

optxcurl: src/optxcurl.c
	mkdir out
	gcc -fdiagnostics-color=always -g src/optxcurl.c -o out/optxcurl -I.