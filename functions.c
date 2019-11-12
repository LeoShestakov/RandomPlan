#include "functions.h"
#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int genRandom() {
	int fd = open("/dev/random", O_RDONLY);
	if (fd < 0) {
		printf("%s: %s\n", "Open Error", strerror(errno));
	}
	int temp = 0;
	if (read(fd, &temp, sizeof(temp)) < 0) {
		printf("%s: %s\n", "Read Error", strerror(errno));
	}
	close(fd);
	return temp;
}