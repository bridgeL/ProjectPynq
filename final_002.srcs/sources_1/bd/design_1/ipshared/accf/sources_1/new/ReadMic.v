`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/11/04 12:59:37
// Design Name: 
// Module Name: ReadMic
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module ReadMic(
    input clk,
//    (* mark_debug="true" *)output reg mic_clk,
//    (* mark_debug="true" *)input mic_data,
//    (* mark_debug="true" *)output [15:0] cic_data_out,
//    (* mark_debug="true" *)output cic_data_valid
    output reg mic_clk,
    input mic_data1,
    input mic_data2,
    input mic_data3,
    input mic_data4,
    input mic_data5,
    input mic_data6,
    output [23:0] cic_data_out1,
    output [23:0] cic_data_out2,
    output [23:0] cic_data_out3,
    output [23:0] cic_data_out4,
    output [23:0] cic_data_out5,
    output [23:0] cic_data_out6
    );
    
reg [3:0] timer_cnt;          //for mic_clk
always@(posedge clk)
begin
    if(timer_cnt>=4'd4)
    begin
        timer_cnt<=4'd0;
        mic_clk<=~mic_clk;
    end
    else
    begin
        timer_cnt<=timer_cnt+5'd1;
    end
end

wire [7:0] cic_data_in1;
assign cic_data_in1[0]=mic_data1;
assign cic_data_in1[7:1]=7'b0;

wire [7:0] cic_data_in2;
assign cic_data_in2[0]=mic_data2;
assign cic_data_in2[7:1]=7'b0;

wire [7:0] cic_data_in3;
assign cic_data_in3[0]=mic_data3;
assign cic_data_in3[7:1]=7'b0;

wire [7:0] cic_data_in4;
assign cic_data_in4[0]=mic_data4;
assign cic_data_in4[7:1]=7'b0;

wire [7:0] cic_data_in5;
assign cic_data_in5[0]=mic_data5;
assign cic_data_in5[7:1]=7'b0;

wire [7:0] cic_data_in6;
assign cic_data_in6[0]=mic_data6;
assign cic_data_in6[7:1]=7'b0;

cic_compiler_0 your_instance_name1 (
  .aclk(clk),                              // input wire aclk
  .s_axis_data_tdata(cic_data_in1),    // input wire [7 : 0] s_axis_data_tdata
  .s_axis_data_tvalid(1'b1),  // input wire s_axis_data_tvalid
  .s_axis_data_tready(),  // output wire s_axis_data_tready
  .m_axis_data_tdata(cic_data_out1),    // output wire [15 : 0] m_axis_data_tdata
  .m_axis_data_tvalid()  // output wire m_axis_data_tvalid
);

cic_compiler_0 your_instance_name2 (
  .aclk(clk),                              // input wire aclk
  .s_axis_data_tdata(cic_data_in2),    // input wire [7 : 0] s_axis_data_tdata
  .s_axis_data_tvalid(1'b1),  // input wire s_axis_data_tvalid
  .s_axis_data_tready(),  // output wire s_axis_data_tready
  .m_axis_data_tdata(cic_data_out2),    // output wire [15 : 0] m_axis_data_tdata
  .m_axis_data_tvalid()  // output wire m_axis_data_tvalid
);

cic_compiler_0 your_instance_name3 (
  .aclk(clk),                              // input wire aclk
  .s_axis_data_tdata(cic_data_in3),    // input wire [7 : 0] s_axis_data_tdata
  .s_axis_data_tvalid(1'b1),  // input wire s_axis_data_tvalid
  .s_axis_data_tready(),  // output wire s_axis_data_tready
  .m_axis_data_tdata(cic_data_out3),    // output wire [15 : 0] m_axis_data_tdata
  .m_axis_data_tvalid()  // output wire m_axis_data_tvalid
);

cic_compiler_0 your_instance_name4 (
  .aclk(clk),                              // input wire aclk
  .s_axis_data_tdata(cic_data_in4),    // input wire [7 : 0] s_axis_data_tdata
  .s_axis_data_tvalid(1'b1),  // input wire s_axis_data_tvalid
  .s_axis_data_tready(),  // output wire s_axis_data_tready
  .m_axis_data_tdata(cic_data_out4),    // output wire [15 : 0] m_axis_data_tdata
  .m_axis_data_tvalid()  // output wire m_axis_data_tvalid
);

cic_compiler_0 your_instance_name5 (
  .aclk(clk),                              // input wire aclk
  .s_axis_data_tdata(cic_data_in5),    // input wire [7 : 0] s_axis_data_tdata
  .s_axis_data_tvalid(1'b1),  // input wire s_axis_data_tvalid
  .s_axis_data_tready(),  // output wire s_axis_data_tready
  .m_axis_data_tdata(cic_data_out5),    // output wire [15 : 0] m_axis_data_tdata
  .m_axis_data_tvalid()  // output wire m_axis_data_tvalid
);

cic_compiler_0 your_instance_name6 (
  .aclk(clk),                              // input wire aclk
  .s_axis_data_tdata(cic_data_in6),    // input wire [7 : 0] s_axis_data_tdata
  .s_axis_data_tvalid(1'b1),  // input wire s_axis_data_tvalid
  .s_axis_data_tready(),  // output wire s_axis_data_tready
  .m_axis_data_tdata(cic_data_out6),    // output wire [15 : 0] m_axis_data_tdata
  .m_axis_data_tvalid()  // output wire m_axis_data_tvalid
);

//ila_0 your_instance_name1(
//	.clk(clk), // input wire clk
//	.probe0(mic_clk), // input wire [0:0]  probe0  
//	.probe1(mic_data), // input wire [0:0]  probe1 
//	.probe2(cic_data_valid), // input wire [0:0]  probe2 
//	.probe3(cic_data_out) // input wire [15:0]  probe3
//);
endmodule