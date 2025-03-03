/*
 *  Header file for OneNAND support for U-Boot
 *
 *  Adaptation from kernel to U-Boot
 *
 *  Copyright (C) 2005-2007 Samsung Electronics
 *  Kyungmin Park <kyungmin.park@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __UBOOT_ONENAND_H
#define __UBOOT_ONENAND_H

#include <sys/types.h>

/* Forward declarations */
struct mtd_info;
struct mtd_oob_ops;
struct erase_info;
struct onenand_chip;

extern struct mtd_info onenand_mtd;
extern struct onenand_chip onenand_chip;

/* board */
extern void onenand_board_init(struct mtd_info *);

/* Functions */
extern void onenand_init(void);
extern int onenand_read(struct mtd_info *mtd, long long from, size_t len,
			size_t * retlen, u_char * buf);
extern int onenand_read_oob(struct mtd_info *mtd, long long from, struct mtd_oob_ops *ops);
extern int onenand_write(struct mtd_info *mtd, long long from, size_t len,
			 size_t * retlen, const u_char * buf);
extern int onenand_erase(struct mtd_info *mtd, struct erase_info *instr);

extern char *onenand_print_device_info(int device, int version);

extern unsigned onenand_block(struct onenand_chip *this, long long addr);

extern long long onenand_addr(struct onenand_chip *this, int block);

extern int flexonenand_region(struct mtd_info *mtd, long long addr);

extern int flexonenand_set_boundary(struct mtd_info *mtd, int die,
					int boundary, int lock);

/* S3C64xx */
extern void s3c64xx_onenand_init(struct mtd_info *);
extern void s3c64xx_set_width_regs(struct onenand_chip *);

#endif /* __UBOOT_ONENAND_H */
