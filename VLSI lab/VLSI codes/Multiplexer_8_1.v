`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:12:22 01/26/2016 
// Design Name: 
// Module Name:    Multiplexer_8_1 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module Multiplexer_8_1(
    input [7:0] in0,in1,in2,in3,in4,in5,in6,in7,
    input  [2:0] sel,
    output reg [7:0] out
    );
   


	always @(in0,in1,in2,in3,in4,in5,in6,in7,sel)
	begin

		case(sel)
			3'd0:out=in0;
			3'd1:out=in1;
			3'd2:out=in2;
			3'd3:out=in3;
			3'd4:out=in4;
			3'd5:out=in5;
			3'd6:out=in6;
			3'd7:out=in7;
			default:out=7'bz; // indicates null
		endcase

	end
endmodule
