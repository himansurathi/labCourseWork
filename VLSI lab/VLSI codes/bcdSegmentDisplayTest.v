`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   00:44:35 02/21/2016
// Design Name:   sevenSegmentDisplay
// Module Name:   F:/VLSI Lab/bcdSegmentDisplay/bcdSegmentDisplayTest.v
// Project Name:  bcdSegmentDisplay
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: sevenSegmentDisplay
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module bcdSegmentDisplayTest;

	// Inputs
	reg [3:0] bcd;

	// Outputs
	wire [5:0] display;
	
	reg [3:0] i;
	// Instantiate the Unit Under Test (UUT)
	sevenSegmentDisplay uut (
		.bcd(bcd), 
		.display(display)
	);

	initial begin
		bcd=4'b0000;
	end
	
	always @(bcd)
	begin
		for(i=0;i<=10;i=i+1)
		begin
			{bcd}=i;
			#10;
		end
		$stop;
	end
      
endmodule

