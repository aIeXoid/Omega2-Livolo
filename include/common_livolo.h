#include <stdint.h>
void delayMicroseconds (unsigned int howLong);

// Increase scheduling priority and algorithm to try to get 'real time' results.
void set_max_priority(void);

// Drop scheduling priority back to normal/default.
void set_default_priority(void);