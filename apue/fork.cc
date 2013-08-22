/*
 * =====================================================================================
 *
 *       Filename:  fork.cc
 *
 *    Description:  Test code for 1.5.3 in apue
 *
 *        Version:  1.0
 *        Created:  08/20/2013 07:09:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    const int MAXLINE = 128;
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        buf[strlen(buf) - 1] = 0;

        if ((pid = fork()) < 0) {
            fprintf(stderr, "fork error");
        }
        else if (pid == 0) {
            execlp(buf, buf, (char *)0);
            fprintf(stderr, "couldn't execute: %s", buf);
            exit(127);
        }

        if ((pid = waitpid(pid, &status, 0)) < 0) {
            fprintf(stderr, "waitpid_error");
        }
        printf("%%");
    }

    exit(0);
}
