`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:50:00 02/27/2016
// Design Name:   binaryToGrayCode
// Module Name:   F:/VLSI Lab/binaryToGrayCode/binaryToGrayCodeTest.v
// Project Name:  binaryToGrayCode
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: binaryToGrayCode
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module binaryToGrayCodeTest;

	// Inputs
	reg [3:0] binary;

	// Outputs
	wire [3:0] gray;
	reg [4:0] i;
	// Instantiate the Unit Under Test (UUT)
	binaryToGrayCode uut (
		.binary(binary), 
		.gray(gray)
	);

	initial begin
		// Initialize Inputs
		binary = 4'b0000;
	end
      
	always @(binary)
		begin
		for(i=0;i<=15;i=i+1)
			begin
			{binary}=i;
			#10;
			end
		$stop;
		end
endmodule

