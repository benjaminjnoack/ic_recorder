#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>

#define RECORDINGS_DIR "/media/ben/IC RECORDER1/REC_FILE/FOLDER01/"

int main()
{
	DIR *dir;
	struct dirent *entry;
	char filepath[256];
	size_t dirnamelen;

	strcpy(filepath, RECORDINGS_DIR);
	dirnamelen = strlen(filepath);

	dir = opendir(filepath);
	if (dir == NULL) {
		perror("opendir");
		return 1;
	}

	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_type == DT_REG) {
			printf("%s\t", entry->d_name);
			strcpy(filepath + dirnamelen, entry->d_name);
			printf("%s\n", filepath);
		}
	}

	closedir(dir);

	return 0;
}
