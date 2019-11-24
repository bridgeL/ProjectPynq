set_property PACKAGE_PIN H16 [get_ports sys_clk_0]
set_property IOSTANDARD LVCMOS33 [get_ports sys_clk_0]

#set_property PACKAGE_PIN U8 [get_ports mic_data_0]
#set_property IOSTANDARD LVCMOS33 [get_ports mic_data_0]

set_property PACKAGE_PIN W19 [get_ports mic_clk_0]
set_property IOSTANDARD LVCMOS33 [get_ports mic_clk_0]

set_property -dict { PACKAGE_PIN Y18    IOSTANDARD LVCMOS33 } [get_ports { mic_data6_0 }]; 
set_property -dict { PACKAGE_PIN C20    IOSTANDARD LVCMOS33 } [get_ports { mic_data5_0 }]; 
set_property -dict { PACKAGE_PIN U7     IOSTANDARD LVCMOS33 } [get_ports { mic_data4_0 }]; 
set_property -dict { PACKAGE_PIN Y6     IOSTANDARD LVCMOS33 } [get_ports { mic_data3_0 }]; 
set_property -dict { PACKAGE_PIN W6     IOSTANDARD LVCMOS33 } [get_ports { mic_data2_0 }]; 
set_property -dict { PACKAGE_PIN Y7     IOSTANDARD LVCMOS33 } [get_ports { mic_data1_0 }]; 

