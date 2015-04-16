#include "common.h"
#include "init.h"
#include "vfs.h"
#include "deepfat.h"

void driver_init(){
	//vfs_mkdir(df_root, "/dev");
	DEVLOAD(dev_stdout)
	DEVLOAD(dev_stderr)
	DEVLOAD(dev_stdin)
	DEVLOAD(dev_null)
}
