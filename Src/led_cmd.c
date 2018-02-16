/*
 * led_cmd.c
 *
 *  Created on: Feb 1, 2018
 *      Author: E9990291
 */


#include "led_cmd.h"
#include "stm32f1xx_hal.h"

int cmd_do_ledon(int argc, char** argv, cmd_line_desc_ptr_t cmd_line_desc) {
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
  cmd_line_printf_tk(cmd_line_desc, "LED ON\r\n");
  return CMD_LINE_SUCCESS;
}

int cmd_do_ledoff(int argc, char** argv, cmd_line_desc_ptr_t cmd_line_desc) {
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
  cmd_line_printf_tk(cmd_line_desc, "LED OFF\r\n");
  return CMD_LINE_SUCCESS;
}

int cmd_do_led(int argc, char** argv, cmd_line_desc_ptr_t cmd_line_desc) {
  if (argc == 0) {
      GPIO_PinState led_state = HAL_GPIO_ReadPin(LD2_GPIO_Port, LD2_Pin);
      if (led_state == GPIO_PIN_SET) {
          cmd_line_printf_tk(cmd_line_desc, "LED is ON\r\n");
      }
      else {
          cmd_line_printf_tk(cmd_line_desc, "LED is OFF\r\n");
      }
  }

  else {
      switch (argv[1][0]) {
        case '0':
          HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
          cmd_line_printf_tk(cmd_line_desc, "LED OFF\r\n");
          break;
        case '1':
          HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
          cmd_line_printf_tk(cmd_line_desc, "LED ON\r\n");
          break;
        default:
          cmd_line_printf_tk(cmd_line_desc, "Invalid parameter.\r\n");
          break;
      }
  }

  return CMD_LINE_SUCCESS;
}


cmd_desc_t cmd_desc_led_on =
    {
        .name = "ledon",
        .one_line = "Set LD2 on",
        .description = "ledon\r\n"
            "Set LD2 on Nucleo board on.\r\n"
            "\r\n"
            "Example:\r\n"
            "\t--> ledon\r\n"
            "\tLED ON\r\n",
        .cmd_fcn = &cmd_do_ledon
    };

cmd_desc_t cmd_desc_led_off =
    {
        .name = "ledoff",
        .one_line = "Set LD2 off",
        .description = "ledoff\r\n"
            "Set LD2 on Nucleo board off.\r\n"
            "\r\n"
            "Example:\r\n"
            "\t--> ledoff\r\n"
            "\tLED OFF\r\n",
        .cmd_fcn = &cmd_do_ledoff
    };

cmd_desc_t cmd_desc_led =
    {
        .name = "led",
        .one_line = "Set or get LED state",
        .description = "led {state}\r\n"
            "If state present, sets the LD2 state to its value.\r\n"
            "If state is not present, reads the current LD2 state."
            "\r\n"
            "Example:\r\n"
            "\t--> led 1\r\n"
            "\tLED ON\r\n",
            "\t--> led\r\n"
            "\tLED is ON\r\n",
        .cmd_fcn = &cmd_do_led
    };

const cmd_desc_t* led_cmd_list[] =
  {
      &cmd_desc_led_on,
      &cmd_desc_led_off,
      &cmd_desc_led,
      NULL
  };
