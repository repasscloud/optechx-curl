optxcurl: src/optxcurl.c
	mkdir out
	gcc -fdiagnostics-color=always -g src/optxcurl.c -o out/optxcurl -I. -lcurl

optxget: src/optxget.cpp
	g++ -o optxget src/optxget.cpp -lcurl

optxg2: app/indicators.hpp app/curl_download.cpp
	g++ app/curl_download.cpp app/indicators.hpp -o curl_download -lcurl