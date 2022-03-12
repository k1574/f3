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


void
skipn(int n)
{
	int i;
	FFPixel buf;
	for(i=0 ; i<n ; ++i)
		ff_read_pixel(0, &buf);
}


int
doimg(void)
{
	FFPixel buf1, buf2, *pbuf;
	u32 wl, hl;
	int i, j;
	ff_read_header(0, &wl, &hl);
	for(i=0 ; i<h && i<hl ; ++i){
		for(j=0 ; j<w && j<wl ; ++j){
			if(!ff_read_pixel(0, &buf1))
				return 1 ;
			layover(&buf2, buf + i*w + j, &buf1);
			ff_copy_pixel(buf + i*w + j, &buf2);
		}
	}
	
	return 0 ;
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

