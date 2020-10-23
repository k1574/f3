#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <time.h>

#include "../endian.h"
#include "../farbfeld.h"

static char *argv0;

void
usage(void)
{
	fprintf(stderr, "usage: %s [width] [height]\n", argv0);
	exit(1);
}

int
main(int argc, char *argv[])
{
	uint32_t w, h, s, i;
	Pixel p;
	argv0 = argv[0] ;

	if(argc!=3)
		usage();

	w = atoi(argv[1]) ;
	h = atoi(argv[2]) ;

	if(!w || !h)
		usage();

	s = w*h ;
	if(islittleendian()){
		swapendian(&h, 4);
		swapendian(&w, 4);
	}
	
	srand(time(0));

	printf("farbfeld");
	fwrite(&w, 4, 1, stdout);
	fwrite(&h, 4, 1, stdout);

	for( i=0 ; i<s ; ++i){
		p.r = rand() % 2 ? rand() : rand() * 2 ;
		p.g = rand() % 2 ? rand() : rand() * 2 ;
		p.b = rand() % 2 ? rand() : rand() * 2 ;
		p.a = rand() % 2 ? rand() : rand() * 2 ;
		fwrite(&p, 8, 1, stdout);
	}

	return 0;
}

