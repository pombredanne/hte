/* 
 *	HT Editor
 *	htpefimg.h
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

#ifndef __HTPEFIMG_H__
#define __HTPEFIMG_H__

#include "htanaly.h"
#include "htpef.h"
#include "formats.h"

extern format_viewer_if htpefimage_if;

/*
 *	ht_pef_aviewer
 */

class ht_pef_aviewer: public ht_aviewer {
public:
	ht_pef_shared_data *pef_shared;
		   void init(bounds *b, char *desc, int caps, ht_streamfile *file, ht_format_group *format_group, Analyser *Analyser, ht_pef_shared_data *pef_shared);
	virtual int  func_handler(eval_scalar *result, char *name, eval_scalarlist *params);
	virtual void setAnalyser(Analyser *a);
};

#endif /* !__HTPEFIMG_H__ */
