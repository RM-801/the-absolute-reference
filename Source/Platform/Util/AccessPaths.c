#include "Platform/Util/AccessPaths.h"
#include "physfs.h"
#include <stdio.h>

bool OpenPaths(const char* const argv0) {
	if (!PHYSFS_init(argv0)) {
		fprintf(stderr, "Error with PHYSFS_init: %s\n", PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode()));
		return false;
	}

	const char* baseDir = PHYSFS_getBaseDir();
	if (!PHYSFS_mount(baseDir, NULL, 1)) {
		fprintf(stderr, "Error mounting base dir: %s\n", PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode()));
		return false;
	}

	char romsPath[1024];
	snprintf(romsPath, sizeof(romsPath), "%sroms", baseDir);
	if (!PHYSFS_mount(romsPath, "roms", 1)) {
		fprintf(stderr, "Error mounting roms dir: %s\n", PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode()));
	}

	printf("Search path directories:\n");
	for (char** searchPath = PHYSFS_getSearchPath(); searchPath != NULL && *searchPath != NULL; searchPath++) {
		printf("%s\n", *searchPath);
	}
	printf("\n");
	
	return true;
}

void ClosePaths() {
	if (!PHYSFS_deinit()) {
		fprintf(stderr, "Failed PhysicsFS deinit: %s\n", PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode()));
	}
}
