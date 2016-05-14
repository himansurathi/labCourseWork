`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 		NIT Durgapur
// Engineer: 		Himansu Rathi
// 
// Create Date:    22:24:10 02/06/2016 
// Design Name: 	
// Module Name:    ringCounter 
// Project Name: 	 ringCounter
// Target Devices: XC7A100T
// Tool versions: 
// Description: Ring Counter Implementation
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module ringCounter(
    input clock,
    input reset,
    output reg [2:0] sequence
    );


always @(posedge clock)
	begin
		if(reset)
			sequence<=3'b001;
		else
			begin
				sequence <= sequence << 1;
				sequence[0]<=sequence[2];
			end
	end
endmodule
