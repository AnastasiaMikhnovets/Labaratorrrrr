// Подключение библиотек
#include "xtimer.h"
#include "timex.h"
#include "periph/gpio.h"

// Макрос для интервала времени, в течение которого трэд будет спать
#define INTERVAL 200000
#define INTERVAL1 200000

int main(void)
{
  // ВременнАя метка для отсчета времени сна
  xtimer_ticks32_t last_wakeup = xtimer_now();
  // Инициализация пина PC8 на выход
  gpio_init(GPIO_PIN(PORT_C, 8), GPIO_OUT);
 gpio_init(GPIO_PIN(PORT_C, 9), GPIO_OUT);

    while(1) {
      // Задача засыпает на период времени, равный значению макроса INTERVAL
      // Пин PC8 переключает свое состояние на противоположное
      gpio_toggle(GPIO_PIN(PORT_C, 8));
 xtimer_periodic_wakeup(&last_wakeup, INTERVAL);
 gpio_toggle(GPIO_PIN(PORT_C, 9));
 xtimer_periodic_wakeup(&last_wakeup, INTERVAL1);
    }

    return 0;
}

/* 
Задание 1. Установите интервал переключения светодиода на 0.5 секунды.
Задание 2. Сделайте так, чтобы вместо одного светодиода моргал другой.
Задание 3. Сделайте так, чтобы светодиоды моргали попеременно - один выключился, другой включился.
*/
