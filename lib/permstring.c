/* 
   Copyright (C) Andrew Tridgell 1996
   Copyright (C) Paul Mackerras 1996
   Copyright (C) 2001 by Martin Pool <mbp@samba.org>
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include <sys/stat.h>

/**
 * Produce a string representation of Unix mode bits like that used by
 * ls(1).
 *
 * @param buf buffer of at least 11 characters
 **/
void permstring(char *perms,
		int mode)
{
	static const char *perm_map = "rwxrwxrwx";
	int i;

	strcpy(perms, "----------");
	
	for (i=0;i<9;i++) {
		if (mode & (1<<i)) perms[9-i] = perm_map[8-i];
	}
	if (S_ISLNK(mode)) perms[0] = 'l';
	if (S_ISDIR(mode)) perms[0] = 'd';
	if (S_ISBLK(mode)) perms[0] = 'b';
	if (S_ISCHR(mode)) perms[0] = 'c';
	if (S_ISSOCK(mode)) perms[0] = 's';
	if (S_ISFIFO(mode)) perms[0] = 'p';
}

	
