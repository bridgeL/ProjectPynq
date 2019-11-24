`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/11/04 12:59:37
// Design Name: 
// Module Name: top
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


module top(
    input sys_clk,
    input mic_data1,
    input mic_data2,
    input mic_data3,
    input mic_data4,
    input mic_data5,
    input mic_data6,
    output mic_clk,
    output [23:0] top_data1,
    output [23:0] top_data2,
    output [23:0] top_data3,
    output [23:0] top_data4,
    output [23:0] top_data5,
    output [23:0] top_data6
//    output data_valid,
//    output data_clk,
//    input data_ready,
//    output data_last
//    output reset
    );
    
//    wire div_clk12;
//    wire div_clk12;
//    wire [15:0] r_cic_data1;
//    wire r_cic_valid;
    wire cic_clk12;
//    wire cic_ready;
//assign data_valid=1'b1;
//assign data_clk=cic_clk12;
//assign top_data1=r_cic_data1;
//assign reset=1'b1;
//assign data_last=r_cic_valid;

wire [23:0] r_cic_data1;
assign top_data1=r_cic_data1;

wire [23:0] r_cic_data2;
assign top_data2=r_cic_data2;

wire [23:0] r_cic_data3;
assign top_data3=r_cic_data3;

wire [23:0] r_cic_data4;
assign top_data4=r_cic_data4;

wire [23:0] r_cic_data5;
assign top_data5=r_cic_data5;

wire [23:0] r_cic_data6;
assign top_data6=r_cic_data6;

ReadMic ReadMic(
    .clk(cic_clk12),
    .mic_clk(mic_clk),
    .mic_data1(mic_data1),
    .mic_data2(mic_data2),
    .mic_data3(mic_data3),
    .mic_data4(mic_data4),
    .mic_data5(mic_data5),
    .mic_data6(mic_data6),
    .cic_data_out1(r_cic_data1),
    .cic_data_out2(r_cic_data2),
    .cic_data_out3(r_cic_data3),
    .cic_data_out4(r_cic_data4),
    .cic_data_out5(r_cic_data5),
    .cic_data_out6(r_cic_data6)
    );

clk_wiz_0 instance_name(
    .clk_out1(cic_clk12),     // output clk_out1
    .clk_in1(sys_clk)     // input clk_in1    
    );      
    
//axis_data_fifo_0 your_instance_name (
//      .s_axis_aresetn(1'd0),          // input wire s_axis_aresetn
//      .s_axis_aclk(sys_clk),                // input wire s_axis_aclk
//      .s_axis_tvalid(1'd1),            // input wire s_axis_tvalid
//      .s_axis_tready(),            // output wire s_axis_tready
//      .s_axis_tdata(r_cic_data),              // input wire [127 : 0] s_axis_tdata
//      .m_axis_tvalid(m_axis_tvalid),            // output wire m_axis_tvalid
//      .m_axis_tready(m_axis_tready),            // input wire m_axis_tready
//      .m_axis_tdata(m_axis_tdata),              // output wire [127 : 0] m_axis_tdata
//      .axis_data_count(axis_data_count),        // output wire [31 : 0] axis_data_count
//      .axis_wr_data_count(axis_wr_data_count),  // output wire [31 : 0] axis_wr_data_count
//      .axis_rd_data_count(axis_rd_data_count)  // output wire [31 : 0] axis_rd_data_count
//    );
endmodule