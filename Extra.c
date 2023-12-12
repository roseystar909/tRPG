#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header_\Extra.h"

// Opens a website in your main browser
int openWebsite(const char *url) {
	url = "https://github.com/roseystar909/tRPG"; 
	char command[1000];

	// Checks your OS
	#ifdef _WIN32
		snprintf(command, sizeof(command), "start %s", url);
	#elif __APPLE__
		snprintf(command, sizeof(command), "open %s", url);
	#else
		snprintf(command, sizeof(command), "xdg-open %s", url);
	#endif

	int result = system(command);

	// In case SOMETHING TERRIBLE happens
	if (result == -1) {
		perror("Error executing command");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

// Delays the code
void delay(int t) {
	long pause;
	clock_t time1, time2;

	pause = t * (CLOCKS_PER_SEC/1000);

	time2 = time1 = clock();

	while((time1-time2) < pause) {
		time1 = clock();
	}
}