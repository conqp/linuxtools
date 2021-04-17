/**
  emerg_reboot.c - Emergency reboot: Reboot a Linux system using sysrq.

  (C) 2021 Richard Neumann <mail at richard dash neumann period de>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this library.  If not, see <http://www.gnu.org/licenses/>.

  Note:
	The compiled binary must have the suid bit set
	in order to work for an arbitrary user.
*/
#include <errno.h>
#include <stdio.h>

static char SYSRQ_ENABLE[] = "/proc/sys/kernel/sysrq";
static char SYSRQ_TRIGGER[] = "/proc/sysrq-trigger";

static int write_to_file(char *filename, char *value)
{
	int rc;
	FILE *fp;

	fp = fopen(filename, "w");
	if (fp == NULL)
		return -EIO;

	rc = fprintf(fp, value);
	fclose(fp);
	return rc;
}

int sysrq(char *code)
{
        int rc;

        rc = write_to_file(SYSRQ_ENABLE, "1");
        if (rc < 0)
                return rc;

        rc = write_to_file(SYSRQ_TRIGGER, code);
        if (rc < 0)
                return rc;

	return 0;
}

int main()
{
	return sysrq("b");
}
