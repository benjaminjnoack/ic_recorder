#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024 
#define DEST_DIR "/home/ben/Music/test/"
#define SRC_DIR "/media/ben/IC RECORDER1/REC_FILE/FOLDER01/"

int main()
{
	char buffer[BUFFER_SIZE];
	ssize_t nread;
	size_t destdirnamelen;
	int destfd;
	char destpath[256];
	DIR *dir;
	mode_t destperms;
	size_t srcdirnamelen;
	struct dirent *entry;
	char srcpath[256];
	int srcfd;


	strcpy(destpath, DEST_DIR);
	destdirnamelen = strlen(destpath);

	strcpy(srcpath, SRC_DIR);
	srcdirnamelen = strlen(srcpath);

	destperms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

	dir = opendir(srcpath);
	if (dir == NULL) {
		perror("opendir");
		return 1;
	}

	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_type == DT_REG) {
			strcpy(destpath + destdirnamelen, entry->d_name);
			strcpy(srcpath + srcdirnamelen, entry->d_name);
			printf("%s\t%s\t%s\t\n", entry->d_name, srcpath, destpath);
			srcfd = open(srcpath, O_RDONLY);
			if (srcfd == -1) {
				perror("open");
				continue;
			}

			destfd = creat(destpath, destperms);
			if (destfd == -1) {
				perror("open");
				continue;
			}

			while ((nread = read(srcfd, buffer, BUFFER_SIZE)) > 0) {
				if (write(destfd, buffer, nread) != nread) {
					
				}
			}

			if (nread == -1) {
				perror("read");
			}


			if (close(destfd) == -1) {
				perror("close");
				continue;
			}

			if (close(srcfd) == -1) {
				perror("close");
				continue;
			}
		}
	}

	if (closedir(dir) == -1) {
		return -1;
	} else {
		return 0;
	}
}
