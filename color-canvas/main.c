#include <stdio.h>
#include <stdlib.h>
#include <ff/ff.h>

char *argv0;

void
usage(void)
{
	fprintf(stderr, "usage: %s <width> <height> <color>\n", argv0);
	exit(1);
}

int
main(int argc, char *argv[])
{
	FFPixel px;
	u32 w, h, n, i;
	argv0 = argv[0] ;
	if(argc != 4)
		usage();

	w = atoi(argv[1]) ;
	h = atoi(argv[2]) ;
	n = w*h ;
	ff_colorname_to_pixel(&px, argv[3]);

	ff_write_header(1, w, h);
	for(i=0 ; i<n ; ++i)
		ff_write_pixel(1, &px);

	return 0 ;
}
