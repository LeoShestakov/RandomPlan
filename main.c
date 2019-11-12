#include "functions.h"
#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main() {
	int arr[10];
	int x = 0;
	for (; x < 10; x++) {
		arr[x] = genRandom();
		printf("random %d: %d\n", x, arr[x]);
	}
	int fd = open("file.txt", O_CREAT | O_WRONLY, 0644);
	if (fd < 0) {
		printf("%s: %s\n", "Open Error", strerror(errno));
	}
	
	printf("-----Writing numbers to file-----\n");
	if (write(fd, arr, sizeof(arr)) < 0) {
		printf("%s: %s\n", "Write Error", strerror(errno));
	}
	close(fd);
	
	int cloned[10];
	fd = open("file.txt", O_RDONLY);
	if (fd < 0) {
		printf("%s: %s\n", "Open Error", strerror(errno));
	}
	
	printf("-----Reading numbers from file-----\n");
	if (read(fd, cloned, sizeof(cloned)) < 0) {
		printf("%s: %s\n", "Write Error", strerror(errno));
	}
	close(fd);
	
	printf("-----Printing read numbers from file-----\n");
	for (x = 0; x < 10; x++) {
		printf("random %d: %d\n", x, cloned[x]);
	}
	return 0;
}
