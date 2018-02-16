/*
 * nucleo_cmd_list.c
 *
 *  Created on: Feb 1, 2018
 *      Author: E9990291
 */

#include "nucleo_cmd_list.h"
#include "led_cmd.h"
#include "cmd.h"

int cmd_do_hello(int argc, char** argv, cmd_line_desc_ptr_t cmd_line_desc) {
  cmd_line_printf_tk(cmd_line_desc, "Greetings Nucleo-F103RB\r\n");
  return CMD_LINE_SUCCESS;
}

cmd_desc_t cmd_desc_nucleo_hello =
    {
        .name = "hello",
        .one_line = "Prints Nucleo board hello message.",
        .description = "hello\r\n"
            "Prints Nucleo board hello message.\r\n"
            "\r\n"
            "Example:\r\n"
            "\t--> hello\r\n"
            "\tGreetings Nucleo-F103RB\r\n",
        .cmd_fcn = &cmd_do_hello
    };

const cmd_desc_t* nucleo_cmd_list[] =
  {
      CMD_LINE_INCLUDE_SUBLIST(basic_cmd_list)
      CMD_LINE_INCLUDE_SUBLIST(led_cmd_list)
      &cmd_desc_nucleo_hello,
      NULL
  };
