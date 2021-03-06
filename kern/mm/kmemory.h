/*
 * Copyright (c) 2014, Justin Crawford <Justasic@gmail.com>
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
#ifndef __KMEMORY_H__
#define __KMEMORY_H__
#include <stdint.h>
#include "lib/common.h"

// malloc functions.
extern void *kalloc(size_t sz);
extern void *kalloc_align(size_t sz);
extern void *kalloc_phys(size_t sz, uint32_t *phys);
extern void *kalloc_align_phys(size_t sz, uint32_t *phys);
extern void *kalloc_align_phys_nowipe(size_t sz, uint32_t *phys);

extern void kfree(void *p);
extern void CleanHeaps(void);

// Calculation functions
extern uint32_t MemoryReduce(uint32_t bytes);
extern const char *MemoryReduceSuffix(uint32_t bytes);

// Used in i386/pc/kmemdetect.c -- SMAP entry structure
typedef struct SMAP_entry {
	
	uint32_t BaseL; // base address QWORD
	uint32_t BaseH;
	uint32_t LengthL; // length QWORD
	uint32_t LengthH;
	uint16_t Type; // entry Ttpe
	uint16_t ACPI; // exteded
	
}__packed SMAP_entry_t;

extern uint32_t __attribute__((regparm(3))) detectMemory(SMAP_entry_t* buffer, uint32_t maxentries);

#endif // __KMEMORY_H__
