cpp_curl: src/cpp_curl/curl_download.cpp src/cpp_curl/indicators.hpp
	g++ src/cpp_curl/curl_download.cpp src/cpp_curl/indicators.hpp -o cpp_curl -lcurl

followrel: src/followrel/followrel.c
	gcc -fdiagnostics-color=always -g src/followrel/rollowrel.c -o out/followrel -I.

optxcurl: src/optxcurl/optxcurl.c
	gcc -fdiagnostics-color=always -g src/optxcurl/optxcurl.c -o out/optxcurl -I. -lcurl

optxget: src/optxget/optxget.cpp
	g++ -o optxget src/optxget/optxget.cpp -lcurl
