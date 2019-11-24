set_property SRC_FILE_INFO {cfile:d:/Xilinx/Vivado/project/final/final_002/final_002.srcs/sources_1/bd/design_1/ip/design_1_top_0_0/sources_1/ip/clk_wiz_0/clk_wiz_0.xdc rfile:../../../final_002.srcs/sources_1/bd/design_1/ip/design_1_top_0_0/sources_1/ip/clk_wiz_0/clk_wiz_0.xdc id:1 order:EARLY scoped_inst:inst/instance_name/inst} [current_design]
current_instance inst/instance_name/inst
set_property src_info {type:SCOPED_XDC file:1 line:57 export:INPUT save:INPUT read:READ} [current_design]
set_input_jitter [get_clocks -of_objects [get_ports clk_in1]] 0.08
