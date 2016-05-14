`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:44:58 01/26/2016 
// Design Name: 
// Module Name:    rippleCarryAdder 
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

module fullAdder(
		input a,
		input b,
		input cin,
		output s,
		output cout
	);
	assign s=a^b^cin;
	assign cout=(a&b)|(a&cin)|(b&cin);
endmodule


module rippleCarryAdder(
    input [3:0] a,
    input [3:0] b,
	 input carryin,
    output [3:0] sum,
    output carryout
    );
	fullAdder f0(a[0],b[0],carryin,sum[0],ripple0);
	fullAdder f1(a[1],b[1],ripple0,sum[1],ripple1);
	fullAdder f2(a[2],b[2],ripple1,sum[2],ripple2);
	fullAdder f3(a[3],b[3],ripple2,sum[3],carryout);
endmodule
