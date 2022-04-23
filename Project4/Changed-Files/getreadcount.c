#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[]){
	if (argc == 2){
	  getreadcount(1);
	} else if (argc > 2){
	  printf(1, "Incorrect number of arguments passed.\n");
	  exit();
	} else {
	  getreadcount(0);
	}
	exit();
}
