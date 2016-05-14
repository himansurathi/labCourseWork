`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:41:59 02/07/2016
// Design Name:   bcdAdder
// Module Name:   F:/VLSI Lab/bcdAdder/bcdAdderTest.v
// Project Name:  bcdAdder
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: bcdAdder
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module bcdAdderTest;

	// Inputs
	reg [3:0] a;
	reg [3:0] b;
	reg cin;

	// Outputs
	wire [3:0] sum;
	wire cout;
	reg [3:0] i,j;
	
	// Instantiate the Unit Under Test (UUT)
	bcdAdder uut (
		.a(a), 
		.b(b), 
		.cin(cin), 
		.sum(sum), 
		.cout(cout)
	);

	initial begin
		a = 4'b0000;
		b = 4'b0000;
		cin=1'b0;
	end
	
	always @(a,b)
		begin
			for(i=0;i<10;i=i+1)
			begin
				{a}=i;
				for(j=0;j<10;j=j+1)
				begin
					{b}=j;
					#10;
				end
			end
			$stop;
		end
endmodule

