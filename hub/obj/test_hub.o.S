# 1 "hub/src/test_hub.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "hub/src/test_hub.c"
# 12 "hub/src/test_hub.c"
# 1 "hub/include/hub/test_hub.h" 1
# 25 "hub/include/hub/test_hub.h"
void test_cusb_poll(void);
# 13 "hub/src/test_hub.c" 2

# 1 "hub/include/hub/cusb.h" 1
# 52 "hub/include/hub/cusb.h"
void cusb_init(void);
void cusb_test_poll(void);
# 15 "hub/src/test_hub.c" 2
# 1 "hub/include/hub/bootloader.h" 1
# 16 "hub/src/test_hub.c" 2

void test_cusb_poll(void)
{
  cusb_init();
  cusb_test_poll();
}
