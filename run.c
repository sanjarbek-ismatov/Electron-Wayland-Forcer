#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int main(int argc, char* argv[]){
	if (argc < 2){
		printf("Error, could not recognize the program!\n");
		return 1;
	}
	char all_arg[256] = "";
	char* program = argv[1];
	bool is_chromium = strcmp(program, "--chromium") == 0 ? true : false;
	if(strcmp(program, "--chromium") == 0) is_chromium = true;
	for(int i = is_chromium ? 2 : 1; i < argc; i++){
		strcat(all_arg, " ");
		strcat(all_arg, argv[i]);
	}
	char run_flags[] = "--ozone-platform-hint=auto";
	char chromium_flags[] = "--enable-features=VaapiVideoDecoder,VaapiIgnoreDriverChecks,Vulkan,DefaultANGLEVulkan,VulkanFromANGLE,TouchpadOverscrollHistoryNavigation";
	// Vulkan flags: Vulkan,DefaultANGLEVulkan,VulkanFromANGLE
	char run[256];
	if(is_chromium){
		sprintf(run, "%s %s %s", all_arg, run_flags, chromium_flags);
		system(run);
	} else{
		sprintf(run, "%s %s", all_arg, run_flags);
		system(run);
	}
	return 0;
}
