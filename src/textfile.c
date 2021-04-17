/**
  textfile.c - text file I/O.

  (C) 2021 Richard Neumann <mail at richard dash neumann period de>

  This library is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <errno.h>
#include <stdio.h>

#include "textfile.h"

int freads(char *filename, char *buf, size_t size)
{
	FILE *fp;

	fp = fopen(filename, "r");
	if (fp == NULL)
		return -EIO;

	fgets(buf, size, fp);
	fclose(fp);
	return 0;
}

int fwrites(char *filename, char *value)
{
	FILE *fp;

	fp = fopen(filename, "w");
	if (fp == NULL)
		return -EIO;

	fprintf(fp, value);
	fclose(fp);
	return 0;
}
