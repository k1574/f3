#include <ff/ff.h>
#include <stdio.h>
#include <stdlib.h>

FFPixel *buf;
u32 w, h;

void (*layover)(FFPixel *, FFPixel *, FFPixel *);

void
alphablend(FFPixel *buf, FFPixel *bg, FFPixel *fg)
{
}

void
stdlay(FFPixel *buf, FFPixel *bg, FFPixel *fg)
{
}

void
replace(FFPixel *buf, FFPixel *bg, FFPixel *fg)
{
	ff_copy_pixel(buf, fg);
}

int
doimg(void)
{
	return ff_lay_from_fd(0, buf, w, h, layover) ;
}

int
main(int argc, char *argv[])
{
	int i, j;
	layover = replace ;

	buf = ff_read_image(0, &w, &h);
	while(!doimg())
		;

	ff_write_image(1, w, h, buf);
quit:
	return 0 ;
}

