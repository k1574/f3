#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <time.h>

#include <ff/ff.h>

static char *argv0;

void
usage(void)
{
	fprintf(stderr, "usage: %s <width> <height>\n", argv0);
	exit(1);
}

int
main(int argc, char *argv[])
{
	u32 w, h, s, i;
	FFPixel p;
	argv0 = argv[0] ;

	if(argc!=3)
		usage();

	w = atoi(argv[1]) ;
	h = atoi(argv[2]) ;

	if(!w || !h)
		usage();

	s = w*h ;
	srand(time(0));

	ff_write_header(1, w, h);

	for( i=0 ; i<s ; ++i){
		p.r = rand() % 2 ? rand() : rand() * 2 ;
		p.g = rand() % 2 ? rand() : rand() * 2 ;
		p.b = rand() % 2 ? rand() : rand() * 2 ;
		p.a = rand() % 2 ? rand() : rand() * 2 ;
		ff_write_pixel(1, &p);
	}

	return 0;
}

