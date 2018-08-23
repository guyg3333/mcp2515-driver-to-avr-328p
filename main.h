/*
 * main.h
 *
 *  Created on: 23 срхїз 2016
 *      Author: etty
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "usci.h"
#include <avr/io.h>
#include "stdio.h"
#include <avr/delay.h>


//set can address
extern unsigned int can_addr;

//Integer type defs
typedef char				int8;
typedef int             	int16;
typedef long            	int32;
typedef long long			int64;
typedef unsigned char		UInt8;
typedef unsigned int    	UInt16;
typedef unsigned long   	UInt32;
typedef unsigned long long	UInt64;
typedef float				float32;
typedef int                 BOOL;


// Typedefs for quickly joining multiple bytes/ints/etc into larger values
// These rely on byte ordering in CPU & memory - i.e. they're not portable across architectures

typedef union _group_64 {
	UInt64	data_u64;
	int64	data_64;
	float32	data_fp[2];
	UInt8	data_u8[8];
	int8	data_8[8];
	UInt16	data_u16[4];
	int16	data_16[4];
	UInt32	data_u32[2];
	int32	data_32[2];
} group_64;













#endif /* MAIN_H_ */
