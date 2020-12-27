# 1 "hub/src/hub_test.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "hub/src/hub_test.c"
# 15 "hub/src/hub_test.c"
# 1 "hub/include/hub/hub_test.h" 1
# 52 "hub/include/hub/hub_test.h"
void test_cusb_poll(void);
# 16 "hub/src/hub_test.c" 2

# 1 "hub/include/hub/cusb.h" 1
# 52 "hub/include/hub/cusb.h"
void cusb_init(void);
void cusb_test_poll(void);
# 18 "hub/src/hub_test.c" 2
# 1 "hub/include/hub/hub_bootloader.h" 1
# 19 "hub/src/hub_test.c" 2
# 50 "hub/src/hub_test.c"
void test_cusb_poll(void)
{
  cusb_init();
  cusb_test_poll();
}
