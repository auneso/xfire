cmd_xfire = gcc -o xfire -m64 -pthread  -march=native -DRTE_MACHINE_CPUFLAG_SSE -DRTE_MACHINE_CPUFLAG_SSE2 -DRTE_MACHINE_CPUFLAG_SSE3 -DRTE_MACHINE_CPUFLAG_SSSE3 -DRTE_MACHINE_CPUFLAG_SSE4_1 -DRTE_MACHINE_CPUFLAG_SSE4_2 -DRTE_MACHINE_CPUFLAG_AES -DRTE_MACHINE_CPUFLAG_PCLMULQDQ -DRTE_MACHINE_CPUFLAG_AVX -DRTE_MACHINE_CPUFLAG_RDRAND -DRTE_MACHINE_CPUFLAG_FSGSBASE -DRTE_MACHINE_CPUFLAG_F16C -DRTE_MACHINE_CPUFLAG_AVX2  -I/home/xfire/build/include -I/home/xfire/dpdk-17.02/x86_64-native-linuxapp-gcc/include -include /home/xfire/dpdk-17.02/x86_64-native-linuxapp-gcc/include/rte_config.h -I/home/xfire/xlib -I/home/xfire/xhttpd -I/home/xfire/xfilter -I/home/xfire/xnet -I/home/xfire/jsonrpc -I/home/xfire/xjsonrpc  -I/home/xfire/include  /home/xfire/xnet/xfire.o -L/home/xfire/dpdk-17.02/x86_64-native-linuxapp-gcc/lib -Wl,-lrte_kni -Wl,-lrte_pipeline -Wl,-lrte_table -Wl,-lrte_port -Wl,-lrte_pdump -Wl,-lrte_distributor -Wl,-lrte_ip_frag -Wl,-lrte_meter -Wl,-lrte_sched -Wl,-lrte_lpm -Wl,--whole-archive -Wl,-lrte_acl -Wl,--no-whole-archive -Wl,-lrte_jobstats -Wl,-lrte_power -Wl,-lrte_timer -Wl,-lrte_efd -Wl,-lrte_cfgfile -Wl,--whole-archive -Wl,-lrte_hash -Wl,-lrte_vhost -Wl,-lrte_kvargs -Wl,-lrte_mbuf -Wl,-lrte_net -Wl,-lrte_ethdev -Wl,-lrte_cryptodev -Wl,-lrte_mempool -Wl,-lrte_ring -Wl,-lrte_eal -Wl,-lrte_cmdline -Wl,-lrte_reorder -Wl,-lrte_pmd_af_packet -Wl,-lrte_pmd_bnxt -Wl,-lrte_pmd_bond -Wl,-lrte_pmd_cxgbe -Wl,-lrte_pmd_e1000 -Wl,-lrte_pmd_ena -Wl,-lrte_pmd_enic -Wl,-lrte_pmd_fm10k -Wl,-lrte_pmd_i40e -Wl,-lrte_pmd_ixgbe -Wl,-lrte_pmd_nfp -Wl,-lm -Wl,-lrte_pmd_null -Wl,-lrte_pmd_qede -Wl,-lrte_pmd_ring -Wl,-lrte_pmd_sfc_efx -Wl,-lrte_pmd_tap -Wl,-lrte_pmd_virtio -Wl,-lrte_pmd_vhost -Wl,-lrte_pmd_vmxnet3_uio -Wl,-lrte_pmd_null_crypto -Wl,--no-whole-archive -Wl,-lrt -Wl,-ldl -Wl,-export-dynamic -Wl,-export-dynamic -L/home/xfire/build/lib -L/home/xfire/dpdk-17.02/x86_64-native-linuxapp-gcc/lib -L/home/xfire/xlib -L/home/xfire/xhttpd -L/home/xfire/xfilter -L/home/xfire/xnet -L/home/xfire/jsonrpc -L/home/xfire/xjsonrpc -L/home/xfire/lib -Wl,-lxnet -Wl,-lxfilter -Wl,-lxhttpd -Wl,-lxlib -Wl,-lxjsonrpc -Wl,-ljrpc -Wl,-lpthread -Wl,-lz -Wl,-lm -Wl,-lrt -Wl,-lnl -Wl,-ldl -Wl,--as-needed -Wl,-Map=xfire.map -Wl,--cref 
