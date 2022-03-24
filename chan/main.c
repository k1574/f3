#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ff/ff.h>

enum Chan {
	Red = 1,
	Green = 2,
	Blue = 4,
	Alpha = 8,
} ;

char *argv0;
int param;
float val = 0;

void
usage(void)
{
	fprintf(stderr, "usage: %s <r|g|b|a> [val]\n", argv0);
	exit(1);
}

int
doimg(void)
{
	FFPixel buf;
	u32 w, h, n;
	if(ff_read_header(0, &w, &h))
		return 1 ;

	n = w * h ;

	ff_write_header(1, w, h);
	while(n){
		if(!ff_read_pixel(0, &buf))
			return 1 ;
		switch(param){
		case Red :
			buf.r *= val ;
		break;
		case Green :
			buf.g *= val ;
		break;
		case Blue :
			buf.b *= val ;
		break;
		case Alpha :
			buf.a *= val ;
		break;
		default:
		}

		ff_write_pixel(1, &buf);
		--n;
	}

	return 0 ;
}

int
main(int argc, char *argv[])
{
	int err;
	char *c;

	argv0 = argv[0] ;
	if(argc < 2)
		usage();

	if(strlen(argv[1]) != 1)
		usage();
	c = argv[1] ;
	switch(*c){
	case 'r' :
		param = Red;
		break;
	case 'g' :
		param = Green ;
		break;
	case 'b' :	
		param = Blue ;
		break;
	case 'a' :
		param = Alpha;
		break;
	default:
		usage();
	}

	if(argc == 3)
		val = atof(argv[2]) ;

	while(!doimg())
		;

	return 0 ;
}

