// (c) Copyright 1995-2019 Xilinx, Inc. All rights reserved.
// 
// This file contains confidential and proprietary information
// of Xilinx, Inc. and is protected under U.S. and
// international copyright and other intellectual property
// laws.
// 
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// Xilinx, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) Xilinx shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or Xilinx had been advised of the
// possibility of the same.
// 
// CRITICAL APPLICATIONS
// Xilinx products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of Xilinx products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
// 
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
// 
// DO NOT MODIFY THIS FILE.


// IP VLNV: xilinx.com:user:top:1.0
// IP Revision: 21

`timescale 1ns/1ps

(* IP_DEFINITION_SOURCE = "package_project" *)
(* DowngradeIPIdentifiedWarnings = "yes" *)
module design_1_top_0_0 (
  sys_clk,
  mic_data1,
  mic_data2,
  mic_data3,
  mic_data4,
  mic_data5,
  mic_data6,
  mic_clk,
  top_data1,
  top_data2,
  top_data3,
  top_data4,
  top_data5,
  top_data6
);

(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME sys_clk, ASSOCIATED_BUSIF cic_data, FREQ_HZ 100000000, PHASE 0.000, CLK_DOMAIN design_1_sys_clk_0, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 sys_clk CLK" *)
input wire sys_clk;
input wire mic_data1;
input wire mic_data2;
input wire mic_data3;
input wire mic_data4;
input wire mic_data5;
input wire mic_data6;
output wire mic_clk;
output wire [23 : 0] top_data1;
output wire [23 : 0] top_data2;
output wire [23 : 0] top_data3;
output wire [23 : 0] top_data4;
output wire [23 : 0] top_data5;
output wire [23 : 0] top_data6;

  top inst (
    .sys_clk(sys_clk),
    .mic_data1(mic_data1),
    .mic_data2(mic_data2),
    .mic_data3(mic_data3),
    .mic_data4(mic_data4),
    .mic_data5(mic_data5),
    .mic_data6(mic_data6),
    .mic_clk(mic_clk),
    .top_data1(top_data1),
    .top_data2(top_data2),
    .top_data3(top_data3),
    .top_data4(top_data4),
    .top_data5(top_data5),
    .top_data6(top_data6)
  );
endmodule
