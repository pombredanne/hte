/* 
 *	HT Editor
 *	lestruct.cc
 *
 *	Copyright (C) 1999-2002 Stefan Weyergraf (stefan@weyergraf.de)
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

#include "lestruct.h"
#include "htendian.h"

byte LE_HEADER_struct[] = {
	STRUCT_ENDIAN_WORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_BYTE | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_BYTE | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_WORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_WORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_BYTE | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_WORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_WORD | STRUCT_ENDIAN_HOST,
     0
};

byte LE_FIXUP_struct[] = {
	STRUCT_ENDIAN_BYTE | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_BYTE | STRUCT_ENDIAN_HOST,
     0
};

byte LE_ENTRYPOINT16_struct[] = {
	STRUCT_ENDIAN_BYTE | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_WORD | STRUCT_ENDIAN_HOST,
	0
};

byte LE_ENTRYPOINT32_struct[] = {
	STRUCT_ENDIAN_BYTE | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	0
};

byte LE_VXD_DESCRIPTOR_struct[] = {
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_WORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_WORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_BYTE | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_BYTE | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_WORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_BYTE | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	0
};

byte LE_FIXUP_INTERNAL_struct[] = {
	STRUCT_ENDIAN_BYTE | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_WORD | STRUCT_ENDIAN_HOST,
	0
};

byte LE_OBJECT_HEADER_struct[] = {
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_BYTE | STRUCT_ENDIAN_HOST,
	0
};

byte LE_PAGE_MAP_ENTRY_struct[] = {
	STRUCT_ENDIAN_WORD | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_BYTE | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_BYTE | STRUCT_ENDIAN_HOST,
	0
};

byte LE_FIXUP_INTERNAL16_struct[] = {
	STRUCT_ENDIAN_BYTE | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_WORD | STRUCT_ENDIAN_HOST,
	0
};

byte LE_FIXUP_INTERNAL32_struct[] = {
	STRUCT_ENDIAN_BYTE | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_DWORD | STRUCT_ENDIAN_HOST,
	0
};

