connect -url tcp:127.0.0.1:3121
source F:/VivadoProject/DataTransmission6/DataTransmission6.sdk/design_1_wrapper_hw_platform_1/ps7_init.tcl
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Xilinx TUL 1234-tulA"} -index 0
rst -system
after 3000
targets -set -filter {jtag_cable_name =~ "Xilinx TUL 1234-tulA" && level==0} -index 1
fpga -file F:/VivadoProject/DataTransmission6/DataTransmission6.sdk/design_1_wrapper_hw_platform_1/design_1_wrapper.bit
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Xilinx TUL 1234-tulA"} -index 0
loadhw -hw F:/VivadoProject/DataTransmission6/DataTransmission6.sdk/design_1_wrapper_hw_platform_1/system.hdf -mem-ranges [list {0x40000000 0xbfffffff}]
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Xilinx TUL 1234-tulA"} -index 0
ps7_init
ps7_post_config
configparams force-mem-access 0
bpadd -addr &main
