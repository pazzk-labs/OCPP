/*
 * SPDX-FileCopyrightText: 2024 Kyunghwan Kwon <k@libmcu.org>
 *
 * SPDX-License-Identifier: MIT
 */

#include "ocpp/ocpp.h"
#include <string.h>
#include <errno.h>

int ocpp_send_bootnotification(const struct ocpp_BootNotification *msg)
{
	if (strlen(msg->chargePointModel) <= 0 ||
			strlen(msg->chargePointVendor) <= 0) {
		return -EINVAL;
	}

	return ocpp_push_message(OCPP_MSG_ROLE_CALL,
			OCPP_MSG_BOOTNOTIFICATION, msg, sizeof(*msg));
}

int ocpp_send_datatransfer(const struct ocpp_DataTransfer *msg)
{
	if (strlen(msg->vendorId) <= 0) {
		return -EINVAL;
	}

	return ocpp_push_message(OCPP_MSG_ROLE_CALL,
			OCPP_MSG_DATA_TRANSFER, msg, sizeof(*msg));
}
