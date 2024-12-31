// p2: A fork and wait example
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/errno.h>

int main(int argc, char *argv[])
{
	printf("Hello from (pid:%d)\n", (int)getpid());
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork error\n");
		exit(1);
	} else if (rc == 0) {
		printf("hello from child (pid:%d)\n", (int)getpid());
	} else {
		int status;
		pid_t ret = waitpid(rc, &status, 0);
		if (ret < 0) {
			fprintf(stderr, "wait error: %s\n", strerror(errno));
			exit(1);
		}
		if (ret != rc) {
			fprintf(stderr, "different child: %d!=%d\n",
				ret, rc);
			exit(1);
		}
		printf("hello from parent of child %d, status %d, (pid:%d)\n",
		       rc, status, (int) getpid());
	}
	return 0;
}
