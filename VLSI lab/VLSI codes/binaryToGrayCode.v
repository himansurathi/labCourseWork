`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:47:13 02/27/2016 
// Design Name: 
// Module Name:    binaryToGrayCode 
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
module binaryToGrayCode(
    input [3:0] binary,
    output [3:0] gray
    );
	assign gray[3]=binary[3];
	assign gray[2]=binary[3]^binary[2];
	assign gray[1]=binary[2]^binary[1];
	assign gray[0]=binary[1]^binary[0];
	
endmodule
