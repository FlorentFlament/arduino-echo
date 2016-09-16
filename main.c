#include <stdio.h>
#include <util/delay.h>

#include "uart.h"

#define BUF_SIZE 512

int main() {
  char buf_in[BUF_SIZE];
  char buf_out[BUF_SIZE];

  uart_init();
  _delay_ms(100); // Initialization can take a bit of time

  // Separating output from previously buffered data
  sprintf(buf_out, "*** START ***");
  uart_write_string(buf_out);

  for(;;) {
    uart_read_string(buf_in);
    sprintf(buf_out, "*** %s ***", buf_in);
    uart_write_string(buf_out);
  }
}
