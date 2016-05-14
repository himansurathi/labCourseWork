`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:21:18 02/07/2016 
// Design Name: 
// Module Name:    bcdAdder 
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

module bcdAdder(
    input [3:0] a,
    input [3:0] b,
    input cin,
    output reg [3:0] sum,
    output reg cout
    );
	 
	reg [4:0] z;
	
	always @(a,b,cin)
	begin
		z=a+b+cin;
		if(z>9)
			{cout,sum}=z+6;
		else
			{cout,sum}=z;
	end
endmodule

