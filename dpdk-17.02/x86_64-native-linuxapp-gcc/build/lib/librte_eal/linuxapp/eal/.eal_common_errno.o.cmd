cmd_eal_common_errno.o = gcc -Wp,-MD,./.eal_common_errno.o.d.tmp  -m64 -pthread  -march=native -DRTE_MACHINE_CPUFLAG_SSE -DRTE_MACHINE_CPUFLAG_SSE2 -DRTE_MACHINE_CPUFLAG_SSE3 -DRTE_MACHINE_CPUFLAG_SSSE3 -DRTE_MACHINE_CPUFLAG_SSE4_1 -DRTE_MACHINE_CPUFLAG_SSE4_2 -DRTE_MACHINE_CPUFLAG_AES -DRTE_MACHINE_CPUFLAG_PCLMULQDQ -DRTE_MACHINE_CPUFLAG_AVX  -I/home/xfire/dpdk-17.02/x86_64-native-linuxapp-gcc/include -include /home/xfire/dpdk-17.02/x86_64-native-linuxapp-gcc/include/rte_config.h -I/home/xfire/dpdk-17.02/lib/librte_eal/linuxapp/eal/include -I/home/xfire/dpdk-17.02/lib/librte_eal/common -I/home/xfire/dpdk-17.02/lib/librte_eal/common/include -W -Wall -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wpointer-arith -Wcast-align -Wnested-externs -Wcast-qual -Wformat-nonliteral -Wformat-security -Wundef -Wwrite-strings -Wno-missing-field-initializers -Wno-uninitialized -O3    -o eal_common_errno.o -c /home/xfire/dpdk-17.02/lib/librte_eal/common/eal_common_errno.c 
