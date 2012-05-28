/*************************************************************
 * This file was automatically generated on 11.04.2012.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICK_MASTER_H
#define BRICK_MASTER_H

#include "ip_connection.h"

typedef Device Master;


void master_create(Master *master, const char *uid);

int master_get_stack_voltage(Master *master, uint16_t *ret_voltage);
int master_get_stack_current(Master *master, uint16_t *ret_current);
int master_set_extension_type(Master *master, uint8_t extension, uint32_t exttype);
int master_get_extension_type(Master *master, uint8_t extension, uint32_t *ret_exttype);
int master_is_chibi_present(Master *master, bool *ret_present);
int master_set_chibi_address(Master *master, uint8_t address);
int master_get_chibi_address(Master *master, uint8_t *ret_address);
int master_set_chibi_master_address(Master *master, uint8_t address);
int master_get_chibi_master_address(Master *master, uint8_t *ret_address);
int master_set_chibi_slave_address(Master *master, uint8_t num, uint8_t address);
int master_get_chibi_slave_address(Master *master, uint8_t num, uint8_t *ret_address);
int master_get_chibi_signal_strength(Master *master, uint8_t *ret_signal_strength);
int master_get_chibi_error_log(Master *master, uint16_t *ret_underrun, uint16_t *ret_crc_error, uint16_t *ret_no_ack, uint16_t *ret_overflow);
int master_set_chibi_frequency(Master *master, uint8_t frequency);
int master_get_chibi_frequency(Master *master, uint8_t *ret_frequency);
int master_set_chibi_channel(Master *master, uint8_t channel);
int master_get_chibi_channel(Master *master, uint8_t *ret_channel);
int master_get_version(Master *master, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);
void master_register_callback(Master *master, uint8_t cb, void *func);

#endif