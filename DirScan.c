#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
void printdir(char *dir, int depth) {
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	//디렉토리가 없을 때
	if((dp = opendir(dir)) == NULL) {
		fprintf(stderr,"cannot open directory: %s\n", dir);
		return;
	}
	chdir(dir);

	while((entry = readdir(dp)) != NULL) {
		lstat(entry->d_name,&statbuf);
		if(S_ISDIR(statbuf.st_mode)) {
			if(strcmp(".",entry->d_name) == 0 ||
				strcmp("..",entry->d_name) == 0) continue;
			
			if(entry->d_name[0]=='.') continue;	//파일이름이 0으로 시작하면 무시

			printf("%*s%s/\n", depth, "", entry->d_name);
			printdir(entry->d_name,depth+4);
		} else printf("%*s%s\n", depth, "", entry->d_name);
	}
	chdir("..");
	closedir(dp);
}
int main() {
	printf("Directory scan of /home:\n");
	printdir("/home",0);
	printf("done.\n");
	exit(0);
}