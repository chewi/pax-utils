/*
 * Copyright 2003-2007 Gentoo Foundation
 * Distributed under the terms of the GNU General Public License v2
 * $Header: /var/cvsroot/gentoo-projects/pax-utils/xfuncs.h,v 1.6 2011/10/03 16:19:18 vapier Exp $
 *
 * Copyright 2003-2007 Ned Ludd        - <solar@gentoo.org>
 * Copyright 2004-2007 Mike Frysinger  - <vapier@gentoo.org>
 */

#ifndef __XFUNCS_H__
#define __XFUNCS_H__

char *xstrdup(const char *s);
void *xmalloc(size_t size);
void *xzalloc(size_t size);
void *xrealloc(void *ptr, size_t size);
void xstrncat(char **dst, const char *src, size_t *curr_len, size_t n);
#define xstrcat(dst,src,curr_len) xstrncat(dst,src,curr_len,0)
void xchrcat(char **dst, const char append, size_t *curr_len);

void *xmemdup(const void *src, size_t n);

typedef struct {
	void **eles;
	size_t num;
} array_t;
void xarraypush(array_t *array, const void *ele, size_t ele_len);
#define xarraypush_str(arr, ele) xarraypush(arr, ele, strlen(ele) + 1 /*NUL*/)
void xarrayfree(array_t *array);
#define xrealloc_array(ptr, size, ele_size) xrealloc(ptr, (size) * (ele_size))
#define array_for_each(arr, n, ele) \
	for (n = 0, ele = arr->eles[n]; n < arr->num; ++n, ele = arr->eles[n])
#define array_init_decl { .eles = NULL, .num = 0, }
#define array_cnt(arr) (arr)->num
char *array_flatten_str(array_t *array);

#endif
