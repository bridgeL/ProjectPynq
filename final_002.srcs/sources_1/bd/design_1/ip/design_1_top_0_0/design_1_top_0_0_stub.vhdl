-- Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2019.1.3 (win64) Build 2644227 Wed Sep  4 09:45:24 MDT 2019
-- Date        : Fri Nov 22 13:28:21 2019
-- Host        : DESKTOP-404 running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub
--               D:/Xilinx/Vivado/project/final/final_002/final_002.srcs/sources_1/bd/design_1/ip/design_1_top_0_0/design_1_top_0_0_stub.vhdl
-- Design      : design_1_top_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg400-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity design_1_top_0_0 is
  Port ( 
    sys_clk : in STD_LOGIC;
    mic_data1 : in STD_LOGIC;
    mic_data2 : in STD_LOGIC;
    mic_data3 : in STD_LOGIC;
    mic_data4 : in STD_LOGIC;
    mic_data5 : in STD_LOGIC;
    mic_data6 : in STD_LOGIC;
    mic_clk : out STD_LOGIC;
    top_data1 : out STD_LOGIC_VECTOR ( 23 downto 0 );
    top_data2 : out STD_LOGIC_VECTOR ( 23 downto 0 );
    top_data3 : out STD_LOGIC_VECTOR ( 23 downto 0 );
    top_data4 : out STD_LOGIC_VECTOR ( 23 downto 0 );
    top_data5 : out STD_LOGIC_VECTOR ( 23 downto 0 );
    top_data6 : out STD_LOGIC_VECTOR ( 23 downto 0 )
  );

end design_1_top_0_0;

architecture stub of design_1_top_0_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "sys_clk,mic_data1,mic_data2,mic_data3,mic_data4,mic_data5,mic_data6,mic_clk,top_data1[23:0],top_data2[23:0],top_data3[23:0],top_data4[23:0],top_data5[23:0],top_data6[23:0]";
attribute X_CORE_INFO : string;
attribute X_CORE_INFO of stub : architecture is "top,Vivado 2019.1.3";
begin
end;
