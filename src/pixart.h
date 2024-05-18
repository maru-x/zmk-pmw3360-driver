#pragma once

/**
 * @file pixart.h
 *
 * @brief Common header file for all optical motion sensor by PIXART
 */

#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/spi.h>

#ifdef __cplusplus
extern "C" {
#endif

/* device data structure */
struct pixart_data {
  const struct device *dev;
  bool sw_smart_flag; // for pmw3360 smart algorithm

  struct gpio_callback irq_gpio_cb; // motion pin irq callback
  struct k_work trigger_work;       // realtrigger job

  struct k_work_delayable
      init_work; // the work structure for delayable init steps
  int async_init_step;

  bool ready; // whether init is finished successfully
  bool last_read_burst;
  int err; // error code during async init
};

// device config data structure
struct pixart_config {
  struct gpio_dt_spec irq_gpio;
  uint16_t cpi;
  struct spi_dt_spec bus;
  struct gpio_dt_spec cs_gpio;
  uint8_t evt_type;
  uint8_t x_input_code;
  uint8_t y_input_code;
  size_t scroll_layers_len;
  int32_t *scroll_layers;
  size_t snipe_layers_len;
  int32_t *snipe_layers;
};

#ifdef __cplusplus
}
#endif

/**
 * @}
 */
