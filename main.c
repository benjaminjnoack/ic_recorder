#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>


int main()
{
	DIR *dir;
	struct dirent *entry;

	dir = opendir("/media/ben/IC RECORDER1/REC_FILE/FOLDER01");
	if (dir == NULL) {
		perror("opendir");
		return 1;
	}

	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_type == DT_REG) {
			printf("%s\n", entry->d_name);
		}
	}


	return 0;
}
