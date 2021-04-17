/**
  emerg_reboot.c - Emergency reboot: Reboot a Linux system using sysrq.

  (C) 2021 Richard Neumann <mail at richard dash neumann period de>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this library.  If not, see <http://www.gnu.org/licenses/>.

  Note:
	The compiled binary must have the suid bit set
	in order to work for an arbitrary user.
*/
#include <stdbool.h>

#include "sysrq.h"

int main()
{
	int rc;

	rc = ensure_sysrq(true);
	if (rc)
		return rc;

	return sysrq('b');
}
