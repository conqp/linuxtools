/**
  sysrq.c - User space sysrq interface

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
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "textfile.h"
#include "sysrq.h"

static char SYSRQ_ENABLE[] = "/proc/sys/kernel/sysrq";
static char SYSRQ_TRIGGER[] = "/proc/sysrq-trigger";

bool sysrq_enabled()
{
	char buf[4];
	int rc;

	rc = freads(SYSRQ_ENABLE, buf, 4);
	if (rc)
		return false;

	return strcmp(buf, "0\n");
}

int set_sysrq(int state)
{
	char value[4];
	sprintf(value, "%d", state);
	return fwrites(SYSRQ_ENABLE, value);
}

int enable_sysrq()
{
	return set_sysrq(1);
}

int disable_sysrq()
{
	return set_sysrq(0);
}

int ensure_sysrq(bool enabled)
{
	bool state = sysrq_enabled();

	if (state && !enabled)
		return disable_sysrq();

	if (!state && enabled)
		return enable_sysrq();

	return 0;
}

int sysrq(char code)
{	
	return fwrites(SYSRQ_TRIGGER, &code);
}
