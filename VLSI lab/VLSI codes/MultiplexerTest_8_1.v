`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   14:50:56 01/26/2016
// Design Name:   Multiplexer_8_1
// Module Name:   F:/VLSI Lab/Multiplexer/MultiplexerTest_8_1.v
// Project Name:  Multiplexer
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Multiplexer_8_1
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module MultiplexerTest_8_1;

	// Inputs
	reg [7:0] in0,in1,in2,in3,in4,in5,in6,in7;
	reg [2:0] sel;
	wire [7:0] out;
	
	reg [3:0] i;
	// Instantiate the Unit Under Test (UUT)
	Multiplexer_8_1 uut (
		.in0(in0), 
		.in1(in1), 
		.in2(in2), 
		.in3(in3), 
		.in4(in4), 
		.in5(in5), 
		.in6(in6), 
		.in7(in7),
		.sel(sel),
		.out(out)
	);

	initial begin
		// Initialize Inputs
		in0 = 8'd128;
		in1 = 7'd64;
		in2 = 6'd32;
		in3 = 5'd16;
		in4 = 4'd8;
		in5 = 3'd4;
		in6 = 2'd2;
		in7 = 1'd1;
		sel = 3'd0;
	end
   
	always @(sel)
		begin
			for(i=0;i<8;i=i+1)
				begin
					{sel}=i;
					#10;
				end
			$stop;
		end
endmodule

