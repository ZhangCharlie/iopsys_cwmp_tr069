/*
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	Copyright (C) 2012 Luka Perkov <freecwmp@lukaperkov.net>
 */

#ifndef _FREECWMP_UBUS_H__
#define _FREECWMP_UBUS_H__

int  ubus_init(struct cwmp *cwmp);
void ubus_exit(void);

#endif
