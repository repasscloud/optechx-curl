#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(int argc, char *argv[])
{
    if (argc != 4) {
        // Display help message if incorrect number of arguments
        printf("Usage: optxcurl <URL> <output_file_name> <output_path>\n");
        return 0;
    }

    // Get URL, output file name, and output path from arguments
    char *url = argv[1];
    char *output_file_name = argv[2];
    char *output_path = argv[3];

    // TODO: Add code to download file from URL and save it to the specified output path with the specified output file name

    return 0;
}