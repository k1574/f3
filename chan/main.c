#include <stdio.h>
#include <stdlib.h>
#include <ff/ff.h>

enum Chan {
	Red,
	Green,
	Blue,
	Alpha,
} ;

void
usage(void)
{
	fprintf(stderr, "usage: %s <rgba>");
}

int
doimg(void)
{
	FFPixel buf;
	u32 w, h, n;
	if(ff_read_header(0, &w, &h))
		return 1 ;

	n = w * h ;

	while(n){
		if(ff_read_pixel(0, &buf))
			return 1 ;
		--n;
	}

	return 0 ;
}

int
main(int argc, char *argv[])
{
	while(!doimg())
		;
	if(argc != 2)
		return 1 ;
	return 0 ;
}

