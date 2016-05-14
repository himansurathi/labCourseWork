`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   22:33:12 02/28/2016
// Design Name:   sequencDetector
// Module Name:   F:/VLSI Lab/sequenceDetector/sequenceDetectorTest.v
// Project Name:  sequenceDetector
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: sequencDetector
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module sequenceDetectorTest;

	// Inputs
	reg in;
	reg reset;
	reg clock;

	// Outputs
	wire out;

	// Instantiate the Unit Under Test (UUT)
	sequencDetector uut (
		.in(in), 
		.reset(reset), 
		.clock(clock), 
		.out(out)
	);

	initial begin
		// Initialize Inputs
		in = 0;
		reset = 1;
		clock = 1;
		#10 reset=0;in=1;
		#10 in=1;
		#10 in=0;
		#10 in=0;
		#10 in=0;
		#10 in=1;
		#10 in=0;
		#10 in=0;
		#10 in=0;
		#10 in=1;
		#10;
		$stop;
	end
  always
	#5 clock=~clock; 
endmodule

