/*
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	Copyright (C) 2011 Luka Perkov <freecwmp@lukaperkov.net>
 */

#include <time.h>

char local_time[32] = {0};

char *mix_get_time_of(time_t t_time)
{
    struct tm *t_tm;

    t_tm = localtime(&t_time);
    if (t_tm == NULL)
        return NULL;

    if (strftime(local_time, sizeof(local_time), "%FT%T%z", t_tm) == 0)
        return NULL;

    local_time[25] = local_time[24];
    local_time[24] = local_time[23];
    local_time[22] = ':';
    local_time[26] = '\0';

    return local_time;
}

char *mix_get_time(void)
{
    time_t t_time;
    t_time = time(NULL);
    mix_get_time_of(t_time);
    return local_time;
}
