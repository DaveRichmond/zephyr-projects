#include <zephyr.h>
#include <sys/printk.h>
#include <shell/shell.h>
#include <shell/shell_uart.h>
#include <version.h>
#include <logging/log.h>
#include <stdlib.h>

LOG_MODULE_REGISTER(app);

static int cmd_demo_ping(const struct shell *shell, size_t argc, char **argv){
	ARG_UNUSED(argc);
	ARG_UNUSED(argv);

	shell_print(shell, "pong");

	return 0;
}

static int cmd_version(const struct shell *shell, size_t argc, char **argv){
	ARG_UNUSED(argc);
	ARG_UNUSED(argv);

	shell_print(shell, "Zephyr version %s", KERNEL_VERSION_STRING);

	return 0;
}

SHELL_STATIC_SUBCMD_SET_CREATE(sub_demo,
	SHELL_CMD(ping, NULL, "Ping command.", cmd_demo_ping),
	SHELL_SUBCMD_SET_END /* Array terminated */
);
SHELL_CMD_REGISTER(demo, &sub_demo, "Demo commands", NULL);
SHELL_CMD_ARG_REGISTER(version, NULL, "Show kernel version", cmd_version, 1, 0);

void main(void){
	// do nothing
}
