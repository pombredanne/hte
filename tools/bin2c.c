/*
 *	bin2c.c
 *
 *	Copyright (C) 2001, 2002 Stefan Weyergraf (stefan@weyergraf.de)
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License version 2 as
 *	published by the Free Software Foundation.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program; if not, write to the Free Software
 *	Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <dirent.h>		/* for NAME_MAX */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef NAME_MAX
#define NAME_MAX 255
#endif

#define OPT_FORCE_HEX	1

int options = 0;

#define ERROR(s...) { printf("error: " s); puts("\n"); exit(1); }

void char2cchar(char *buf, char c)
{
	if ((!(options & OPT_FORCE_HEX)) && ((c>=32) && (c<='~'))) {
		if (c=='\'') {
			strcpy(buf, "'\\''");
		} else if (c=='\\') {
			strcpy(buf, "'\\\\'");
		} else {
			sprintf(buf, "'%c'", (unsigned char)c);
		}
	} else {
		sprintf(buf, "0x%02x", (unsigned char)c);
	}
}

#define BUFSIZE 1024
#define CHARS_PER_LINE 8

void bin2c_table(int size, FILE *in, FILE *out)
{
	char buf[BUFSIZE];
	size_t s = sizeof buf;
	int i, j=0;
	char elem[16];

	while ((s = fread(buf, 1, s, in))) {
		for (i = 0; i < s; i++) {
			int elemlen;
			if (i % CHARS_PER_LINE == 0) {
				fputs("\t", out);
			}
			char2cchar(elem, buf[i]);
			elemlen = strlen(elem);
			fputs(elem, out);
			if (j+1 < size) {
				int k;
				fputs(",", out);
				for (k=0; k<4-elemlen; k++) fputs(" ", out);
				if ((j+1) % CHARS_PER_LINE == 0) {
					fputs("\n", out);
				}
			} else {
				fputs("\n", out);
			}
			j++;
		}
	}
}

void bin2c(char *name, int size, FILE *in, FILE *out, char *inname)
{
	fprintf(out, "/* generated by bin2c from %s */\n\n", inname);
	fprintf(out, "char %s[%d] = {\n", name, size);
	bin2c_table(size, in, out);
	fputs("};\n", out);
}

void bin2h(char *name, int size, FILE *out, char *outname)
{
	char q[NAME_MAX];
	int i, l;
	strcpy(q, outname);
	l=strlen(q);
	for (i=0; i<l; i++) {
		if ((q[i]>='a') && (q[i]<='z')) {
			q[i]+='A'-'a';
		}
		if (((q[i]<'A') || (q[i]>'Z')) &&
			((q[i]<'0') || (q[i]>'9'))) {
			q[i]='_';
		}
	}
	fprintf(out, "#ifndef __%s\n", q);
	fprintf(out, "#define __%s\n\n", q);
	fputs("extern\n#ifdef __cplusplus\n\"C\"\n#endif\n", out);
	fprintf(out, "char %s[%d];\n", name, size);
	fprintf(out, "\n#endif /* __%s */\n", q);
}

void syntax(char *name)
{
	printf("syntax: %s [-Ndataname] infile c-outfile [h-outfile]\n", name);
	exit(1);
}

int main(int argc, char *argv[])
{
	int l;
	FILE *in=NULL, *out=NULL, *outh=NULL;
	char *inname, *outname, *outhname;
	char *name="bindata";
	int x=1;
	char n[NAME_MAX];

	if ((argc>1) && (strncmp(argv[1], "-N", 2)==0)) {
		name=argv[1]+2;
		x++;
	}

	if (argc>=x+1) {
		inname=argv[x];
	} else {
		syntax(argv[0]);
	}
	in=fopen(inname, "rb");
	if (!in) ERROR("can't open input file: %s", inname);

	if (argc>=x+2) {
		outname=argv[x+1];
		if (argc>=x+3) {
			outhname=argv[x+2];
		} else {
			int k=strlen(outname);
			strcpy(n, outname);
			if ((k>2) && (strncmp(argv[x+1]+k-2, ".c", 2)==0)) {
				strcpy(n+k-2, ".h");
			} else {
				strcpy(n+k, ".h");
			}
			outhname=n;
		}
		outh=fopen(outhname, "wb");
		if (!outh) ERROR("can't open .h output file: %s", outhname);
	} else {
		ERROR("no output file");
	}
	out=fopen(outname, "wb");
	if (!out) ERROR("can't open .c output file: %s", outname);

	fseek(in, 0, SEEK_END);
	l=ftell(in);
	fseek(in, 0, SEEK_SET);

	bin2c(name, l, in, out, inname);
	bin2h(name, l, outh, outhname);

	return 0;
}
