`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company:       NIT Durgapur
// Engineer:		Himansu Rathi
//
// Create Date:   22:40:00 02/06/2016
// Design Name:   ringCounter
// Module Name:   F:/VLSI Lab/ringCounter/ringCounterTest.v
// Project Name:  ringCounter
// Target Device:  XC7A100T
// Tool versions:  
// Description:    Ring Counter Testing And Simulations
//
// Verilog Test Fixture created by ISE for module: ringCounter
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module ringCounterTest;

	// Inputs
	reg clock;
	reg reset;

	// Outputs
	wire [2:0] sequence;

	// Instantiate the Unit Under Test (UUT)
	ringCounter uut (
		.clock(clock), 
		.reset(reset), 
		.sequence(sequence)
	);

	initial begin
		reset = 1'b1;
		#100 reset=1'b0;
	end
   
always
		begin
			clock=1'b1;
			#50 clock=1'b0;
			#50;
		end
endmodule

