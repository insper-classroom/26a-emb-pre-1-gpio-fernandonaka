#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 28;

const int LED_PIN_V = 5;
const int LED_PIN_L = 8;
const int LED_PIN_A = 11;
const int LED_PIN_Y = 15;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  gpio_init(LED_PIN_V);
  gpio_set_dir(LED_PIN_V, GPIO_OUT);

  gpio_init(LED_PIN_L);
  gpio_set_dir(LED_PIN_L, GPIO_OUT);

  gpio_init(LED_PIN_A);
  gpio_set_dir(LED_PIN_A, GPIO_OUT);

  gpio_init(LED_PIN_Y);
  gpio_set_dir(LED_PIN_Y, GPIO_OUT);

  while (true) {
    // Use delay de 300 ms entre os estados!
    if (!gpio_get(BTN_PIN)) {
      sleep_ms(300);
      gpio_put(LED_PIN_V, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_V, 0);
      gpio_put(LED_PIN_L, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_L, 0);
      gpio_put(LED_PIN_A, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_A, 0);
      gpio_put(LED_PIN_Y, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_Y, 0);
      while (!gpio_get(BTN_PIN)) {
      };
    }

  }
}
