/**
  sysrq.h - User space sysrq interface

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
#ifndef SYSRQ_H
#define SYSRQ_H

#include <stdbool.h>

bool sysrq_enabled();
int set_sysrq(bool enabled);
int enable_sysrq();
int disable_sysrq();
int ensure_sysrq(bool enabled);
int sysrq(char *code);

#endif
