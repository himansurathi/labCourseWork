`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Comultiplierany: 
// Engineer: 
// 
// Create Date:    00:38:22 02/18/2016 
// Design Name: 
// Module Name:    boothMultiplier 
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
module boothMultiplier(
    input [3:0] multiplicand,
    input [3:0] multiplier,
    output [7:0] product,
    input clock,
    input reset
    );

	reg [3:0] A, Q, M;
	reg Q_1;
	reg [3:0] count;

	wire [3:0] sum, difference;

	always @(posedge clock)
	begin
		if (reset) begin
			A <= 4'b0;      
			M <= multiplicand;
			Q <= multiplier;
			Q_1 <= 1'b0;      
			count <= 3'b0;
		end
		else begin
			case ({Q[0], Q_1})
				2'b01 : {A, Q, Q_1} <= {sum[3], sum, Q};
				2'b10 : {A, Q, Q_1} <= {difference[3], difference, Q};
				default: {A, Q, Q_1} <= {A[3], A, Q};
			endcase
			count <= count + 1;
		end
	end

	alu adder (A, M, 0,sum);
	alu subtracter (A, ~M, 1,difference);
	assign product = {A, Q};

endmodule

module alu(a,b,cin,out);
	input [3:0] a;
	input [3:0] b;
	input cin;
	output [3:0] out;

	assign out = a + b + cin;

endmodule
