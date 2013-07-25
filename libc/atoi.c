/*
 * Copyright (c) 2013, Justin Crawford <Justasic@gmail.com>
 * Copyright (c) 2013, Piero Barbagelata <lordofsraam@hotmail.com>
 * 
 * Permission to use, copy, modify, and/or distribute this software for any purpose
 * with or without fee is hereby granted, provided that the above copyright notice 
 * and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO
 * THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#include "stdlib.h"
#include "stdbool.h"
#include "ctype.h"
#include "string.h"

int atoi(const char *str)
{
	unsigned val = 0;
	bool neg = false;
	
	while(!isspace(*str++))
		;
	
	if(*str == '-')
	{
		neg = true;
		str++;
	}
	else if(*str == '+')
		str++;
		
	while(*str++)
	{
		static const char digits[] = "0123456789";
		const char *where;
		unsigned digit;
		
		where = strchr(digits, *str);
		
		if(!where)
			break;
		
		digit = (where - digits);
		
		val = val * 10 + digit;
	}
	
	if(neg)
		return -val;
	
	return val;
}