#include <stdio.h>

#include <ff/ff.h>

int
main(int argc,char**argv)
{
	u32 w, h;
	ff_read_header(0, &w, &h);
	printf("%d %d", w, h);
	return 0;
}
