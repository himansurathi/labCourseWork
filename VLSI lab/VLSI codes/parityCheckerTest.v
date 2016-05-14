`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   18:47:19 02/21/2016
// Design Name:   parityChecker
// Module Name:   F:/VLSI Lab/parityChecker/parityCheckerTest.v
// Project Name:  parityChecker
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: parityChecker
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module parityCheckerTest;

	// Inputs
	reg [3:0] data;
	reg parity;

	// Outputs
	wire parity_result;

	// Instantiate the Unit Under Test (UUT)
	parityChecker uut (
		.data(data), 
		.parity(parity), 
		.parity_result(parity_result)
	);

	initial begin
		// Initialize Inputs
	
		data = 4'b0101;
		parity = 0;
		#10;

		data = 4'b1101;
		parity = 0;
		#10;
        
		data = 4'b0101;
		parity = 1;
		#10;

		data = 4'b1101;
		parity = 1;
		#10;
		
		$stop;
	end
      
endmodule

