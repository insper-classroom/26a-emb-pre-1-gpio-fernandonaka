#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 28;
const int BTN_PIN2 = 26;

const int LED_PIN_R = 4;
const int LED_PIN_Y = 6;



int main() {
  int led_r_state = 0;
  int led_y_state = 0;
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  gpio_init(BTN_PIN2);
  gpio_set_dir(BTN_PIN2, GPIO_IN);
  gpio_pull_up(BTN_PIN2);

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);

  gpio_init(LED_PIN_Y);
  gpio_set_dir(LED_PIN_Y, GPIO_OUT);

  while (true) {
    if (!gpio_get(BTN_PIN)) {
      led_r_state = !led_r_state;
      gpio_put(LED_PIN_R, led_r_state);
      while (!gpio_get(BTN_PIN)) {};
    }
    if (!gpio_get(BTN_PIN2)) {
      led_y_state = !led_y_state;
      gpio_put(LED_PIN_Y, led_y_state);
      while (!gpio_get(BTN_PIN2)) {};
    }
  }
}
