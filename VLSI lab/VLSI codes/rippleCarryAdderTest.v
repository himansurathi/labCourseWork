`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:29:48 01/26/2016
// Design Name:   rippleCarryAdder
// Module Name:   F:/VLSI Lab/Adder/rippleCarryAdderTest.v
// Project Name:  Adder
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: rippleCarryAdder
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module rippleCarryAdderTest;

	// Inputs
	reg [3:0] a;
	reg [3:0] b;
	reg carryin;
	
	// Outputs
	wire [3:0] sum;
	wire carryout;

	reg [10:0] i;

	// Instantiate the Unit Under Test (UUT)
	rippleCarryAdder uut (
		.a(a), 
		.b(b), 
		.carryin(carryin),
		.sum(sum), 
		.carryout(carryout)
	);

	initial begin
		a = 4'b0000;
		b = 4'b0000;
		carryin=1'b0;
	end
	
	always @(a,b)
		begin
			for(i=0;i<16*16*2;i=i+1)
			begin
				{carryin,a,b}=i;
				#10;
			end
			$stop;
		end
endmodule

