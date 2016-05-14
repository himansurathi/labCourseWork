`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:39:52 02/21/2016 
// Design Name: 
// Module Name:    parityChecker 
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
module parityChecker(
    input [3:0] data,
    input parity,
    output reg parity_result
    );
	 
	always @(data,parity)
		begin
		  if (^data == parity) 
			begin
			 parity_result = 0;
			end
		  else 
			 begin
				parity_result = 1;
			 end
		end
endmodule
