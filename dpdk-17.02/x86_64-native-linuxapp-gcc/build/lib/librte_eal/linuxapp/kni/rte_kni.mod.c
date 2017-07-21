#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x14522340, "module_layout" },
	{ 0x4f1939c7, "per_cpu__current_task" },
	{ 0xe23d7acb, "up_read" },
	{ 0xa43636ec, "net_assign_generic" },
	{ 0xfa2e111f, "slab_buffer_size" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0x950ffff2, "cpu_online_mask" },
	{ 0x79aa04a2, "get_random_bytes" },
	{ 0xd691cba2, "malloc_sizes" },
	{ 0xb54533f7, "usecs_to_jiffies" },
	{ 0x2bd43d13, "dynamic_debug_enabled2" },
	{ 0x105e2727, "__tracepoint_kmalloc" },
	{ 0x3758301, "mutex_unlock" },
	{ 0xcb27f3de, "__put_net" },
	{ 0x7d11c268, "jiffies" },
	{ 0x343a1a8, "__list_add" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xb4b0ee4e, "down_read" },
	{ 0x257e2d4c, "kthread_bind" },
	{ 0xffc7c184, "__init_waitqueue_head" },
	{ 0x41344088, "param_get_charp" },
	{ 0x3acac6d7, "misc_register" },
	{ 0xde0bdcff, "memset" },
	{ 0x42ae98a2, "netif_rx_ni" },
	{ 0xf12bb3b8, "dev_alloc_skb" },
	{ 0xf85ccdae, "kmem_cache_alloc_notrace" },
	{ 0x4bf79039, "__mutex_init" },
	{ 0xea147363, "printk" },
	{ 0xcf08c5b6, "kthread_stop" },
	{ 0x7bd0a577, "free_netdev" },
	{ 0x7ec9bfbc, "strncpy" },
	{ 0xdb3b96d5, "register_netdev" },
	{ 0xb4390f9a, "mcount" },
	{ 0x85abc85f, "strncmp" },
	{ 0x3229caeb, "skb_push" },
	{ 0xfee8a795, "mutex_lock" },
	{ 0x521445b, "list_del" },
	{ 0x1902adf, "netpoll_trap" },
	{ 0xd851af78, "up_write" },
	{ 0x45d55543, "down_write" },
	{ 0x9077e3a6, "unregister_pernet_gen_subsys" },
	{ 0xcc07af75, "strnlen" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0xafbc0d15, "alloc_netdev_mq" },
	{ 0xd62c833f, "schedule_timeout" },
	{ 0x9cb480f4, "dynamic_debug_enabled" },
	{ 0xb5a34391, "register_pernet_gen_subsys" },
	{ 0xd55704ee, "eth_type_trans" },
	{ 0x266c7c38, "wake_up_process" },
	{ 0x7f8bdd3a, "ether_setup" },
	{ 0x6ad065f4, "param_set_charp" },
	{ 0x642e54ac, "__wake_up" },
	{ 0xd2965f6f, "kthread_should_stop" },
	{ 0x9c55cec, "schedule_timeout_interruptible" },
	{ 0x37a0cba, "kfree" },
	{ 0xc185e3ce, "kthread_create" },
	{ 0x236c8c64, "memcpy" },
	{ 0x33d92f9a, "prepare_to_wait" },
	{ 0x38098f57, "dev_trans_start" },
	{ 0x9ccb2622, "finish_wait" },
	{ 0x73618816, "unregister_netdev" },
	{ 0xbc0d78f9, "__netif_schedule" },
	{ 0xde0cf25, "consume_skb" },
	{ 0x207b7e2c, "skb_put" },
	{ 0x3302b500, "copy_from_user" },
	{ 0x16c0b339, "misc_deregister" },
	{ 0xa2b8a2ba, "__init_rwsem" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "1F63E90EF5D555E68E0AE9A");

static const struct rheldata _rheldata __used
__attribute__((section(".rheldata"))) = {
	.rhel_major = 6,
	.rhel_minor = 2,
};
