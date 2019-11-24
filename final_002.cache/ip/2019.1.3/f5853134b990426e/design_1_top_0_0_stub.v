// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2019.1.3 (win64) Build 2644227 Wed Sep  4 09:45:24 MDT 2019
// Date        : Fri Nov 22 13:28:16 2019
// Host        : DESKTOP-404 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ design_1_top_0_0_stub.v
// Design      : design_1_top_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg400-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "top,Vivado 2019.1.3" *)
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix(sys_clk, mic_data1, mic_data2, mic_data3, 
  mic_data4, mic_data5, mic_data6, mic_clk, top_data1, top_data2, top_data3, top_data4, top_data5, 
  top_data6)
/* synthesis syn_black_box black_box_pad_pin="sys_clk,mic_data1,mic_data2,mic_data3,mic_data4,mic_data5,mic_data6,mic_clk,top_data1[23:0],top_data2[23:0],top_data3[23:0],top_data4[23:0],top_data5[23:0],top_data6[23:0]" */;
  input sys_clk;
  input mic_data1;
  input mic_data2;
  input mic_data3;
  input mic_data4;
  input mic_data5;
  input mic_data6;
  output mic_clk;
  output [23:0]top_data1;
  output [23:0]top_data2;
  output [23:0]top_data3;
  output [23:0]top_data4;
  output [23:0]top_data5;
  output [23:0]top_data6;
endmodule
