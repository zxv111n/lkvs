// SPDX-License-Identifier: GPL-2.0-only
/*
 *
 * Copyright (c) 2024 Intel Corporation.
 * Jiaxi Chen <jiaxi.chen@linux.intel.com>
 * Jiaan Lu <jiaan.lu@intel.com>
 *
 */

#include <stdio.h>
#include <limits.h>
#include "cmpxadd.c"
void main(void)
{
	unsigned long uop1, uop2, uop3;
	long op1, op2, op3;
	struct output_signed output;

	op1 = -2;
	op2 = LONG_MAX;
	op3 = 1;
	output = cmp_no_add(op1, op2, op3);
	printf("cmp_no_add - target: *(rax) = -2, rbx = -2, rcx = 1, rflags = 0xa16\n");
	if (output.rax == -2 && output.rbx == -2 && output.rcx == 1 && output.rflags == 0xa16)
		printf("Test passed\n");
	else
		printf("Test failed\n");
}
