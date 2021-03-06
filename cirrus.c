/*
 * Copyright 2014 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "drv_priv.h"
#include "helpers.h"
#include "util.h"

const static uint32_t supported_formats[] = { DRM_FORMAT_ARGB8888, DRM_FORMAT_RGB888,
					      DRM_FORMAT_XRGB8888 };

static int cirrus_init(struct driver *drv)
{
	return drv_add_linear_combinations(drv, supported_formats, ARRAY_SIZE(supported_formats));
}

struct backend backend_cirrus = {
	.name = "cirrus",
	.init = cirrus_init,
	.bo_create = drv_dumb_bo_create,
	.bo_destroy = drv_dumb_bo_destroy,
	.bo_import = drv_prime_bo_import,
	.bo_map = drv_dumb_bo_map,
};
